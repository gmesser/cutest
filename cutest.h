/* cutest.h - C unit test macros. */

#ifndef CUTEST_H
#define CUTEST_H

#include <stdio.h>  // For printf() only.

/**
 Required counters - must be in the scope of the framework functions.
*/
extern int cu_case_runs;	// Number of test cases run
extern int cu_case_fails;	// Number of test cases that failed
extern int cu_assert_runs;	// Number of assertions evaluated in a test case
extern int cu_assert_fails;	// Number of assertions that evaluated as false in a test case

/**
 Initialize the test suite counters.
 */
#define cu_initialize_suite() \
do { \
	cu_case_runs = 0; \
	cu_case_fails = 0; \
	printf("%-9s Test suite...  File: %s.  Function: %s.\n", \
                "Suite", \
                __FILE__, \
                __FUNCTION__); \
} while (0)

/**
 Run a test case function and report the result.  
   "Passed" means all the assertions in the test case function evaluated to true.
   "Failed" means one or more of the assertions in the test case function evaluated to false.
*/
#define cu_run_case(cu_case_func) \
do { \
	cu_assert_runs = 0; \
	cu_assert_fails = 0; \
	cu_case_runs++; \
	printf("  %-9s Test case...  File: %s.  Function: %s.  Case: #%d.\n", \
                "Case", \
                __FILE__, \
                #cu_case_func, \
                cu_case_runs); \
	cu_case_func(); \
	printf("  %-9s Test case...  File: %s.  Function: %s.  Case: #%d.  ", \
				(cu_assert_fails == 0 ? "Passed" : "Failed"), \
				__FILE__, \
				#cu_case_func, \
				cu_case_runs); \
	if (cu_assert_fails == 0) { \
		printf("%d of %d (%3.1f%%) true assertions.", \
				cu_assert_runs, \
				cu_assert_runs, \
				100.0); \
	} \
 	else { \
		printf("%d of %d (%3.1f%%) false assertions.", \
				cu_assert_fails, \
				cu_assert_runs, \
				(cu_assert_fails / (cu_assert_runs + 0.0)) * 100); \
		cu_case_fails++; \
	} \
	printf("\n"); \
} while (0)

/**
 Evaluate an assertion and print a message if it fails.
 Note: 
   Write your assertions so that a passing condition evaluates to true.  
   Assertions that evaluate to false count as failures.
*/
#define cu_assert(cu_assert_expr, cu_failure_message) \
do { \
	cu_assert_runs++; \
	if (!(cu_assert_expr)) { \
		printf("    %-9s Assertion #%d.%d (%s) %s\n", \
                "False", \
                cu_case_runs, \
                cu_assert_runs, \
                #cu_assert_expr, \
                #cu_failure_message); \
		cu_assert_fails++; \
	} \
	else { \
		printf("    %-9s Assertion #%d.%d (%s)\n", \
                "True", \
                cu_case_runs, \
                cu_assert_runs, \
                #cu_assert_expr); \
	} \
} while (0)

/**
 Print a report of the result of running a suite of test functions.
   "PASS" means that all the suite functions passed.
   "FAIL" means that one or more of the suite functions failed.
*/
#define cu_report_suite() \
do { \
	printf("%-9s Test suite...  File: %s.  Function: %s.  ", \
				((cu_case_fails == 0) ? "PASS" : "FAIL"), \
				__FILE__, \
				__FUNCTION__); \
	if (cu_case_fails == 0)  { \
		printf("%d of %d test case functions (%3.1f%%) passed.", \
				cu_case_runs, \
				cu_case_runs, \
				100.0); \
	} \
	else { \
		printf("%d of %d test case functions (%3.1f%%) failed.", \
				cu_case_fails, \
				cu_case_runs, \
				(cu_case_fails / (cu_case_runs + 0.0)) * 100); \
	} \
	printf("\n\n"); \
} while (0)

/**
 Determine the return value of the test suite. 
   1 means that at least one failure occured in the suite.
   0 means that all tests passed in the suite.
*/
#define cu_suite_return_value (cu_case_fails > 0 ? 1 : 0)

#endif // CUTEST_H
