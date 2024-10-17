#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "threed.h"

/* 
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return false; }

ThreeDPtr testThreeD;

int testCount = 0;
int passCount = 0;

void printTestInfo(char* testName, char *info) {
	fprintf(stdout, "%s - %s\n", testName, info);
}

void printTestResult(char* testName, bool passed) {
	if(passed == true)
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	else
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
}

/* Test Case Definitions */

bool SetValWithinBounds(void) {

    SetVal(testThreeD, 5, 5, 5, 27);

	myassert(GetVal(testThreeD, 5, 5, 5) == 27) //no semicolon for the macro!!! 

    // if assert/s end up true, return that! 
    return true;
}


bool SetValOutsideBounds(void) {

    SetVal(testThreeD, 50, 5, 5, 27);

    //what should the behavior be? Defensive programming? Should it crash?

    // if assert/s end up true, return that! 
    return true;
}

/*
 * etc...
 */

void beforeTest(char* testName) {
	printTestInfo(testName, "Running...");
	testThreeD = CreateThreeD(10, 20, 30);
	testCount++;
}

void afterTest(char* testName, bool result) {
	printTestResult(testName, result);
	DestroyThreeD(testThreeD);
	passCount += result;
}

void runUnitTests(void) {
	bool result;
	char *testName;

	testName = "SetValWithinBounds";
	beforeTest(testName);
	result = SetValWithinBounds();
	afterTest(testName, result);



	testName = "SetValOutsideBounds";
	beforeTest(testName);
	result = SetValOutsideBounds();
	afterTest(testName, result);
	//etc...

	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(void) {
	runUnitTests();
	exit(0);
}
