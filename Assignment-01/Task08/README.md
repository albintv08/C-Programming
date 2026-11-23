# Task 8 – Trace the Compilation Process

## Objective
Demonstrate the stages of C compilation using GCC and classify compile-time, link-time and runtime errors.

## Source Program
The billing program from Task 5 was used:
- `../Task05/main.c`
- `../Task05/billing.c`
- `../Task05/billing.h`

## Compilation Evidence
| Stage | Output |
|---|---|
| Preprocessing | main.i |
| Assembly generation | main.s |
| Object files | main.o, billing.o |
| Linking | billing_program |

## Error Evidence
- `compile_error.txt` – compile-time undeclared variable error.
- `link_error.txt` – link-time undefined reference error.
- `runtime_error.txt` – invalid input rejected during execution.

## Program Output
See `output.txt` for the successful billing results.

## Detailed Explanation
See `task08_analysis.md`.

## Environment
- OS: Ubuntu on WSL
- Compiler: GCC
- Compilation flags: `-Wall -Wextra -Wpedantic -std=c11`
- stage_evidence.txt – generated file types and sizes for each compilation stage.
