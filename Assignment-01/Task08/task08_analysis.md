# Task 8 – Trace the Compilation Process

## 1. Objective
To understand the stages involved in converting C source code into an executable program using GCC.

## 2. Compilation Stages

The Task 5 billing program was used to demonstrate the four stages.

| Stage | GCC command | Generated file | Purpose |
|---|---|---|---|
| Preprocessing | gcc -E | main.i | Expands header files and macros |
| Compilation | gcc -S | main.s | Converts C code into assembly |
| Assembly | gcc -c | main.o, billing.o | Generates relocatable object files |
| Linking | gcc main.o billing.o -o billing_program | billing_program | Combines object files into an executable |

## 3. Preprocessor Operations
The preprocessor processes directives before compilation:
- Expands #include directives by inserting header contents.
- Replaces macros with their defined values.
- Processes conditional compilation directives.
- Removes comments from the processed source.

The generated main.i file was approximately 22 KB.

## 4. Output of Each Stage
- main.i: Preprocessed C source code.
- main.s: Assembly language source, approximately 2.1 KB.
- main.o: Relocatable x86-64 object file, approximately 2.2 KB.
- billing.o: Relocatable x86-64 object file, approximately 1.5 KB.
- billing_program: Linked executable, approximately 16 KB.

The executable produced the expected billing results for 0, 100, 150, 200 and 350 units.

## 5. Error Classification

### Compile-time error
An intentional undeclared variable named missing_variable was used in compile_error_demo.c. GCC reported that it was undeclared. The error was detected while compiling the source file.

### Link-time error
The command `gcc main.o -o missing_billing` intentionally omitted billing.o. The linker reported undefined references to calculate_bill_paise and print_debug_info because their implementations were missing.

### Runtime input error
The safe input program from Task 6 was executed with invalid inputs:
- `abc 1150`
- `-10 100`

Both were rejected with the message "Invalid previous reading". These are handled runtime validation errors, not program crashes.

## 6. Compiler Warnings
The source files were compiled using:
`-Wall -Wextra -Wpedantic -std=c11`

No warnings were produced during the successful compilation of main.c and billing.c. These options enable additional compiler diagnostics and help detect potential programming mistakes.

## 7. Separate Compilation
The billing application uses two source files:
- main.c contains the main function and billing report.
- billing.c contains the billing function implementations.
- billing.h provides shared declarations.

Each source file was compiled separately into an object file and then linked.

If only billing.c changes, only billing.o needs recompilation before relinking. A change to a shared header may require recompiling all source files that depend on it.

Separate compilation improves modularity and avoids recompiling unchanged source files. However, object files require additional storage.

## 8. Conclusion
The experiment successfully demonstrated preprocessing, assembly generation, object-file creation and linking. It also distinguished compile-time, link-time and runtime input errors. The multi-file billing program was compiled and executed successfully.
