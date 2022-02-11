// cutest_test.c - test the cutest.h macros
/*
 This file illustrates running multiple unit test suites, each with one or more test cases.
*/
#include <stdio.h>
#include "cutest.h"

// Test suite functions:
int test_suite1();
int test_suite2();
int test_suite3();
int test_suite4();
int test_suite5();
int test_suite6();

// Test case functions:
void test_case1();
void test_case2();
void test_case3();
void test_case4();
void test_case5();
void test_case6();
void test_case7();

int cu_case_runs, cu_case_fails, cu_assert_runs, cu_assert_fails; // REQUIRED

// This main() function runs several suites.  
int main(int argc, char *argv[]) {
	test_suite1();
	test_suite2();
	test_suite3();
	test_suite4();
	test_suite5();
	test_suite6();
}

int test_suite1() {
	// Start a suite of tests.  Mix of passes and fails.
	cu_initialize_suite();
	// Call the cu_run_case macro to run a test function one or more times as needed.
	cu_run_case(test_case1);
	cu_run_case(test_case2);
	cu_run_case(test_case3);
	cu_run_case(test_case4);
	cu_run_case(test_case5);
	cu_run_case(test_case1);
	cu_run_case(test_case2);
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

int test_suite2() {
	// Start another suite of tests.  All pass.
	cu_initialize_suite();
	// Call the cu_run_case macro to run more test functions.
	cu_run_case(test_case1);
	cu_run_case(test_case1);
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

int test_suite3() {
	// Start another suite of tests.  All fail.
	cu_initialize_suite();
	// Call the cu_run_case macro to run more test functions.
	cu_run_case(test_case5);
	cu_run_case(test_case5);
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

int test_suite4() {
	// Start another suite of tests.  All fail.
	cu_initialize_suite();
	// Call the cu_run_case macro to run more test functions.
	cu_run_case(test_case6);
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

int test_suite5() {
	// Start another suite of tests.  No test cases.
	cu_initialize_suite();
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

int test_suite6() {
	// Start another suite of tests.  All fail.
	cu_initialize_suite();
	// Call the cu_run_case macro to run more test functions.
	cu_run_case(test_case7);
	// Report the results of the tests.
	cu_report_suite();
	return(cu_suite_return_value);
}

void test_case1() {
	// Do something that sets the value, then call the cu_assert macro.
	int value = 0;
 	cu_assert(value == 0, "Error: 1st value was not zero.");
	value = 0;
 	cu_assert(value == 0, "Error: 2nd value was not zero.");
	value = 0;
	cu_assert(value == 0, "Error: 3rd value was not zero.");
}

void test_case2() {
	int value = 0;
 	cu_assert(value == 0, "Error: 1st value was not zero.");
	value = 0;
 	cu_assert(value == 0, "Error: 2nd value was not zero.");
	value = 33;
	cu_assert(value == 0, "Error: 3rd value was not zero.");
}

void test_case3() {
	int value = 0;
 	cu_assert(value == 0, "Error: 1st value was not zero.");
	value = 22;
 	cu_assert(value == 0, "Error: 2nd value was not zero.");
	value = 33;
	cu_assert(value == 0, "Error: 3rd value was not zero.");
}

void test_case4() {
	int value = 11;
 	cu_assert(value != 0, "Error: 1st value was zero.");
	value = 22;
 	cu_assert(value != 0, "Error: 2nd value was zero.");
	value = 33;
	cu_assert(value != 0, "Error: 3rd value was zero.");
}

void test_case5() {
	int value = 0;
 	cu_assert(value != 0, "Error: 1st value was zero.");
	value = 0;
 	cu_assert(value != 0, "Error: 2nd value was zero.");
	value = 0;
	cu_assert(value != 0, "Error: 3rd value was zero.");
}

void test_case6() {
	int value = 0;
	cu_assert(value != 0, "Error: 3rd value was zero.");
}

void test_case7() {
	int value = 0;
 	cu_assert(value == 0, "Error: 1st value was not zero.");
}
