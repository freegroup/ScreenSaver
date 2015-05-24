/****************************************************************************
** SaverScreenWindow meta object code from reading C++ file 'SaverScreenWindow.h'
**
** Created: Thu Jul 5 12:57:46 2001
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SaverScreenWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <qucom.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 14)
#error "This file was generated using the moc from 3.0.0-beta2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SaverScreenWindow::className() const
{
    return "SaverScreenWindow";
}

QMetaObject *SaverScreenWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SaverScreenWindow = QMetaObjectCleanUp();

#ifndef QT_NO_TRANSLATION
QString SaverScreenWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SaverScreenWindow", s, c, FALSE );
    else
	return QString::fromLatin1( s );
}
QString SaverScreenWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SaverScreenWindow", s, c, TRUE );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION

QMetaObject* SaverScreenWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"SaverScreenWindow", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0,
	0, 0 );
    cleanUp_SaverScreenWindow.setMetaObject( metaObj );
    return metaObj;
}

bool SaverScreenWindow::qt_invoke( int _id, QUObject* _o )
{
    return QMainWindow::qt_invoke(_id,_o);
}

bool SaverScreenWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SaverScreenWindow::qt_property( const QMetaProperty* _p, int _f, QVariant* _v)
{
    return QMainWindow::qt_property( _p, _f, _v);
}
#endif // QT_NO_PROPERTIES
