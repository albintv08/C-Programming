# Task 11 – Recommend and Defend the Final Design

## Objective
Recommend suitable C data types, constants and preprocessor features for the Grama Jyothi electricity billing system, using evidence from Tasks 1–10.

## 1. Recommended Data Types

| Data item | Recommended type | Reason |
|---|---|---|
| Meter reading | `meter_t` (`unsigned short`) | Represents the 16-bit meter register from 0 to 65535 on the tested system. |
| Units consumed | `unsigned int` | Stores non-negative consumption values. |
| Individual bill in paise | `long` | Stores the individual bill without using floating-point currency. |
| District accumulated bill in paise | `long long` | Provides a wide integer range for large totals. |
| Tariff rates | `long` integer paise values | Avoids fractional currency calculations. |
| Household count/index | `unsigned int` or `size_t` | Represents non-negative counts and array sizes. |
| Debug status | `int` | Suitable for simple status values. |

Money should be stored as integer paise rather than float rupees. This prevents fractional rounding errors during billing and accumulation.

## 2. Evidence from Experiments

Task 7 demonstrated that repeated float accumulation can differ from integer-paise accumulation. In the 10,000-bill test, the float result was Rs.1,625,020.12 while the integer-paise result was Rs.1,625,100.00.

Task 10 measured the following district-scale result:

- Number of bills: 800,000
- One bill: 16,251 paise
- District total: 13,000,800,000 paise
- Equivalent total: Rs.130,008,000.00

The total exceeds the maximum `int` value on the tested system (2,147,483,647). It fits in both `long` and `long long` on this 64-bit system. I recommend `long long` for accumulated totals because the C standard guarantees at least a 64-bit range for this type.

Task 10 also showed that float accumulation differed from the integer result by Rs.699,008.00 at 800,000 bills. Double matched the integer total to two decimal places in the experiment, but integer paise remains preferable for exact currency calculations.

## 3. Tariff Revision Strategy

In the current design, tariff values are centralised as named constants in `billing.h`. This avoids typing rates in multiple locations and makes the program easier to maintain.

For a tariff revision:
1. Update the central tariff definitions.
2. Recompile the program.
3. Test the boundary values and representative bills again.
4. Deploy the tested executable.

If tariff values change frequently or must be changed by office staff, a configuration file is preferable. The program can read and validate tariff values at startup without recompilation.

## 4. Preprocessor Features

The recommended preprocessor features are:

- `#define` for named tariff constants and fixed limits.
- Include guards (`#ifndef`, `#define`, `#endif`) to prevent repeated header inclusion.
- `#include` to share declarations between source files.
- `#ifdef DEBUG` for optional debugging output.

Macros should be used for simple constants rather than complex expressions with side effects. Inline functions are safer for operations that require evaluation.

## 5. Limitations

- The `unsigned short` meter representation assumes the specified 16-bit meter register. The program should validate this assumption on the target platform.
- The current tariff constants require recompilation after a rate change.
- The program must reject invalid readings and handle meter rollover correctly.
- A 64-bit integer is sufficient for the tested district total, but future growth should be checked against the maximum possible accumulated value.
- Floating-point output should not be used as the authoritative stored currency value.

## 6. Alternative: Read Tariffs from a Configuration File

An alternative is to store the fixed charge, slab limits and rates in a configuration file and read them when the program starts.

For t tariff values:
- Reading and validating the configuration takes O(t) time.
- Storing the tariff values requires O(t) space.
- Each bill can then use the loaded tariff values.
- A tariff revision only requires updating the configuration file, rather than recompiling and redistributing the program.

This approach adds file handling, parsing and validation. A missing, malformed or invalid configuration file must be detected safely. For a small fixed tariff, compile-time constants are simpler; for frequent revisions, runtime configuration is more flexible.

## 7. Final Recommendation

The final design should use integer paise for all money calculations, `long long` for accumulated totals, and an appropriate unsigned type for meter readings and consumption. Tariff definitions should remain centralised in a header for the current fixed-rate implementation. If the co-operative needs frequent tariff changes without software deployment, tariff values should move to a validated configuration file.

The Task 10 experiment confirms that the recommended integer representation and wide accumulator can handle the tested district workload. Therefore, the design remains correct at the tested scale on the current 64-bit system.
