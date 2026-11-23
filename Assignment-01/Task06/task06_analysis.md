# Task 6 – Formatted Input and Output

## Objective
Demonstrate formatted input/output, input validation, format specifiers and safe line-based input.

## scanf() Implementation
The program uses `%hu` for unsigned short meter readings and checks that scanf returns 2. Invalid input is rejected. `%u` displays unsigned units and `%ld` displays the bill in paise-based rupees.

## Safer Input
The alternative program uses fgets() to read a complete line and strtol() to convert values. It checks conversion errors, range limits and unexpected characters.

## Currency Formatting
The bill is stored in integer paise. Dividing by 100 gives rupees and the remainder gives paise, displayed with `%02ld` to preserve two decimal places.

## Meter Rollover
When the current reading is less than the previous reading, the program calculates rollover using the maximum unsigned-short value. Test 65535 to 0 correctly produces one unit.

## Test Results

| Input | Result |
|---|---|
| 1000 1150 | 150 units; Rs. 162.50 |
| abc 1150 | Rejected as invalid input |
| 65535 0 | 1 unit; Rs. 50.00 |
| Safe input: 1000 1150 | 150 units; Rs. 162.50 |
| Safe input: abc 1150 | Invalid previous reading |

## Format Specifier Note
The correct specifier for unsigned short with scanf is `%hu`; for unsigned int output use `%u`; for long output use `%ld`. A mismatched format specifier can cause undefined behaviour. Never test a mismatched scanf pointer type as if it were safe.

## Complexity
Input parsing and bill calculation take O(1) time and O(1) auxiliary space for fixed-size input.

## Conclusion
The program demonstrates validated formatted input, safe string conversion, meter rollover handling and exact two-decimal currency output.
