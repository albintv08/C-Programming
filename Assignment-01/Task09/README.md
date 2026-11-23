# Task 9 – Implement and Test the Billing Program

## Objective
Implement and test electricity billing, tariff boundaries, meter rollover and invalid input.

## Files
- `billing_test.c` – billing test program and input validation.
- `output.txt` – actual program output.
- `task09_analysis.md` – test table, hand calculation and complexity analysis.

## Reused Implementation
- `../Task05/billing.h`
- `../Task05/billing.c`

## Compile and Run
Compile:
`gcc -Wall -Wextra -Wpedantic -std=c11 billing_test.c ../Task05/billing.c -I../Task05 -o billing_test`

Execute:
`./billing_test`

## Test Summary
- Five billing tests: PASS.
- Meter rollover: PASS.
- Invalid input rejection: PASS.
- Five-bill total: Rs. 1,487.50 – PASS.

See `task09_analysis.md` for detailed results.
