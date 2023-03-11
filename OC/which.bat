@echo off
setlocal enabledelayedexpansion
if "%1"=="" goto help
set arg=%1
:start
if not "%1"=="" (
	shift
	if "%1"=="/?" goto help
	goto :start
) 
for %%a in ("%pathext:;=" "%") do (
echo %arg%|findstr /E /I %%a >nul
if not ERRORLEVEL 1 goto rashr
)
set ext=0
for %%a in ("%pathext:;=" "%") do (
if EXIST "%CD%\!arg!%%~a" (
echo This is an external command: %CD%\!arg!%%~a
set ext=1
goto :internal
)
)
for %%G in ("%path:;=" "%") do (
for %%a in ("%pathext:;=" "%") do (
if EXIST "%%~G\!arg!%%~a" (
echo This is an external command: %%~G\!arg!%%~a
set ext=1
goto :internal
)
)
)
goto :internal
:rashr
if EXIST "%CD%\!arg!" (
echo This is an external command: %CD%\!arg!
set ext=1
goto :internal
)
for %%G in ("%path:;=" "%") do (
if EXIST "%%~G\!arg!" (
echo This is an external command: %%~G\!arg!
set ext=1
goto :internal
)
)
:internal
SET PATH=
%arg% /? >NUL 2>&1
IF ERRORLEVEL 9009 (
if "%ext%"=="0" (
echo This is not a command
)
ENDLOCAL
goto :EOF
)
if "%ext%"=="1" (
echo This is also an internal command
ENDLOCAL
goto :EOF
)
echo This is internal command
ENDLOCAL
goto :EOF
:help
echo WHICH
echo Shows path to file or notifies if command is internal.