@echo off

echo.
echo Test 1: Uses "legacy_stdio_float_rounding.obj"

if exist ".\x32-Debug\Test1.exe" (
  echo.
  echo Test1.exe (x32-Debug^)
  .\x32-Debug\Test1.exe
)

if exist ".\x32-Release\Test1.exe" (
  echo.
  echo Test1.exe (x32-Release^)
  .\x32-Release\Test1.exe
)

if exist ".\x64-Debug\Test1.exe" (
  echo.
  echo Test1.exe (x64-Debug^)
  .\x64-Debug\Test1.exe
)

if exist ".\x64-Release\Test1.exe" (
  echo.
  echo Test1.exe (x64-Release^)
  .\x64-Release\Test1.exe
)

echo.
echo Result: Correctly rounds all floating-point values between [0.5,0.6]
echo.

pause
