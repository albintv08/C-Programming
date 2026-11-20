# Assignment 1 — Task 1: Understand the Problem and Identify the Data

**Student:** Albin T V  
**Register number:** 1924260177  
**Course:** CSA02 — C Programming  
**Course outcome:** CO1  
**Marks:** 4  
**Bloom's level:** K4 — Analyse

## 1. Problem understanding

Grama Jyothi Rural Electricity Co-operative currently bills about 4,000 households each month. A meter reader records each household's previous and current meter readings. The program calculates the consumed units and the bill. The tariff described in the assignment is:

- First 100 units: free.
- Units 101–200: ₹2.25 per unit.
- Units above 200: ₹4.50 per unit.
- A fixed charge is also added to the energy charge.

The system must avoid negative consumption when a 16-bit meter register rolls over from 65535 to 0. It must also avoid small currency errors and allow the workload to grow from 4,000 households to 60,000 and eventually 800,000 households.

## 2. Input data

| Data item | Meaning | Why it is required |
|---|---|---|
| Household number | Unique identifier for the consumer | Associates each calculated bill with the correct household and helps identify records |
| Previous meter reading | Register value at the start of the billing period | Provides the starting point for calculating consumption |
| Current meter reading | Register value at the end of the billing period | Used with the previous reading to calculate consumption |
| Consumer category | Household/customer classification, if used by the co-operative | Preserves the category information required by the problem; the brief does not specify category-specific tariff rates |

The two readings are register values, not the consumed units themselves. Consumption must be calculated from the pair of readings and must account for the meter's rollover behaviour.

## 3. Computed values and outputs

| Output | Meaning | Purpose |
|---|---|---|
| Units consumed | Difference between current and previous readings, with rollover handled | Determines the energy charge |
| Energy charge | Amount calculated using the three consumption slabs | Represents the variable part of the bill |
| Fixed charge | Fixed amount added to the bill | Represents the non-energy component |
| Total bill | Energy charge + fixed charge | Final amount payable by the household |

The program should display or store the bill against the household number so that the result can be traced to the correct consumer.

## 4. Constants and values that can change

The following tariff rules are fixed during one execution under the original assignment scenario and should be represented as named constants:

- First slab limit: 100 units.
- Second slab limit: 200 units.
- First-slab rate: ₹0 per unit.
- Second-slab rate: ₹2.25 per unit.
- Third-slab rate: ₹4.50 per unit.
- Fixed charge: the assignment's stated fixed charge (Task 3 supplies the concrete value ₹50.00).

The number of households, household number, category, meter readings, consumption, energy charge and total bill vary between records. Tariff values may be revised in a later run, but they should not be duplicated as unexplained numeric literals throughout the program.

## 5. Values that may be negative, fractional or large

- **Negative values:** A valid bill total and valid consumption must not be negative. A current reading lower than the previous reading can occur when the meter register rolls over; it must not automatically be treated as negative consumption. Invalid input values, such as a negative meter reading, should be rejected.
- **Fractional values:** The tariff of ₹2.25 per unit contains a fractional rupee amount. The bill must be accurate to the paisa. Storing currency as an integer number of paise avoids binary floating-point representation errors in monetary arithmetic.
- **Large values:** The household count may grow to 800,000. The aggregate amount for all households can therefore be much larger than an individual bill. The design must choose types based on the maximum possible values and check aggregate totals for overflow.

## 6. Rules and correctness conditions

1. Consumption must correctly account for the 16-bit meter register rolling over from 65535 to 0.
2. The first 100 units are charged at the first-slab rate (free in the stated tariff).
3. Units from 101 through 200 are charged at ₹2.25 per unit.
4. Units above 200 are charged at ₹4.50 per unit.
5. The fixed charge must be added to the energy charge.
6. The total bill must equal the energy charge plus the fixed charge.
7. A valid bill must never be negative.
8. Currency calculations must preserve paisa accuracy; avoid accumulating approximate floating-point rupee values.
9. Input must be validated so that non-numeric input and invalid meter readings do not silently produce a bill.
10. The same tariff definition must be used consistently for every household in a run.

## 7. Assumptions

- Each household has one meter reading pair for the billing period in the original design.
- The original meter is a 16-bit register with values from 0 through 65535, as stated in the assignment.
- The assignment's tariff slabs apply uniformly to the households unless a later requirement explicitly defines category-specific rates.
- Task 3 gives the fixed charge as ₹50.00; this value is used when implementing the tariff calculation.
- A lower current reading is treated as a rollover only when it is consistent with the specified register behaviour. The program should validate inputs rather than accept arbitrary negative readings.
- The original billing period uses whole consumed units. The later smart-meter redesign in Task 12 changes the measurement to watt-hours and must be analysed separately.

## 8. Alternative concept: store meter readings as text

A reading could be kept as a character string such as `"01530"` rather than as an integer.

| Aspect | Integer representation | Text representation |
|---|---|---|
| Example | `1530` | `"01530"` |
| Storage | Uses the integer type's fixed number of bytes | Uses one character per digit plus the terminating null character `\\0` |
| Arithmetic | Can be used directly in numeric calculations | Must first be parsed or converted to an integer |
| Leading zeroes | Not preserved as formatting | Preserved |
| Validation | Check the numeric range and input conversion | Check each character is a digit, then check the converted range |

Let **d** be the number of decimal digits in a reading. Scanning and converting a text reading takes **O(d)** time. Comparing two already parsed integer readings takes **O(1)** time. Comparing text strings can take up to **O(d)** time. A text buffer requires **O(d)** space for the digits and the null terminator; an integer uses the fixed storage size of its selected type.

For repeated billing arithmetic, integer readings are the more direct representation. Text input may still be useful at the input boundary when preserving leading zeroes or validating the exact entered characters is important; it should be converted and validated before numeric calculations.

## 9. Conclusion

The billing program needs household identification, a category, two meter readings and calculated consumption and bill components. The main design risks are meter rollover, currency precision, invalid input and growth in the number of households. Named tariff constants, validated readings, integer paise calculations and sufficiently wide aggregate types provide a sound basis for the later implementation tasks.

## 10. Execution evidence

Task 1 is an analysis task and does not prescribe a standalone C program. Add any supporting diagrams or test evidence required by the instructor here. Compiler details for the assignment environment: GCC 15.2.0 on Ubuntu (reported by the student on 20 November 2026).
