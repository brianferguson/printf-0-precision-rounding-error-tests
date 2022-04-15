/* Test1.cpp - Using "legacy_stdio_float_rounding.obj"
*  By: Brian Ferguson
*  Date: 2022-04-15
*  
*  Reported bug:
*    https://developercommunity.visualstudio.com/t/printf-family-functions-with-0-precision/1702961
* 
*  Description:
*    This test uses "legacy_stdio_float_rounding.obj" as described by the following link:
*    https://docs.microsoft.com/en-us/cpp/c-runtime-library/link-options?view=msvc-170
* 
*  Testing Environment:
*    Windows 10 (21H1) 19043.1586
*    Visual Studio 2022 (17.1.4)
*    C++ Compiler: 19.31.31106.2 (using command "cl" from developer command prompt)
*    Project settings: Mostly default "console" settings with minor changes to output file
*      locations. See ".vcxproj" files for details.
* 
*  Results:
*    x86 (debug)  : All floating-point values rounded correctly.
*    x86 (release): All floating-point values rounded correctly.
*    x64 (debug)  : All floating-point values rounded correctly.
*    x64 (release): All floating-point values rounded correctly.
* 
*  Notes:
*    Same results as VS2019 prior to 16.2, and all other compilers I could test.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Test 1 - double: ");
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

	printf("Test 1 - float:  ");
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
