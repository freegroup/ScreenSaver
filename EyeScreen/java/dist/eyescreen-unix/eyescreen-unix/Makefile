# Screensaver Makefile

# Set this to your Java home directory
jdkhome=/usr/java/j2sdk1.5.0

# Set this to where xscreensaver is installed
xscreensaverhome=/opt/xscreensaver-4.14

# Set this to your platform (either Linux or SunOS)
# Leave alone to autodetect
platform=`uname`

# Compiler
cc=gcc

# Linker
link=gcc

# Symbol Stripper
strip=strip

# Args to compiler and linker
commonargs=-Wall -Wstrict-prototypes -Wnested-externs -std=c89 -U__STRICT_ANSI__

# Args to compiler
ccargs=${commonargs} -c -I . -I ${xscreensaverhome}/hacks -I ${xscreensaverhome}/utils -I ${xscreensaverhome} -I ${jdkhome}/include -I ${jdkhome}/include/linux -I ${jdkhome}/include/solaris -DPLATFORM_${platform} -DSTANDALONE -g -O2

# Args to linker
linkargs=${commonargs} -L/usr/local/lib -L/usr/X11R6/lib -L${jdkhome}/jre/lib/i386 -L${jdkhome}/jre/lib/i386/client -L${jdkhome}/jre/lib/sparc -L${jdkhome}/jre/lib/sparc/client -ljvm -lSM -lICE -lXm -lXt -lX11 -lXmu -lXext -lm

# Objects for linker
linkobj=${xscreensaverhome}/hacks/screenhack.o ${xscreensaverhome}/utils/resources.o ${xscreensaverhome}/utils/visual.o ${xscreensaverhome}/utils/usleep.o ${xscreensaverhome}/utils/yarandom.o

all: eyescreen-bin 

eyescreen-bin:
	${cc} ${ccargs} -o eyescreen.o eyescreen.c
	${link} ${linkargs} -o eyescreen-bin eyescreen.o ${linkobj}
	${strip} eyescreen-bin
	chmod a+x eyescreen



clean:
	rm eyescreen-bin  *.o

