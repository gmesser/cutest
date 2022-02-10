# cutest - C language Unit Test framework - header-only design.
  
### Inspired by minunit, with thanks!

* *See: http://www.jera.com/techinfo/jtns/jtn002.html*

### Changes from minunit:

* *Continues after test failures. (The minunit macros stopped on the first failure.)*
* *Counts test cases, passes, and failures.*
* *Reports the result of the test functions.*

## Terms:

* A **test suite** is a function that calls one or more test cases.
* A **test case** is a function that evaluates one or more assertions.
* The **assertion** calls are automatically numbered; their results are counted to determine the PASS and FAIL statuses for the test cases.

## Macros:

There is no .c source file for this unit test framework.  All the work is done by macros in **cutest.h**.

The **cu_initialize_suite** macro:
* Initializes the test suite's run/fail counters to 0.

The **cu_assert** macro:
* Increments the assertion run counter.
* Evaluates assert expressions.
* Prints "True" and the assertion if the assertion evaluates to true.
* Prints "False" and the assertion, and the failure message, if the assertion evaluates to false.
* Increments the assertion failure counter if the assertion evaluates to false.

The **cu_run_case** macro:
* Initializes the test case's assertion run/fail counters to 0.
* Increments the test case run counter.
* Calls test case functions.
* Ignores return values from the test case functions.
* Prints "Passed" if all the assertions were true.
* Prints "Failed" if one or more of the assertions were false.
* Increments the test case failure counter if the assertion failure counter is greater than 0.
* Prints the number and percentage of failed assertions for the test case.

The **cu_report** macro:
* Prints PASS or FAIL for the test suite.
* Prints "PASS" if all the test cases passed.
* Prints "FAIL" if one or more of the test cases failed.
* Prints the number and percentage of failed test cases.

The **cu_return_value** macro:
* Determines the return value for the test suite.
* Evaluates to 0 if the test suite passed.
* Evaluates to 1 if the test suite failed.

## Usage:

Include the **cutest.h** file.

```
#include <cutest.h>
```

Define the following four counter variables where they are visible to the test case functions.
They could be in one common file that is linked to the test program during the build.  They could also be in separate files, which would allow multiple test suites to run concurrently, with each suite maintaining its own counters.

```
/**
 The required counters.  
 The cu_initialize_suite and cu_run_case macros initialize the counters.
 The cu_run_case and cu_assert macros increment the counters.
 The cu_report_suite macro reports the counters.
 The cu_suite_return_value macro uses the 
 cu_case_fails counter. 
*/

int cu_case_runs;
int cu_case_fails;
int cu_assert_runs;
int cu_assert_fails;
```

## Example test suite function:

```
/**
 A test suite minimally requires:
  1. A cu_initialize_suite() statement
  2. Zero or more cu_run_case() statements
  3. A cu_report_suite() statement
*/

// This is a test suite function that calls two test case functions.
int test_suite(int argc, char *argv[]) {
    cu_initialize_suite();

    // Call the cu_run_case macro to run two test case functions.
    cu_run_case(test_case1);
    cu_run_case(test_case2);
    // ...

    cu_report();
    return(cu_return_value);
}
```

## Example test case function:

```
/**
 A test case requires:
   1. Zero or more cu_assert statements
 */

// This is a test case function that evaluates two assertions.
void test_case1(void) {
    int value = should_return_zero(); // Get a value to be tested.
    cu_assert(value == 0, "Error: Expected zero.");  // Passes if the function returns 0.
    
    value = should_return_non_zero(); // Get a value to be tested.
    cu_assert(value != 0, "Error: Expected non-zero.");  // Passes if the function returned non-zero.
}
```
