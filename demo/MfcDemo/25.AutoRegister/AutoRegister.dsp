# Microsoft Developer Studio Project File - Name="AutoRegister" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=AutoRegister - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AutoRegister.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AutoRegister.mak" CFG="AutoRegister - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AutoRegister - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AutoRegister - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AutoRegister - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/AutoRegisterDemo.exe"

!ELSEIF  "$(CFG)" == "AutoRegister - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/AutoRegisterDemo.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AutoRegister - Win32 Release"
# Name "AutoRegister - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ActiveLoginDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoRegister.rc
# End Source File
# Begin Source File

SOURCE=.\ActiveLoginDemoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BSWndContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\DeviceInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\dhmutex.cpp
# End Source File
# Begin Source File

SOURCE=.\ExButton.cpp
# End Source File
# Begin Source File

SOURCE=.\excel.cpp
# End Source File
# Begin Source File

SOURCE=.\NameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\PluginLogging.cpp
# End Source File
# Begin Source File

SOURCE=.\PTZControlDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PtzScreen.cpp
# End Source File
# Begin Source File

SOURCE=.\ReadWriteExcel.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TreeCtrlEx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ActiveLoginDemo.h
# End Source File
# Begin Source File

SOURCE=.\ActiveLoginDemoDlg.h
# End Source File
# Begin Source File

SOURCE=.\BSWndContainer.h
# End Source File
# Begin Source File

SOURCE=.\DeviceInfo.h
# End Source File
# Begin Source File

SOURCE=.\dhconfigsdk.h
# End Source File
# Begin Source File

SOURCE=.\dhmutex.h
# End Source File
# Begin Source File

SOURCE=.\dhnetsdk.h
# End Source File
# Begin Source File

SOURCE=.\ExButton.h
# End Source File
# Begin Source File

SOURCE=.\excel.h
# End Source File
# Begin Source File

SOURCE=.\MessageText.h
# End Source File
# Begin Source File

SOURCE=.\NameDlg.h
# End Source File
# Begin Source File

SOURCE=.\PlayWnd.h
# End Source File
# Begin Source File

SOURCE=.\PluginLogging.h
# End Source File
# Begin Source File

SOURCE=.\PTZControlDlg.h
# End Source File
# Begin Source File

SOURCE=.\PtzScreen.h
# End Source File
# Begin Source File

SOURCE=.\ReadWriteExcel.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TreeCtrlEx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\AutoRegister.ico
# End Source File
# Begin Source File

SOURCE=.\res\AutoRegister.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
