@echo off
set input=%1

set target=%1

for %%a in("%pathext:;=" "%") do (
    echo %arg%|findstr /E /I %%a >null
)

set external_cmd=0
for %%a in ("%pathext:;=" "%") do (
    if EXIST "%CD%\!arg!%%~a" (
        echo This is an external command: %CD%\!arg!%%~a
        set ext=1
    )
)

