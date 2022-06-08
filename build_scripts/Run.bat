@echo off

call SetEnv.bat

set BROWSER_PATH="C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe"
rem set BROWSER_PATH="C:\Programs\Firefox Setup 98.0.2\firefox.exe"

cd %APP_ROOT%

if not exist %BUILD_DIR% exit /b 1

cd %CURRENT_DIR%

set WEBPAGE_PATH=%APP_ROOT%\%BUILD_DIR%\%APP_NAME%.html

emrun --browser=%BROWSER_PATH% %WEBPAGE_PATH% 

pause