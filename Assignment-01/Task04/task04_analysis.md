# Task 4 – Use Macros Safely

**Course:** CSA02 – C Programming  
**Assignment:** 1  
**Student:** Albin T.V.  
**Register Number:** 1924260177

## 1. Objective

To demonstrate C preprocessor macros for repeated calculations and understand their advantages, limitations, and possible errors. The program also compares macros with static inline functions.

## 2. Macro Definitions

- RUPEES_TO_PAISE(rupees): converts rupees into paise.
- BAD_SQUARE(x): demonstrates an incorrectly written macro.
- SQUARE(x): correctly calculates the square using parentheses.
- MAX(a,b): returns the larger argument.

## 3. Importance of Parentheses

BAD_SQUARE(a + 1) expands to a + 1 * a + 1. For a = 3, it produces 7 instead of 16 because multiplication has higher precedence than addition.

SQUARE(a + 1) expands to ((a + 1) * (a + 1)) and correctly produces 16.

## 4. Double Evaluation Problem

MAX(a,b) is defined as (((a) > (b)) ? (a) : (b)). When MAX(i++,j) is used, i++ can be evaluated twice. In the experiment, i changes from 3 to 5.

Expressions with increment or decrement operators should be avoided as macro arguments.

## 5. Preprocessor Expansion

Command used: gcc -E -P macro_demo.c -o preprocessed.i

The -E option runs the preprocessor, and -P suppresses line markers.

Observed expansions:
- Rupees conversion: ((long)(50) * 100L)
- Incorrect square: a + 1 * a + 1
- Correct square: ((a + 1) * (a + 1))
- MAX with increment: (((i++) > (j)) ? (i++) : (j))

## 6. Macro and Static Inline Function Comparison

| Feature | Macro | Static inline function |
|---|---|---|
| Processing | Preprocessor substitution | Compiler function processing |
| Type checking | Limited | Normal C type checking |
| Argument evaluation | May happen multiple times | Each argument evaluated once |
| Function call overhead | No function call | May be eliminated by compiler |
| Debugging | More difficult | Easier |
| Code size | Expansion may be repeated | Compiler can reuse or inline code |

Macros may increase code size when expanded repeatedly. Inline functions can avoid repeated source expansion, although the compiler decides whether to inline them.

## 7. Output and Testing

The program was compiled using gcc -std=c11 -Wall -Wextra -Wpedantic macro_demo.c -o macro_demo and executed successfully.

| Test | Result |
|---|---:|
| Rs. 50 converted to paise | 5000 |
| Incorrect square of (3 + 1) | 7 |
| Correct square of (3 + 1) | 16 |
| MAX(10, 20) | 20 |
| MAX(i++, j) | 4 |
| i after MAX macro | 5 |
| Inline maximum(i++, j) | 3 |
| i after inline function | 4 |

## 8. Conclusion

Macros are useful for small repeated calculations, but they must be written with proper parentheses. Macro arguments containing side effects can be evaluated more than once. Static inline functions provide better type checking and safer argument evaluation. GCC preprocessor output confirms how macro substitution takes place before compilation.
