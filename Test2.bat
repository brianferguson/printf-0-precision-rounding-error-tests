@echo off
set ITERATIONS=%1
if "%ITERATIONS%" == "" set ITERATIONS=10

echo.
echo Test 2: Shows rounding error in debug builds
echo Iterations: %ITERATIONS%

if exist ".\x32-Debug\Test2.exe" (
  echo.
  echo Test2.exe (x32-Debug^)
  for /l %%i in (1,1,%ITERATIONS%) do .\x32-Debug\Test2.exe
)

if exist ".\x32-Release\Test2.exe" (
  echo.
  echo Test2.exe (x32-Release^)
  for /l %%i in (1,1,%ITERATIONS%) do .\x32-Release\Test2.exe
)

if exist ".\x64-Debug\Test2.exe" (
  echo.
  echo Test2.exe (x64-Debug^)
  for /l %%i in (1,1,%ITERATIONS%) do .\x64-Debug\Test2.exe
)

if exist ".\x64-Release\Test2.exe" (
  echo.
  echo Test2.exe (x64-Release^)
  for /l %%i in (1,1,%ITERATIONS%) do .\x64-Release\Test2.exe
)

echo.
echo Result: Inconsistent results from 32-bit debug builds, and all 64-bit debug builds are incorrect.
echo.

pause
