@echo off

set CURRENT_DIR=%cd%
set BUILD_DIR=build

set APP_NAME=SpanTree
set APP_ROOT=%CURRENT_DIR%\..

if (%QTDIR%)==() set QTDIR=C:\Qt\5.15.2\wasm_32
set QMAKE=%QTDIR%\bin\qmake
set MAKE=C:\Qt\Tools\mingw810_64\bin\mingw32-make

call emsdk_env.bat