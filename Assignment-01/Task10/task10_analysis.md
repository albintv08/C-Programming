# Task 10 – Compare Expectations with Execution

## Objective
Compare floating-point and integer-paise accumulation at village, taluk and district scales. Examine integer ranges, type sizes and the effect of using double.

## 1. Experimental Setup
- Compiler: GCC 15.2.0
- Language standard: C11
- One bill: Rs.162.51 or 16,251 paise
- Bill counts: 4,000, 60,000 and 800,000
- Program: expectation.c
- Actual output: output.txt

Compile and execute:
`gcc -Wall -Wextra -Wpedantic -std=c11 expectation.c -o expectation`
`./expectation`

## 2. Expected Integer Totals

| Bills | Expected total |
|---:|---:|
| 4,000 | Rs.650,040.00 |
| 60,000 | Rs.9,750,600.00 |
| 800,000 | Rs.130,008,000.00 |

The expected total is calculated as number of bills multiplied by 16,251 paise.

## 3. Float, Double and Integer Comparison

| Bills | Float total | Double total | Integer-paise total |
|---:|---:|---:|---:|
| 4,000 | Rs.650,020.12 | Rs.650,040.00 | Rs.650,040.00 |
| 60,000 | Rs.9,754,209.00 | Rs.9,750,600.00 | Rs.9,750,600.00 |
| 800,000 | Rs.129,308,992.00 | Rs.130,008,000.00 | Rs.130,008,000.00 |

The float errors compared with the expected integer total were:
- 4,000 bills: -Rs.19.88
- 60,000 bills: +Rs.3,609.00
- 800,000 bills: -Rs.699,008.00

The repeated float additions accumulate rounding errors. Double produced the same displayed two-decimal totals as integer paise in these tests, because it has greater precision than float. Nevertheless, binary floating-point is not guaranteed to represent every decimal currency amount exactly.

## 4. Integer Overflow Analysis

| Bills | Total in paise | int on this system | long | long long |
|---:|---:|---|---|---|
| 4,000 | 65,004,000 | Fits | Fits | Fits |
| 60,000 | 975,060,000 | Fits | Fits | Fits |
| 800,000 | 13,000,800,000 | Does not fit | Fits | Fits |

On this system, int has a maximum value of 2,147,483,647. The district total of 13,000,800,000 paise exceeds this limit. Both long and long long have a maximum value of 9,223,372,036,854,775,807 on this system and safely hold the tested total.

## 5. Type Sizes and C Standard Guarantees

| Type | Size on this system | Relevant standard minimum |
|---|---:|---|
| int | 4 bytes | At least 16 bits |
| long | 8 bytes | At least 32 bits |
| long long | 8 bytes | At least 64 bits |
| float | 4 bytes | At least 6 decimal digits of precision |
| double | 8 bytes | At least 10 decimal digits of precision |

The measured sizes and ranges are implementation-dependent. The C standard specifies minimum ranges and precision, not that every platform must use the exact sizes observed here.

## 6. Why the Results Differ

Float has limited precision. Repeatedly adding a decimal amount such as Rs.162.51 introduces small binary rounding errors. These errors accumulate over thousands of additions.

Integer paise stores the amount as a whole number, avoiding fractional rounding during accumulation. A long long is large enough for the district-scale total on this system.

Double has substantially more precision than float and matched the integer result when printed to two decimal places in these tests. However, it still uses binary floating-point and should not be treated as an exact currency representation.

## 7. Alternative: Accumulating in Double

At 800,000 bills, double produced Rs.130,008,000.00 when printed to two decimal places, matching the integer-paise total in this experiment.

- Time: O(n) additions for n bills, as with integer accumulation.
- Space: O(1) for one running total.
- Double uses 8 bytes on this system.
- Integer paise with long long is preferable when exact currency arithmetic is required.
- Double is useful for scientific calculations where approximate fractional values are acceptable.

## 8. Conclusion

The experiment confirms that float is unsuitable for accumulating billing totals because its rounding error becomes significant at scale. An int cannot store the district total in paise on this system. The recommended approach is to store money in integer paise and use long long for accumulated totals. This avoids floating-point rounding and provides sufficient range for the tested district workload.
