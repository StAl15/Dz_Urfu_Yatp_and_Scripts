@echo off
set input=%1

set /is_exist_curr is_exist_curr=0
set /is_exist_prev is_exist_prev=0

IF EXIST input (
 is_exist_curr=1
) ELSE (
 for %f in %PATHEXT% do (
    input=input + %f 
    IF EXIST input (
        is_exist_curr=1
    )
 )
)
set /result result = is_exist_curr + is_exist_prev

IF result!=0 (
 echo %1 is exist
) ELSE (
 not exist
)