# Task 07 – Control Type Conversion and Precision

## Objective
Demonstrate C type conversions, integer promotion, division, explicit casting, rounding, and floating-point accumulation error.

## Files
- `type_precision.c` – C program demonstrating conversions and precision.
- `output.txt` – Actual output from the executed program.
- `task07_analysis.md` – Explanation, experiment results, complexity and conclusion.

## Compile and Run
Compile using:
gcc -std=c11 -Wall -Wextra -Wpedantic type_precision.c -lm -o type_precision

Run using:
./type_precision

## Key Findings
- Integer division 150 / 100 produces 1, while floating-point division produces 1.50.
- Converting -1 to unsigned int produces 4294967295 on this platform.
- Narrowing 3000000000L to int is implementation-defined.
- Repeated float accumulation produces increasing differences compared with integer-paise arithmetic.
- Integer paise is recommended for accurate electricity billing.

See task07_analysis.md for the full analysis and output.txt for the actual execution results.
