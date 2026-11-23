# Task 5 – Header Files and Conditional Compilation

## Objective
Organise a C billing program using header files and demonstrate compile-time debugging.

## Program Structure
- `billing.h`: Contains tariff constants, function prototypes and an include guard.
- `billing.c`: Implements the billing calculation and conditional debug function.
- `main.c`: Tests the billing calculation with five consumption values.

## Header File Concepts
The `#ifndef`, `#define` and `#endif` directives form an include guard. They prevent the same header contents from being processed more than once in a translation unit.

Angle brackets, as in `#include <stdio.h>`, are used for standard or system headers. Double quotes, as in `#include "billing.h"`, are used for project headers; the compiler searches the source file directory first.

## Conditional Compilation
`#ifdef DEBUG` includes debug printing only when DEBUG is defined during preprocessing. The normal build excludes this debug code. The debug build uses `-DDEBUG`.

## Compile-Time vs Runtime Debugging
- Compile-time: `#ifdef DEBUG` selects code before compilation. A normal build does not contain the excluded debug statements.
- Runtime: `if (debug)` checks a variable while the program runs. The condition and associated code remain in the compiled program.
- Compile-time selection can avoid runtime condition checks and debug code in production builds. Runtime selection allows debugging to be enabled or disabled without recompiling.

## Test Results

| Units | Expected bill | Observed bill |
|---:|---:|---:|
| 0 | Rs. 50.00 | Rs. 50.00 |
| 100 | Rs. 50.00 | Rs. 50.00 |
| 150 | Rs. 162.50 | Rs. 162.50 |
| 200 | Rs. 275.00 | Rs. 275.00 |
| 350 | Rs. 950.00 | Rs. 950.00 |

The debug build additionally prints consumption and bill values in paise. Both builds compiled with GCC warning flags and produced the expected calculations.

## Complexity
For each test case, the billing calculation performs a fixed number of comparisons and arithmetic operations: O(1) time and O(1) auxiliary space. For n test cases, total execution time is O(n).

## Conclusion
The program demonstrates modular organisation using a header file, include guards, project and system header inclusion, and compile-time debug selection.
