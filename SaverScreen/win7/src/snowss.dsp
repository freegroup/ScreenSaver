# Microsoft Developer Studio Project File - Name="SaverScreen" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SaverScreen - Win32 Release
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit\
 NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den\
 Befehl
!MESSAGE 
!MESSAGE NMAKE /f "snowss.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "snowss.mak" CFG="SaverScreen - Win32 Release"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "SaverScreen - Win32 Release" (basierend auf\
  "Win32 (x86) Application")
!MESSAGE "SaverScreen - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SaverScreen - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:".\Release\SaverScreen.scr"

!ELSEIF  "$(CFG)" == "SaverScreen - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:".\SaverScreen.scr"

!ENDIF 

# Begin Target

# Name "SaverScreen - Win32 Release"
# Name "SaverScreen - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\AnimatedBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingBigCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingBurstCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingCondom2Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingEarthBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingRaketeCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingReverseCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingRotateCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingSpermBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyingUndichtCondomBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\NumEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\NumSpinCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ranadd.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\snowss.cpp
# End Source File
# Begin Source File

SOURCE=.\snowss.rc
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\snowssDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SnowWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ssapp.cpp
# End Source File
# Begin Source File

SOURCE=.\sswnd.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TransparentBitmap.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\AnimatedBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingBigCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingBurstCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingCondom2Bitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingEarthBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingRaketeCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingReverseCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingRotateCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingSpermBitmap.h
# End Source File
# Begin Source File

SOURCE=.\FlyingUndichtCondomBitmap.h
# End Source File
# Begin Source File

SOURCE=.\NumEdit.h
# End Source File
# Begin Source File

SOURCE=.\NumSpinCtrl.h
# End Source File
# Begin Source File

SOURCE=.\ranadd.H
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\ShowWnd.h
# End Source File
# Begin Source File

SOURCE=.\snowss.h
# End Source File
# Begin Source File

SOURCE=.\snowssDlg.h
# End Source File
# Begin Source File

SOURCE=.\SnowWnd.h
# End Source File
# Begin Source File

SOURCE=.\ssbase.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TransparentBitmap.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\big_condom101.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom102.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom103.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom104.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom105.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom106.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom107.bmp
# End Source File
# Begin Source File

SOURCE=.\res\big_condom108.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom101.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom102.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom103.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom104.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom105.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom106.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom107.bmp
# End Source File
# Begin Source File

SOURCE=.\res\condom108.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Free71.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rakete_condom107.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rakete_condom108.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom101.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom102.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom103.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom104.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom105.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom106.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom107.bmp
# End Source File
# Begin Source File

SOURCE=.\res\reverse_condom108.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom101.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom102.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom103.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom104.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom105.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom106.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom107.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rotate_condom108.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SaverScreen.ico
# End Source File
# Begin Source File

SOURCE=.\res\SaverScreen.rc2
# End Source File
# Begin Source File

SOURCE=.\res\sperm1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sperm8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\undicht_condom101.bmp
# End Source File
# Begin Source File

SOURCE=.\res\undicht_condom102.bmp
# End Source File
# Begin Source File

SOURCE=.\res\undicht_condom105.bmp
# End Source File
# End Group
# End Target
# End Project
