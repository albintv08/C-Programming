#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

#define BILL_PAISE 16251L

int main(void)
{
    int counts[] = {4000, 60000, 800000};
    int n = 3;

    printf("TASK 10 - EXPECTATION VS EXECUTION\n");
    printf("One bill = Rs.162.51 (16251 paise)\n\n");

    printf("TYPE INFORMATION\n");
    printf("sizeof(int)       = %zu bytes, range = %d to %d\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("sizeof(long)      = %zu bytes, range = %ld to %ld\n",
           sizeof(long), LONG_MIN, LONG_MAX);
    printf("sizeof(long long) = %zu bytes, range = %lld to %lld\n",
           sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("sizeof(float)     = %zu bytes, FLT_DIG = %d\n",
           sizeof(float), FLT_DIG);
    printf("sizeof(double)    = %zu bytes, DBL_DIG = %d\n\n",
           sizeof(double), DBL_DIG);

    printf("C STANDARD MINIMUM GUARANTEES\n");
    printf("int: at least 16 bits\n");
    printf("long: at least 32 bits\n");
    printf("long long: at least 64 bits\n");
    printf("float: at least 6 decimal digits of precision\n");
    printf("double: at least 10 decimal digits of precision\n\n");

    printf("TOTAL COMPARISON\n");

    for (int i = 0; i < n; i++) {
        int bills = counts[i];
        float float_total = 0.0f;
        double double_total = 0.0;
        long long paise_total = 0;

        for (int j = 0; j < bills; j++) {
            float_total += 162.51f;
            double_total += 162.51;
            paise_total += BILL_PAISE;
        }

        printf("\nBills: %d\n", bills);
        printf("Float total       = Rs.%.2f\n", float_total);
        printf("Integer paise     = Rs.%lld.%02lld\n",
               paise_total / 100, paise_total % 100);
        printf("Double total      = Rs.%.2f\n", double_total);
        printf("Difference        = Rs.%.2f\n",
               (double)float_total - (double)paise_total / 100.0);

        printf("int total paise   = ");
        if ((long long)bills * BILL_PAISE > INT_MAX)
            printf("OVERFLOW (not representable)\n");
        else
            printf("%d\n", (int)((long long)bills * BILL_PAISE));

        printf("long total paise  = ");
        if ((long long)bills * BILL_PAISE > LONG_MAX)
            printf("OVERFLOW (not representable)\n");
        else
            printf("%ld\n", (long)((long long)bills * BILL_PAISE));

        printf("long long paise   = %lld\n", paise_total);
    }

    printf("\nFLOATING-POINT INFORMATION\n");
    printf("FLT_EPSILON = %.10g\n", FLT_EPSILON);
    printf("DBL_EPSILON = %.10g\n", DBL_EPSILON);

    return 0;
}
