@echo off

set VCVARSALL=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat
if not exist "%VCVARSALL%" set VCVARSALL=%VCVARSALL:Community\=Enterprise\%
if not exist "%VCVARSALL%" echo ERROR: vcvarsall.bat not found & exit /b 1

call "%VCVARSALL%" x86 > nul

set BUILD_DEBUG="msbuild.exe" /nologo^
	/p:ExcludeTests=true^
	/p:TrackFileAccess=false^
	/p:Configuration=Debug

set BUILD_RELEASE="msbuild.exe" /nologo^
	/p:ExcludeTests=true^
	/p:TrackFileAccess=false^
	/p:Configuration=Release

echo * Building 32-bit projects
%BUILD_DEBUG% /t:rebuild /p:Platform=x86 /v:q /m .\printf-0-precision-rounding-error-tests.sln || (echo   ERROR %ERRORLEVEL%: Build failed & exit /b 1)
%BUILD_RELEASE% /t:rebuild /p:Platform=x86 /v:q /m .\printf-0-precision-rounding-error-tests.sln || (echo   ERROR %ERRORLEVEL%: Build failed & exit /b 1)

echo * Building 64-bit projects
%BUILD_DEBUG% /t:rebuild /p:Platform=x64 /v:q /m .\printf-0-precision-rounding-error-tests.sln || (echo   ERROR %ERRORLEVEL%: Build failed & exit /b 1)
%BUILD_RELEASE% /t:rebuild /p:Platform=x64 /v:q /m .\printf-0-precision-rounding-error-tests.sln || (echo   ERROR %ERRORLEVEL%: Build failed & exit /b 1)

echo.
pause

call .\Test1.bat
call .\Test2.bat
