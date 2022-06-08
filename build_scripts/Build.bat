@echo off

call SetEnv.bat

cd %APP_ROOT%

if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cd %BUILD_DIR%

%QMAKE% %APP_ROOT%\%APP_NAME%.pro
%MAKE%

cd %CURRENT_DIR%
pause