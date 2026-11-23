# Task 12 – Day-4 Design Challenge: Smart Meter Billing

## Objective
Redesign electricity billing for 15-minute smart meter readings, peak-hour pricing and runtime tariff configuration.

## Requirements
- Process 35,040 readings per year.
- Use wider integer types for accumulated energy.
- Apply 20% higher rates between 18:00 and 22:00.
- Change tariffs without recompiling.

## Files
- smart_billing.c – billing implementation.
- tariff.conf – runtime tariff settings.
- normal_tariff_output.txt – original tariff test.
- peak_test_output.txt – modified tariff test.
- annual_capacity_output.txt – annual capacity test.
- task12_analysis.md – detailed analysis and calculations.

## Compile
gcc -Wall -Wextra -Wpedantic -std=c11 smart_billing.c -o smart_billing

## Run
./smart_billing

Keep tariff.conf in the same directory as the executable.

## Test Summary
- Normal and peak billing: PASS – Rs. 54.95.
- Runtime tariff modification: PASS – Rs. 56.60.
- Annual reading capacity: PASS – 35,040 readings.
- Original tariff restored: PASS.

## Conclusion
The implementation demonstrates peak-hour billing, wider integer storage and runtime tariff configuration without recompilation.
