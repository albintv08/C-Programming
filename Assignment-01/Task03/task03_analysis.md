# Task 03 – Define Constants

**Student Name:** Albin T.V.  
**Register Number:** 1924260177  
**Course:** CSA02 – C Programming  
**Assignment:** Assignment 1 – Rural Electricity Billing System

## 1. Objective

The objective is to define tariff limits, energy rates and the fixed charge as symbolic constants. This avoids repeating numerical values throughout the billing program and makes tariff updates easier.

## 2. Constants Used

| Constant | Value | Purpose |
|---|---:|---|
| SLAB1_UNITS | 100 | First slab limit |
| SLAB2_UNITS | 200 | Second slab limit |
| RATE1_PAISE | 0 | Rate for first 100 units |
| RATE2_PAISE | 225 | Rate per unit from 101 to 200 |
| RATE3_PAISE | 450 | Rate per unit above 200 |
| FIXED_CHARGE_PAISE | 5000 | Fixed charge of Rs. 50 |

All monetary calculations are performed in paise using integer arithmetic to avoid floating-point rounding errors.

## 3. Implementation

The program uses `#define` macros to declare the tariff constants. The `compute_bill()` function starts with the fixed charge and calculates the energy charge according to the applicable consumption slabs.

- First 100 units: free.
- Units 101–200: 225 paise per unit.
- Units above 200: 450 paise per unit.

The final amount is returned in paise and displayed in rupees with two decimal places.

## 4. Test Results

| Consumption | Expected bill | Actual bill | Result |
|---:|---:|---:|---|
| 0 units | Rs. 50.00 | Rs. 50.00 | PASS |
| 100 units | Rs. 50.00 | Rs. 50.00 | PASS |
| 150 units | Rs. 162.50 | Rs. 162.50 | PASS |
| 200 units | Rs. 275.00 | Rs. 275.00 | PASS |
| 350 units | Rs. 950.00 | Rs. 950.00 | PASS |

## 5. Tariff Revision Test

The second-slab rate was temporarily changed from 225 paise to 230 paise. The program was recompiled and executed.

| Consumption | Revised bill |
|---:|---:|
| 0 units | Rs. 50.00 |
| 100 units | Rs. 50.00 |
| 150 units | Rs. 165.00 |
| 200 units | Rs. 280.00 |
| 350 units | Rs. 955.00 |

The revised results confirm that changing one constant updates all applicable bills consistently. The original rate of 225 paise was restored after the test.

## 6. Comparison of Constant Definitions

| Method | Characteristics |
|---|---|
| `#define` | Preprocessor substitution; no declared data type; useful for fixed symbolic values |
| `const` | Creates a typed read-only object; supports scope and type checking |
| `enum` | Defines named integer constants; useful for related integral values |

For this task, `#define` is used because the provided program specifically requires macro constants. In larger programs, `const` may offer stronger type checking and scope control.

## 7. Complexity Analysis

The billing function performs a fixed number of comparisons and arithmetic operations, regardless of the number of units.

- Time complexity: O(1)
- Auxiliary space complexity: O(1)

## 8. Conclusion

The program successfully calculates electricity bills using centralized tariff constants. All five standard test cases passed. The tariff revision test also passed, demonstrating that centralized constants make future rate changes simple and consistent.
