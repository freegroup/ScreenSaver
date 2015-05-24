/****************************************************************************
** EyeScreenWindow meta object code from reading C++ file 'EyeScreenWindow.h'
**
** Created: Thu Jul 5 11:39:49 2001
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EyeScreenWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <qucom.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 14)
#error "This file was generated using the moc from 3.0.0-beta2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EyeScreenWindow::className() const
{
    return "EyeScreenWindow";
}

QMetaObject *EyeScreenWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EyeScreenWindow = QMetaObjectCleanUp();

#ifndef QT_NO_TRANSLATION
QString EyeScreenWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EyeScreenWindow", s, c, FALSE );
    else
	return QString::fromLatin1( s );
}
QString EyeScreenWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EyeScreenWindow", s, c, TRUE );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION

QMetaObject* EyeScreenWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"EyeScreenWindow", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0,
	0, 0 );
    cleanUp_EyeScreenWindow.setMetaObject( metaObj );
    return metaObj;
}

bool EyeScreenWindow::qt_invoke( int _id, QUObject* _o )
{
    return QMainWindow::qt_invoke(_id,_o);
}

bool EyeScreenWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EyeScreenWindow::qt_property( const QMetaProperty* _p, int _f, QVariant* _v)
{
    return QMainWindow::qt_property( _p, _f, _v);
}
#endif // QT_NO_PROPERTIES
