printf-0-precision-rounding-error-tests
----

Simple tests showing a rounding error with printf when using **0** precision on floating-point values, both `double` and `float`, between values `0.5` and `0.6`.

**Note 1**: As of VS2022 (17.1.4), this seems to happen on `debug` builds (both 32 and 64 bit). The 32-bit debug build's results are inconsistent, sometimes correctly rounding the values, sometimes not.

**Note 2**: These tests seem to show the problem only in `debug` builds, however, <u>I am also seeing the issue in `release` builds on a different project</u>. I do not know what compiler flags or other settings are causing this behavior.

----

### Test environment:
* **Windows 10 (21H1) 19043.1586**
* **Visual Studio 2022 (17.1.4)**
* **C++ Compiler**: 19.31.31106.2 (using command "cl" from developer command prompt)
* **Project settings**: Mostly default "console" settings with minor changes to output file locations. See ".vcxproj" files for details.
  * `Test1.vcxproj` changes: [here](https://github.com/brianferguson/printf-0-precision-rounding-error-tests/Test1/Test1.vcxproj#L4-L12) and [here](https://github.com/brianferguson/printf-0-precision-rounding-error-tests/Test1/Test1.vcxproj#L97-L105)
  * `Test2.vcxproj` changes: [here](https://github.com/brianferguson/printf-0-precision-rounding-error-tests/Test2/Test2.vcxproj#L4-L12) and [here](https://github.com/brianferguson/printf-0-precision-rounding-error-tests/Test2/Test2.vcxproj#L97-L104)

----

### Build instructions (using VS2022):
1. Download repo
2. Run `Build.bat` (This will also run `Test1.bat` and `Test2.bat`)

###### Notes: This will run each "Test1.exe" once. "Test2.exe" will run 10 times each to show the inconsistent results for the 32-bit debug build.

----

### Run tests:
There are 2 test batch files. They do the following:
* `Test1.bat` - This runs all 4 `Test1.exe` programs. `Test1` utilizes the "legacy_stdio_float_rounding.obj" file described [here](https://docs.microsoft.com/en-us/cpp/c-runtime-library/link-options?view=msvc-170). Results are correct.
* `Test2.bat` - Runs all 4 `Test2.exe` programs. `Test2` does not use the legacy file from `Test1`. Debug builds are incorrect, with the 32-bit version giving inconsistent results.


----

Sample output:
``` txt
* Building 32-bit projects
* Building 64-bit projects

Press any key to continue . . . 

Test 1: Uses "legacy_stdio_float_rounding.obj"

Test1.exe (x32-Debug)
Test 1 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 1 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1

Test1.exe (x32-Release)
Test 1 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 1 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1

Test1.exe (x64-Debug)
Test 1 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 1 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1

Test1.exe (x64-Release)
Test 1 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 1 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1

Result: Correctly rounds all floating-point values between [0.5,0.6]

Press any key to continue . . . 

Test 2: Shows rounding error in debug builds
Iterations: 10

Test2.exe (x32-Debug)
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 1 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1

Test2.exe (x32-Release)
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1

Test2.exe (x64-Debug)
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1
Test 2 - double: 0 0 0 0 0 0 0 0 0 0 0 0 1
Test 2 - float:  0 0 0 0 0 0 0 0 0 0 0 1 1

Test2.exe (x64-Release)
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - double: 0 0 1 1 1 1 1 1 1 1 1 1 1
Test 2 - float:  0 0 1 1 1 1 1 1 1 1 1 1 1

Result: Inconsistent results from 32-bit debug builds, and all 64-bit debug builds are incorrect.

Press any key to continue . . . 
```

----

Links
* Bug report: [https://developercommunity.visualstudio.com/t/printf-family-functions-with-0-precision/1702961](https://developercommunity.visualstudio.com/t/printf-family-functions-with-0-precision/1702961)
* Previous bug report (incorrectly marked as duplicate): [https://developercommunity.visualstudio.com/t/printf-rounding-bug-in-C-runtime-version/1197890#T-N1200879](https://developercommunity.visualstudio.com/t/printf-rounding-bug-in-C-runtime-version/1197890#T-N1200879)
* Link options: [https://docs.microsoft.com/en-us/cpp/c-runtime-library/link-options?view=msvc-170](https://docs.microsoft.com/en-us/cpp/c-runtime-library/link-options?view=msvc-170)
