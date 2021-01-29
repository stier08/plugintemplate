set BUILD_PLATFORM=Win32
set BUILD_CONFIGURATION=Debug

set NPP_HOME=%PORTABLE_WS_APP_HOME%npp.7.7.1.bin
set PLUGIN_HOME=%NPP_HOME%\plugins\NppPyStandalonePlugin

call md %PLUGIN_HOME%
set ARTIFACT_HOME=%~dp0bin\Output\%BUILD_PLATFORM%\%BUILD_CONFIGURATION%
xcopy /y "%ARTIFACT_HOME%\NppPyStandalonePlugin\NppPyStandalonePlugin.dll" "%PLUGIN_HOME%"\NppPyStandalonePlugin.dll
xcopy /y "%ARTIFACT_HOME%\NppPyStandalonePlugin\NppPyStandalonePlugin.pdb" "%PLUGIN_HOME%"\NppPyStandalonePlugin.pdb

rem set NPP_INIT_PY_PATH=%PORTABLE_WS_CORE_HOME%pylibs\pysergplugin\pynppinit.py

rem cd /d %PORTABLE_WS_BIN_HOME%
rem npp.bat
