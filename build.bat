@echo off
cls
cd src
echo Compiling...
gcc -Wall -Wextra -g3 -I lib -o ../BankingSystem.exe *.c

if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b
)
cd ..
set /p runNow="Compilation successful. Do you want to run the program now? (Y/N): "
if /i "%runNow%"=="Y" (
    echo.
    echo Running program...
    start BankingSystem.exe
) else (
    exit /b
)