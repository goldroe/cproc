@echo off

SET WARNING_FLAGS=-WX -W4 -wd4100 -wd4101 -wd4189 -wd4996
SET COMPILER_FLAGS=-nologo -FC -Zi
SET LINKER_FLAGS=

PUSHD ..\build

CL %WARNING_FLAGS% %COMPILER_FLAGS% ..\code\cproc.c -link %LINKER_FLAGS%

REM Copy the executable to my utilities folder
COPY cproc.exe C:\Dev\utils > nul 2> nul

POPD
