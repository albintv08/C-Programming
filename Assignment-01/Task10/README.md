# Task 10 – Compare Expectations with Execution

## Objective
Compare float, double and integer-paise totals at 4,000, 60,000 and 800,000 bills, and examine type ranges and overflow.

## Files
- `expectation.c` – measurement program.
- `output.txt` – actual execution results.
- `task10_analysis.md` – comparisons, overflow analysis and conclusion.

## Compile and Run
`gcc -Wall -Wextra -Wpedantic -std=c11 expectation.c -o expectation`

`./expectation`

## Result
Float accumulation showed increasing errors at larger scales. The district total overflowed the int range, while long and long long held it. Double matched the integer total to two decimal places in the tests.

See `task10_analysis.md` for detailed measurements.
