# Task 7 – Control Type Conversion and Precision

## Objective
To identify type conversions in C, demonstrate integer division, integer promotion, unsigned conversion, explicit casting and rounding, and compare floating-point accumulation with integer-paise calculations.

## 1. Type Conversion Demonstrations

The program produced the following results:

| Expression | Result | Explanation |
|---|---:|---|
| `150 / 100` | 1 | Both operands are integers, so fractional parts are discarded. |
| `150.0 / 100` | 1.50 | The floating-point operand causes floating-point division. |
| `(unsigned int)-1` | 4294967295 | Conversion to a 32-bit unsigned integer wraps modulo 2^32. |
| `(unsigned short)65535 + 1` | 65536 | The unsigned short is promoted to int before addition on this system. |
| `(int)3000000000L` | -1294967296 | The value is outside the range of a 32-bit int; the result is implementation-defined. |

### Unexpected results

1. Integer division: `150 / 100` produces 1 rather than 1.5. Use floating-point arithmetic when a fractional result is required.
2. Unsigned conversion: converting -1 to unsigned int produces 4294967295 on this system because unsigned conversion is modulo 2^32.
3. Large integer cast: converting 3000000000L to int produces -1294967296 on this GCC platform. Such a conversion is implementation-defined and should be avoided when the value may exceed the int range.

### Integer promotion and usual arithmetic conversions

In `(unsigned short)65535 + 1`, the unsigned short operand is promoted to int because this platform's int can represent every unsigned short value. The addition therefore produces 65536 rather than wrapping at 65535.

In billing calculations, the program explicitly converts the unit difference to long before multiplication. This helps ensure that intermediate calculations use a wider integer type.

## 2. Rounding Fractional Charges

The program uses `lround(charge * 100.0)` to convert a charge in rupees to paise. The demonstrated value Rs. 12.345 becomes 1235 paise.

`lround()` rounds to the nearest integer, with halfway cases rounded away from zero. A consistent rounding rule is important when converting fractional currency values to paise.

## 3. Billing Calculation

For 150 units, the program calculates:

- Fixed charge: 5000 paise
- First 100 units: 0 paise
- Next 50 units: 50 × 225 = 11250 paise
- Total: 16250 paise = Rs. 162.50

The billing function uses integer arithmetic to avoid floating-point accumulation in the final bill.

## 4. Floating-Point Versus Integer-Paise Experiment

The program repeatedly adds Rs. 162.51 using float and 16251 paise using long integer arithmetic.

| Number of bills | Float total | Integer-paise total | Difference |
|---:|---:|---:|---:|
| 1 | Rs. 162.51 | Rs. 162.51 | Rs. 0.00 |
| 100 | Rs. 16250.98 | Rs. 16251.00 | Rs. 0.02 |
| 1000 | Rs. 162510.52 | Rs. 162510.00 | Rs. 0.52 |
| 4000 | Rs. 650020.12 | Rs. 650040.00 | Rs. 19.88 |
| 10000 | Rs. 1625020.12 | Rs. 1625100.00 | Rs. 79.88 |

The experiment shows that repeated floating-point additions can accumulate rounding error. The error increases as the number of bills increases. Integer paise gives the exact expected total for these values, provided the chosen integer type does not overflow.

## 5. Time and Space Complexity

Each bill calculation and each accumulation operation takes O(1) time. Processing n bills takes O(n) time for either approach.

A float typically occupies 4 bytes, while long occupies 8 bytes on this 64-bit Linux environment. The integer approach may therefore use more storage per value, but it provides exact paise arithmetic within the integer type's range.

## 6. Conclusion

C performs implicit conversions according to integer promotion and the usual arithmetic conversion rules. Integer division can discard fractions, unsigned conversion changes negative values, and narrowing a large long to int can produce implementation-dependent results.

For electricity billing, storing monetary values as integer paise is recommended. It avoids cumulative floating-point rounding errors and provides predictable results when suitable integer ranges are used.

## Environment and Execution

- Operating system: Ubuntu on WSL
- Compiler: GCC 15.2.0
- Compile command: `gcc -std=c11 -Wall -Wextra -Wpedantic type_precision.c -lm -o type_precision`
- Run command: `./type_precision`
- Actual execution output: `output.txt`
