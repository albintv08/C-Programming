# Task 11 – Recommend and Defend the Final Design

## Objective
Recommend suitable data types, constants and preprocessor features for the electricity billing system.

## Files
- `task11_analysis.md` – final design recommendation, experimental evidence, limitations and configuration-file alternative.

## Evidence Used
- Task 7: float versus integer-paise accumulation.
- Task 9: billing correctness, meter rollover and invalid-input tests.
- Task 10: type sizes, integer overflow and village/taluk/district total comparisons.

## Recommendation
Use integer paise for money, `long long` for accumulated totals, and a suitable unsigned type for meter readings. Centralise tariff constants. Consider a validated configuration file when tariff changes must not require recompilation.

See `task11_analysis.md` for the full justification.
