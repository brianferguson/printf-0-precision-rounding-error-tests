/* Test2.cpp
*  By: Brian Ferguson
*  Date: 2022-04-15
*
*  Reported bug:
*    https://developercommunity.visualstudio.com/t/printf-family-functions-with-0-precision/1702961
* 
*  Description:
*    This test does not use the "legacy_stdio_float_rounding.obj" file like "Test1" does. Debug builds
*    show the rounding error.
*
*  Testing Environment:
*    Windows 10 (21H1) 19043.1586
*    Visual Studio 2022 (17.1.4)
*    C++ Compiler: 19.31.31106.2 (using command "cl" from developer command prompt)
*    Project settings: Mostly default "console" settings with minor changes to output file
*      locations. See ".vcxproj" files for details.
*
*  Results:
*    x86 (debug)  : Inconsistent results. Sometimes values are rounded, sometimes not. Run "Test2.bat" to see the differences.
*    x86 (release): All tested floating-point values are rounded correctly.
*    x64 (debug)  : NO tested floating-point values are rounded correctly!!!!     <------
*    x64 (release): All tested floating-point values are rounded correctly.
*
*  Notes:
*    I get the same results from VS2019 16.3 to VS2022 17.1.4 (current). Also, there seems to be other compiler or linker options
*    that also affect this printf issue since other projects in RELEASE mode also show the issue. Unfortunately, I can't show an 
*    easy example of that since I do not know the exact project settings that affect this issue.
* 
*  Conclusion:
*    There is an issue (with "debug" builds) with printf using 0 precision rounding between
*    floating-point values of [0.5, 0.6].
*/

#include <stdio.h>  // results are the same if using the "#include <cstdio>" library

int main(int argc, char* argv[])
{
	printf("Test 2 - double: ");
	printf("%.0f ",  0.49);
	printf("%.0f ",  0.50);
	printf("%.0f ",  0.51);
	printf("%.0f ",  0.52);
	printf("%.0f ",  0.53);
	printf("%.0f ",  0.54);
	printf("%.0f ",  0.55);
	printf("%.0f ",  0.56);
	printf("%.0f ",  0.57);
	printf("%.0f ",  0.58);
	printf("%.0f ",  0.59);
	printf("%.0f ",  0.60);
	printf("%.0f\n", 0.61);

	printf("Test 2 - float:  ");
	printf("%.0f ",  0.49f);
	printf("%.0f ",  0.50f);
	printf("%.0f ",  0.51f);
	printf("%.0f ",  0.52f);
	printf("%.0f ",  0.53f);
	printf("%.0f ",  0.54f);
	printf("%.0f ",  0.55f);
	printf("%.0f ",  0.56f);
	printf("%.0f ",  0.57f);
	printf("%.0f ",  0.58f);
	printf("%.0f ",  0.59f);
	printf("%.0f ",  0.60f);
	printf("%.0f\n", 0.61f);

	return 0;
}
