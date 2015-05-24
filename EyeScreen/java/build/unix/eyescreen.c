/*
 * Copyright � 2004 Sun Microsystems, Inc. All rights reserved. Use is
 * subject to license terms.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

/*
 * Bridges xscreensaver (Linux or Solaris) to Java
 * Define either -DPLATFORM_SunOS or -DPLATFORM_Linux as a parameter to gcc
 * 
 * Author: Mark Roth <mark.roth@sun.com>
 * Contributor: Bino George <bino.george@sun.com>
 */

#include <jni.h>
#include <dlfcn.h>
#include "screenhack.h"

#define PATH_SEPARATOR ':' /* UNIX */

#define SCREENSAVER_BASE_CLASS "org/jdesktop/jdic/screensaver/ScreensaverBase"
#define SCREENSAVER_CONTEXT_CLASS "org/jdesktop/jdic/screensaver/ScreensaverContext"

#ifdef PLATFORM_Linux
#define EMBEDDED_FRAME_CLASS "sun/awt/X11/XEmbeddedFrame"
#elif PLATFORM_SunOS
#define EMBEDDED_FRAME_CLASS "sun/awt/motif/MEmbeddedFrame"
#endif

/** Copyright notice to appear in generated binaries */
char *copyright = 
"Copyright (c) 2004 Sun Microsystems, Inc., 4150 Network Circle, Santa \n"
"Clara, California 95054, U.S.A. All rights reserved.  Use is subject \n"
"to license terms specified in the file COPYING included in this \n"
"distribution. Sun, Sun Microsystems and the Sun logo are \n"
"trademarks or registered trademarks of Sun Microsystems, Inc. in the \n"
"U.S. and other countries. \n"
"\n"
"This product is covered and controlled by U.S. Export Control laws and \n" 
"may be subject to the export or import laws in other countries. \n"
"Nuclear, missile, chemical biological weapons or nuclear maritime end \n"
"uses or end users, whether direct or indirect, are strictly \n"
"prohibited.  Export or reexport to countries subject to U.S. embargo \n"
"or to entities identified on U.S. export exclusion lists, including, \n"
"but not limited to, the denied persons and specially designated \n"
"nationals lists is strictly prohibited.";

/***************************************************************************/
/* Begin substituted parameters                                            */
/***************************************************************************/

char *progclass = "eyescreen";
char *jarName;
char *className;

XrmOptionDescRec options [] = {
    { "-jdkhome", ".jdkhome", XrmoptionSepArg, 0 },

    { "-jar", ".jar", XrmoptionSepArg, 0 },
    { "-class", ".class", XrmoptionSepArg, 0 },
    { "-delay", ".delay", XrmoptionSepArg, 0 },
    { 0, 0, 0, 0 }
};

char *defaults [] = {
    ".background:	black",
    ".foreground:	white",
    "*class:            de.freegroup.screensave.eyescreen.EyeScreen",
    "*jar:              eyescreen.jar",
    "*delay:            16666",
    0
};

/***************************************************************************/
/* End substituted parameters                                              */
/***************************************************************************/

JavaVM *jvm = 0;
JNIEnv *env = 0;

/* See comment later about dlopen */
/*
 * Pointers to the needed JNI invocation API, initialized by LoadJavaVM.
 * Borrowed from src.zip invoker/java.h
 */
/*
char *jdkHome = NULL;
#define ARCH         "i386"
#define MAXPATHLEN   1024
#define JVM_DLL      "libjvm.so"
typedef jint (JNICALL *CreateJavaVM_t)(JavaVM **pvm, void **env, void *args);
typedef struct {
    CreateJavaVM_t CreateJavaVM;
} InvocationFunctions;
InvocationFunctions ifn;
*/


GC gc;
int delay;
unsigned long fg, bg;
int npixels;
int prev_width = 0, prev_height = 0;
char *realClassName;

void
init_saverbeans(Display *dpy, Window window) {
    int i;
    XGCValues gcv;
    XWindowAttributes xgwa;
    Colormap cmap;
    XGetWindowAttributes(dpy, window, &xgwa);
    cmap = xgwa.colormap;
    npixels = 0;
    gcv.foreground= fg= get_pixel_resource("foreground", "Foreground", dpy, cmap);
    gcv.background= bg= get_pixel_resource("background", "Background", dpy, cmap);
    gcv.fill_style= FillOpaqueStippled;
    gc = XCreateGC(dpy, window, GCForeground|GCBackground|GCFillStyle, &gcv);
    
    delay = get_integer_resource("delay", "Integer");
    if (delay < 0) delay = 0;
    jarName = get_string_resource("jar", "String");
    className = get_string_resource("class", "String");
    /*
     * jdkHome = get_string_resource( "jdkHome", "String" );
     */
    
    /* We need class in the form com/acme/Foo, not com.acme.Foo */
    realClassName = malloc( strlen( className ) );
    strcpy( realClassName, className );
    for( i = 0; i < strlen(realClassName); i++ ) {
        if( realClassName[i] == '.' ) realClassName[i] = '/';
    }
    
    i = 0;
}

/* 
 * Create the Graphics object.  The current strategy for this is to 
 * create an EmbeddedFrame that is a child of this native window
 * and snag the Graphics object from it.  The screen saver will be
 * rendering to an embedded frame but that shouldn't matter.
 *
 * Note: This isn't 100% portable since it requires the Sun VM.  If this
 * is an issue, an alternative implementation of saverbeans can be provided
 * without changing the Screensavers themselves (since how we get the
 * Graphics object is an implementation detail of saverbeans.c).  I've been told
 * that realistically VMs other than Sun's VM include the sun.awt packages
 * anyway.
 */
int create_frame( Display *dpy, Window window, 
    jclass *class_embedded_frame_result, jobject *frame_result ) 
{
    jmethodID constructor;
    jobject frame = 0;
    jclass cls;
    int valid = 1;
    XWindowAttributes xgwa;
    
    XGetWindowAttributes( dpy, window, &xgwa );
    
    /* Create an embedded frame that is a child of this window */
    cls = (*env)->FindClass( env, EMBEDDED_FRAME_CLASS );
    if( cls == NULL ) {
        fprintf( stderr, "Could not find class %s\n", EMBEDDED_FRAME_CLASS );
        valid = 0;
    }

    /* Find constructor */
    if( valid ) {
        *class_embedded_frame_result = cls;
        constructor = (*env)->GetMethodID( env, cls, "<init>", "(J)V" );
        if( constructor == NULL ) {
            fprintf( stderr, "Could not find constructor for %s\n",
                EMBEDDED_FRAME_CLASS );
            valid = 0;
        }
    }
    
    /* Create embedded frame */
    if( valid ) {
        frame = (*env)->NewObject( env, cls, constructor, (jlong)window );
        *frame_result = frame;
        if( frame == NULL ) {
            fprintf( stderr, "Could not create %s\n", EMBEDDED_FRAME_CLASS );
            valid = 0;
        }
    }

    return valid;
}

void update_context( jclass context_class, jobject context,
    jclass class_embedded_frame, jobject frame, Display *dpy, Window window ) 
{
    int valid = 1;
    jmethodID mid;
    XWindowAttributes xgwa;
    
    XGetWindowAttributes( dpy, window, &xgwa );
    
    /* If either the width or height changed, change the bounds of the
     * embedded frame as well. */
    if( (prev_width != xgwa.width) || (prev_height != xgwa.height) ) {
        /* Set bounds to the bounds of the enclosing window */
        if( valid ) {
            mid = (*env)->GetMethodID( env, class_embedded_frame, 
                "setBounds", "(IIII)V" );
            if( mid == NULL ) {
                fprintf( stderr, "Could not find setBounds()\n" );
                valid = 0;
            }
            else {
                (*env)->CallVoidMethod( env, frame, mid, 0, 0, 
                    xgwa.width, xgwa.height );
            }
        }
        
        prev_width = xgwa.width;
        prev_height = xgwa.height;
    }
}
    
/* Create the information in the ScreensaverContext object */
int create_context( jclass *class_context_result, 
    jobject *context_result, jclass class_embedded_frame,
    jobject frame, Display *dpy, Window window ) 
{
    int valid = 1;
    jclass class_context;
    jmethodID mid;
    jmethodID constructor;
    jobject context = 0;
    char *key, *value;
    jstring keyString, valueString;
    XrmOptionDescRec *opt = options;
    XWindowAttributes xgwa;
    XGetWindowAttributes( dpy, window, &xgwa );
    
    /* Find ScreensaverContext class: */
    class_context = (*env)->FindClass( env, SCREENSAVER_CONTEXT_CLASS );
    if( class_context == NULL ) {
        fprintf( stderr, "Could not find class %s\n", 
            SCREENSAVER_CONTEXT_CLASS );
        valid = 0;
    }
    
    /* Find constructor */
    if( valid ) {
        *class_context_result = class_context;
        constructor = (*env)->GetMethodID( env, class_context, 
            "<init>", "()V" );
        if( constructor == NULL ) {
            fprintf( stderr, "Could not find constructor for %s\n",
                SCREENSAVER_CONTEXT_CLASS );
            valid = 0;
        }
    }

    /* Create instance */
    if( valid ) {
        context = (*env)->NewObject( env, class_context, constructor );
        if( context == NULL ) {
            fprintf( stderr, "Could not construct ScreensaverContext\n" );
            valid = 0;
        }
        else {
            *context_result = context;
        }
    }
    
    /* Create an instance of the ScreensaverContext */
    if( valid ) {
        if( context == NULL ) {
            fprintf( stderr, "Error creating screensaver context\n" );
            valid = 0;
        }
    }

    /* Find and call setComponent() */
    if( valid ) {
        mid = (*env)->GetMethodID( env, class_context, "setComponent", 
            "(Ljava/awt/Component;)V" );
        if( mid == NULL ) {
            fprintf( stderr, 
                "Could not find ScreensaverContext.setComponent()\n");
            valid = 0;
        }
        else {
            (*env)->CallVoidMethod( env, context, mid, frame );
        }
    }

    /* Populate context object with option values */
    if( valid ) {
        mid = (*env)->GetMethodID( env, class_context, "option",
            "(Ljava/lang/String;Ljava/lang/String;)V" );
        if( mid == NULL ) {
            fprintf( stderr, "Could not find ScreensaverContext.option()\n" );
            valid = 0;
        }
        else {
            while( opt->option != 0 ) {
                /* Get value of option, without the '-' */
                key = ((opt->option)+1);
                keyString = (*env)->NewStringUTF( env, key );
                if(opt->argKind == XrmoptionIsArg) {
                    value = get_string_resource( key, "String" );
                    if( value != 0 ) {
                        valueString = (*env)->NewStringUTF( env, "" );
                        (*env)->CallVoidMethod( env, context, mid, keyString, 
                            valueString );
                    }
                }
                else {
                    value = get_string_resource( key, "String" );
                    if( value != 0 ) {
                        valueString = (*env)->NewStringUTF( env, value );
                        (*env)->CallVoidMethod( env, context, mid, keyString, 
                            valueString );
                    }
                }
                opt++;
            }
        }
    }
    
    return valid;
}

/* ------------------------------------------------------------------------- */
/* 
 * In the current JDK, we cannot dynamically load the VM via dlopen()
 * so there is no way to run the JDK without having LD_LIBRARY_PATH set.
 * In a future version we can eliminate the wrapper shell script by
 * using dlopen() instead of setting LD_LIBRARY_PATH.  I'm preserving 
 * this code in case we are later able to do this.
 */
/**
 * Find path to JVM_DLL from the given java home directory.
 * Returns JNI_FALSE if the file is not there.
 */
/*
jboolean GetJREPathFromBase( char *path, jint pathsize, char *base ) {
    // Search lib/i386/
    sprintf( path, "%s/lib/" ARCH "/" JVM_DLL, base );
    if( access( path, F_OK ) == 0 ) {
        return JNI_TRUE;
    }

    // Search lib/jre/i386/
    sprintf( path, "%s/jre/lib/" ARCH "/" JVM_DLL, base );
    if( access( path, F_OK ) == 0 ) {
        return JNI_TRUE;
    }

    // Search lib/i386/client
    sprintf( path, "%s/lib/" ARCH "/client/" JVM_DLL, base );
    if( access( path, F_OK ) == 0 ) {
        return JNI_TRUE;
    }

    // Search lib/jre/i386/client
    sprintf( path, "%s/jre/lib/" ARCH "/client/" JVM_DLL, base );
    if( access( path, F_OK ) == 0 ) {
        return JNI_TRUE;
    }

    return JNI_FALSE;
}
*/
/*
 * Find path to JRE based on JAVA_HOME environment variable
 * XXX - is there a more standard way to do this?
 */
/*
jboolean GetJREPath( char *path, jint pathsize ) {
    jboolean result = JNI_FALSE;

    char *javaHome;
    if( (javaHome = getenv( "JAVA_HOME" )) != NULL ) {
        result = GetJREPathFromBase( path, pathsize, javaHome );
    }

    if( !result && (jdkHome != NULL) ) {
        result = GetJREPathFromBase( path, pathsize, jdkHome );
    }

    return result;
}
*/
/*
jboolean LoadJavaVM( const char *jvmpath ) {
    void *libjvm;
    int valid = 1;
    jint res;

    // libjvm = dlopen( jvmpath, RTLD_NOW + RTLD_GLOBAL );
    libjvm = dlopen( jvmpath, RTLD_LAZY );
    if( libjvm == NULL ) {
        fprintf( stderr, "Could not load %s", jvmpath );
        valid = 0;
    }

    if( valid ) {
        ifn.CreateJavaVM = (CreateJavaVM_t)dlsym( libjvm, "JNI_CreateJavaVM" );
        if( ifn.CreateJavaVM == 0 ) {
            fprintf( stderr, "Failed %s, because %s\n", jvmpath, dlerror() );
            valid = 0;
        }
    }

    if( valid ) {
        JavaVMInitArgs vm_args;
        JavaVMOption options[1];
        options[0].optionString = malloc( 320 + strlen(jarName) );
        sprintf( options[0].optionString, "-Djava.class.path=%s%c%s", jarName,
            PATH_SEPARATOR, "saverbeans-api.jar" );
        vm_args.version = 0x00010002;
        vm_args.options = options;
        vm_args.nOptions = 1;
        vm_args.ignoreUnrecognized = JNI_TRUE;
        // Create the Java VM
        res = ifn.CreateJavaVM(&jvm, (void**)&env, &vm_args);
        if (res < 0) {
            fprintf(stderr, "Can't create Java VM\n");
            valid = 0;
        }
    }

    return valid;
}
*/
/* ------------------------------------------------------------------------- */

jboolean InitializeJavaVM(void) {
    int valid = 1;
    jint res;
    JNIEnv **penv = &env;

    JavaVMInitArgs vm_args;
    JavaVMOption options[1];
    options[0].optionString = malloc( 320 + strlen(jarName) );
    sprintf( options[0].optionString, "-Djava.class.path=%s%c%s", jarName,
        PATH_SEPARATOR, "saverbeans-api.jar" );
    vm_args.version = 0x00010002;
    vm_args.options = options;
    vm_args.nOptions = 1;
    vm_args.ignoreUnrecognized = JNI_TRUE;
    /* Create the Java VM */
    res = JNI_CreateJavaVM(&jvm, (void **)penv, &vm_args);
    if (res < 0) {
        fprintf(stderr, "Can't create Java VM\n");
        valid = 0;
    }

    return valid;
}


/* Main entry point called from screenhack.c */
void screenhack(Display *dpy, Window window) {
    jclass class_screensaver;
    jclass class_context;
    jclass class_embedded_frame;
    jclass cls;
    jmethodID constructor;
    jobject saver = 0; /* the screen saver instance */
    jobject context;
    jobject frame;
    jmethodID mid;
    jmethodID render_frame_mid = 0;
    int valid = 1;
    int tick = 0;
    /* char jrepath[MAXPATHLEN]; */
    
    init_saverbeans(dpy, window);

    /* Commented out (see dlopen above) */
    /*
    if( !GetJREPath( jrepath, sizeof( jrepath ) ) ) {
        fprintf( stderr, "Could not find Java Runtime.  Please set "
            "JAVA_HOME or specify -jdkHome parameter.\n" );
        valid = 0;
    }
    */

    if( valid ) {
        /*valid = LoadJavaVM( jrepath );*/
        valid = InitializeJavaVM();
    }
    
    /* Find the class */
    if( valid ) {
        cls = (*env)->FindClass(env, realClassName);
        if (cls == NULL) {
            fprintf( stderr, "Can't find class %s\n", realClassName );
            valid = 0;
        }
    }
    
    /* Find the org.jdesktop.jdic.screensaver.Screensaver base class */
    if( valid ) {
        class_screensaver = (*env)->FindClass( env, SCREENSAVER_BASE_CLASS );
        if( class_screensaver == NULL ) {
            fprintf( stderr, "Can't find base class %s\n", 
                SCREENSAVER_BASE_CLASS );
            valid = 0;
        }
    }
    
    /* Make sure the specified class is a subclass of SCREENSAVER_BASE_CLASS */
    if( valid ) {
        if( !((*env)->IsAssignableFrom( env, cls, class_screensaver ) ) ) {
            fprintf( stderr, "Error: Class %s is not a subclass of %s\n",
                realClassName, SCREENSAVER_BASE_CLASS );
            valid = 0;
        }
    }
    
    /* Find the no-args constructor */
    if( valid ) {
        constructor = (*env)->GetMethodID( env, cls, "<init>", "()V" );
        if( constructor == NULL ) {
            fprintf( stderr, 
                "Can't find no-args constructor for screensaver\n" );
            valid = 0;
        }
    }
    
    /* Create an instance of the screensaver */
    if( valid ) {
        saver = (*env)->NewObject( env, cls, constructor );
        if( saver == NULL ) {
            fprintf( stderr, "Error creating instance of %s\n", 
                realClassName );
            valid = 0;
        }
    }
    
    /* Create embedded frame */
    if( valid ) {
        valid = create_frame( dpy, window, 
            &class_embedded_frame, &frame );
    }

    
    /* Update context object */
    if( valid ) {
        valid = create_context( &class_context, &context, 
            class_embedded_frame, frame, dpy, window );
    }
    
    /* Initialize screen saver */
    if( valid ) {
        mid = (*env)->GetMethodID( env, cls, "baseInit", 
            "(Lorg/jdesktop/jdic/screensaver/ScreensaverContext;)V" );
        if( mid == NULL ) {
            fprintf( stderr, "Could not find baseInit() method\n" );
            valid = 0;
        }
        else {
            (*env)->CallVoidMethod( env, saver, mid, context );
        }
    }
    
    /* Find renderFrame() method */
    if( valid ) {
        render_frame_mid = (*env)->GetMethodID( env, cls, "renderFrame", 
            "()V" );
        if( render_frame_mid == NULL ) {
            fprintf( stderr, "Could not find renderFrame() method\n" );
            valid = 0;
        }
    }
    
    /* Start render loop */
    tick = 60;
    if( valid ) {
        while (1) {
            tick++;
            if( tick > 30 ) {
                /* Update width and height every 30 frames */
                update_context( class_context, context, 
                    class_embedded_frame, frame, dpy, window );
                tick = 0;
            }
            
            /* Call renderFrame() */
            (*env)->CallVoidMethod( env, saver, render_frame_mid );
            
            screenhack_handle_events(dpy);
            if (delay) usleep(delay);
        }
    }
    
    /* destroy (never reached unless invalid) */
    if( env ) {
        if ((*env)->ExceptionOccurred(env)) {
            (*env)->ExceptionDescribe(env);
        }
    }
    if( jvm ) {
        (*jvm)->DestroyJavaVM(jvm);
    }
}
