#include <stdio.h>

/* Macro definitions */
#define RUPEES_TO_PAISE(rupees) ((long)(rupees) * 100L)
#define BAD_SQUARE(x) x * x
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/* Safer inline function alternatives */
static inline long rupees_to_paise(long rupees)
{
    return rupees * 100L;
}

static inline int square(int x)
{
    return x * x;
}

static inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 3;
    int i = 3;
    int j = 2;

    printf("RUPEES TO PAISE\n");
    printf("Macro: Rs. 50 = %ld paise\n", RUPEES_TO_PAISE(50));
    printf("Inline function: Rs. 50 = %ld paise\n",
           rupees_to_paise(50));

    printf("\nSQUARE MACRO TEST\n");
    printf("Incorrect BAD_SQUARE(a + 1) = %d\n", BAD_SQUARE(a + 1));
    printf("Correct SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("Inline square(a + 1) = %d\n", square(a + 1));

    printf("\nMAX MACRO TEST\n");
    printf("MAX(10, 20) = %d\n", MAX(10, 20));

    printf("\nDOUBLE EVALUATION TEST\n");
    printf("Initial i = 3, j = 2\n");
    printf("MAX(i++, j) = %d\n", MAX(i++, j));
    printf("i after macro call = %d\n", i);

    i = 3;
    printf("Inline maximum(i++, j) = %d\n", maximum(i++, j));
    printf("i after inline call = %d\n", i);

    return 0;
}
