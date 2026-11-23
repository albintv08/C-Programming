# Task 04 — Use Macros Safely

**Course:** CSA02 – C Programming  
**Assignment:** 1  
**Student:** Albin T.V.  
**Register Number:** 1924260177

## Objective
Demonstrate safe C macros, understand preprocessor expansion, identify macro pitfalls, and compare macros with static inline functions.

## Files
- `macro_demo.c` — C source code and macro demonstrations.
- `output.txt` — Actual program execution output.
- `preprocessed.i` — GCC preprocessor output.
- `task04_analysis.md` — Detailed explanation, test results, and comparison.

## Environment
- Compiler: GCC 15.2.0 (Ubuntu 15.2.0-16ubuntu1)

## Compilation
`gcc -std=c11 -Wall -Wextra -Wpedantic macro_demo.c -o macro_demo`

## Execution
`./macro_demo`

## Preprocessor
`gcc -E -P macro_demo.c -o preprocessed.i`

## Verified Results
- Rupees to paise: 5000 paise.
- Incorrect square macro: 7.
- Correct square macro: 16.
- MAX(10, 20): 20.
- MAX(i++, j): increments i twice in this test.
- Inline maximum: evaluates each argument once.

## Complexity
The demonstrated arithmetic operations use constant time, O(1), and constant auxiliary space, O(1). Macro expansion can increase generated code size when repeated many times.

## Evidence
Program output and preprocessor expansion are saved in the task folder. Terminal screenshots must be added before final submission.

## Status
Program compiled and executed successfully. Analysis and output files prepared.
