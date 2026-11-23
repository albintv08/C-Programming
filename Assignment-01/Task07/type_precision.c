#include <stdio.h>
#include <math.h>

long calculate_bill(int units)
{
    long bill = 5000L;

    if (units > 200)
        bill += 100L * 225L + (long)(units - 200) * 450L;
    else if (units > 100)
        bill += (long)(units - 100) * 225L;

    return bill;
}

int main(void)
{
    int units = 150;
    long large = 3000000000L;
    double charge = 12.345;
    long rounded = lround(charge * 100.0);

    printf("TASK 07 - TYPE CONVERSION AND PRECISION\n\n");

    printf("1. Integer division: 150 / 100 = %d\n", 150 / 100);
    printf("2. Floating division: 150.0 / 100 = %.2f\n", 150.0 / 100);
    printf("3. Unsigned conversion: (unsigned int)-1 = %u\n",
           (unsigned int)-1);
    printf("4. Integer promotion: (unsigned short)65535 + 1 = %u\n",
           (unsigned int)((unsigned short)65535 + 1));
    printf("5. Large long value: %ld\n", large);
    printf("6. Casting that long to int: %d (implementation-defined)\n",
           (int)large);
    printf("7. Bill for %d units: %ld paise\n",
           units, calculate_bill(units));
    printf("8. Rounding Rs %.3f to nearest paise: %ld paise\n",
           charge, rounded);

    printf("\nFLOAT VERSUS INTEGER-PAISE ACCUMULATION\n");

    int counts[] = {1, 100, 1000, 4000, 10000};

    for (int i = 0; i < 5; i++) {
        int n = counts[i];
        float float_total = 0.0f;
        long integer_total = 0;

        for (int j = 0; j < n; j++) {
            float_total += 162.51f;
            integer_total += 16251L;
        }

        printf("%5d bills: float = Rs %.2f, integer = Rs %ld.%02ld\n",
               n, float_total, integer_total / 100,
               integer_total % 100);
    }

    return 0;
}
