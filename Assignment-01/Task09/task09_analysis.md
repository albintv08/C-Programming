# Task 9 – Implement and Test the Billing Program

## 1. Objective
Implement and test the electricity billing calculation using the tariff structure developed in Task 5. Verify normal bills, boundary values, meter rollover and invalid input.

## 2. Tariff Structure

| Consumption | Charge |
|---|---|
| Fixed charge | Rs. 50.00 |
| First 100 units | Included in fixed charge |
| 101–200 units | Rs. 2.25 per additional unit |
| Above 200 units | Rs. 4.50 per additional unit |

The calculation uses integer paise to avoid floating-point rounding errors.

## 3. Implementation
The test program `billing_test.c` reuses `calculate_bill_paise()` from Task 5. It also includes:
- Meter reading validation using `strtol()`.
- Reading range validation from 0 to 65535.
- Normal consumption calculation.
- Meter rollover detection.
- Rejection of invalid decreases when rollover conditions are not met.
- Expected-versus-actual billing comparisons.

## 4. Billing Test Results

| Test | Units | Expected bill | Actual bill | Result |
|---|---:|---:|---:|---|
| Zero units | 0 | Rs. 50.00 | Rs. 50.00 | PASS |
| Boundary | 100 | Rs. 50.00 | Rs. 50.00 | PASS |
| Middle slab | 150 | Rs. 162.50 | Rs. 162.50 | PASS |
| Boundary | 200 | Rs. 275.00 | Rs. 275.00 | PASS |
| Upper slab | 350 | Rs. 950.00 | Rs. 950.00 | PASS |

All five billing tests passed.

## 5. Meter Rollover Test
Previous reading = 65535  
Current reading = 0

Units consumed = 65535 - 65535 + 1 + 0 = 1 unit.

The resulting bill is Rs. 50.00. The rollover test passed.

## 6. Invalid Input Tests

| Input or condition | Expected behaviour | Actual result |
|---|---|---|
| Letters: abc | Reject | REJECTED |
| Negative reading: -10 | Reject | REJECTED |
| Out of range: 70000 | Reject | REJECTED |
| Invalid decrease: 1200 to 1100 | Reject | REJECTED |

All invalid input tests were rejected.

## 7. Five-Bill Total Verification

The five bills are:

- 0 units = Rs. 50.00
- 100 units = Rs. 50.00
- 150 units = Rs. 162.50
- 200 units = Rs. 275.00
- 350 units = Rs. 950.00

Hand-calculated total:

Rs. 50.00 + Rs. 50.00 + Rs. 162.50 + Rs. 275.00 + Rs. 950.00 = Rs. 1,487.50.

The program calculated Rs. 1,487.50. The total verification passed.

## 8. Complexity Analysis
The billing calculation uses a fixed number of conditional checks, so its time complexity is O(1). It uses a fixed number of variables, so its auxiliary space complexity is O(1).

An alternative implementation could store slab limits and rates in arrays and process them using a loop. That approach has O(s) time complexity for s slabs and O(s) storage. Arrays are easier to extend when many tariff slabs are added, while the fixed conditional approach is simple and efficient for the current three-level tariff.

## 9. Compilation
The program was compiled using:

`gcc -Wall -Wextra -Wpedantic -std=c11 billing_test.c ../Task05/billing.c -I../Task05 -o billing_test`

No compiler warnings were produced.

## 10. Conclusion
The billing program passed all five normal and boundary billing tests. Meter rollover was calculated correctly, invalid readings were rejected, and the five-bill total matched the hand calculation. The implementation uses integer paise for accurate currency calculations.
