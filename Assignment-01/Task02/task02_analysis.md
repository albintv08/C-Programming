# Assignment 1 — Task 2: Choose the Data Types

**Student:** Albin T V  
**Register Number:** 1924260177  
**Course:** CSA02 — C Programming  
**CO:** CO1  
**Marks:** 4

## 1. Data type selection

| Data item | Selected type | Justification |
|---|---|---|
| Meter reading | unsigned short | Represents the 16-bit meter register |
| Consumption | unsigned int | Stores calculated units |
| Household number | unsigned int | Supports a large number of household identifiers |
| Individual bill | long | Stores monetary values as integer paise |
| District total | long long | Provides a wider range for accumulated bills |
| Category | char or enum | Represents a small category code |
| Text input | char array | Stores names and other textual information |

## 2. Type sizes and ranges

The program uses sizeof, limits.h and float.h to display the
sizes and limits reported by the Ubuntu GCC environment.

The observed sizes are:

| Type | Size |
|---|---:|
| char | 1 byte |
| short | 2 bytes |
| int | 4 bytes |
| long | 8 bytes |
| long long | 8 bytes |
| float | 4 bytes |
| double | 8 bytes |
| meter_t | 2 bytes |

The exact ranges are recorded in output.txt.

## 3. Meter rollover

The meter register is an unsigned 16-bit counter. Its values range
from 0 to 65535. After 65535, it returns to 0.

The program uses unsigned 16-bit arithmetic to calculate consumption
without an if-else statement.

Test 1:
Previous reading = 1200
Current reading = 1530
Consumption = 330 units

Test 2:
Previous reading = 65400
Current reading = 120
Consumption = 256 units

The second result is positive because the register wraps around
modulo 65536.

## 4. Floating-point precision versus integer paise

The program adds 4000 values of 0.01 rupees using float.

Observed float total = 39.999294281 rupees.

The same amounts are added as integer paise:

4000 bills × 1 paisa = 4000 paise = Rs 40.00.

The floating-point result is approximate because 0.01 cannot be
represented exactly in binary floating-point. Integer paise gives
an exact result for these monetary values.

## 5. Alternative: double rupees

An alternative is to store each bill as double rupees. This offers
more precision than float, but decimal currency values may still
be approximated in binary. Rounding would be required when
converting the calculated amount to paise or displaying the bill.

Both approaches require O(1) time per addition. A double uses
more storage than a typical integer paise value on this system.
Integer paise is preferable when the currency precision is exactly
one paisa and calculations must remain exact.

For n bills, summation takes O(n) time. The total uses O(1)
additional space when bills are processed one at a time.

## 6. Conclusion

The tests confirm that unsigned short is suitable for the
16-bit meter register on this system. Integer paise avoids the
observed floating-point accumulation error. A wider integer type
such as long long is appropriate for large district-level totals,
provided the maximum possible total is checked.

## 7. Execution evidence

- Source file: meter_types.c
- Output file: output.txt
- Compiler: GCC 15.2.0
- Compile command:
  gcc -std=c11 -Wall -Wextra -Wpedantic meter_types.c -o meter_types
- Run command:
  ./meter_types
