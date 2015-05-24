# Microsoft Developer Studio Project File - Name="EyeScreen" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=EyeScreen - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "EyeScreen.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "EyeScreen.mak" CFG="EyeScreen - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "EyeScreen - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "EyeScreen - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "EyeScreen - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "$(QTDIR)\include" /I "_$(QTDIR)\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib wsock32.lib $(QTDIR)\lib\qt-mt300.lib $(QTDIR)\lib\qtmain.lib /nologo /subsystem:windows /machine:I386 /out:"EyeScreen.scr"

!ELSEIF  "$(CFG)" == "EyeScreen - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /I "$(QTDIR)\include" /I "_$(QTDIR)\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib wsock32.lib $(QTDIR)\lib\qt-mt300.lib $(QTDIR)\lib\qtmain.lib /nologo /subsystem:windows /debug /machine:I386 /out:"EyeScreen_debug.scr" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "EyeScreen - Win32 Release"
# Name "EyeScreen - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\ActionObject.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject001.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject002.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject003.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject004.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject005.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject006.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject007.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject008.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject009.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject010.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject011.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject012.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject013.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject014.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject015.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject016.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObject017.cpp
# End Source File
# Begin Source File

SOURCE=.\ActionObjectWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\AnimatedObject.cpp
# End Source File
# Begin Source File

SOURCE=.\animation.cpp
# End Source File
# Begin Source File

SOURCE=.\EyeScreenWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\moc_EyeScreenWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\ranadd.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\ActionObject.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject001.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject002.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject003.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject004.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject005.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject006.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject007.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject008.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject009.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject010.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject011.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject012.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject013.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject014.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject015.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject016.h
# End Source File
# Begin Source File

SOURCE=.\ActionObject017.h
# End Source File
# Begin Source File

SOURCE=.\ActionObjectWrapper.h
# End Source File
# Begin Source File

SOURCE=.\AnimatedObject.h
# End Source File
# Begin Source File

SOURCE=.\animation.h
# End Source File
# Begin Source File

SOURCE=.\EyeScreenWindow.h

!IF  "$(CFG)" == "EyeScreen - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Moc'ing $(InputName).h ...
InputDir=.
InputPath=.\EyeScreenWindow.h
InputName=EyeScreenWindow

"$(InputDir)\moc_$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%qtdir%\bin\moc.exe $(InputDir)\$(InputName).h -o $(InputDir)\moc_$(InputName).cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "EyeScreen - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Moc'ing $(InputName).h ...
InputDir=.
InputPath=.\EyeScreenWindow.h
InputName=EyeScreenWindow

"$(InputDir)\moc_$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%qtdir%\bin\moc.exe $(InputDir)\$(InputName).h -o $(InputDir)\moc_$(InputName).cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ranadd.H
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\readme.txt
# End Source File
# End Target
# End Project
