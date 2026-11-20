#include <stdio.h>
#include <limits.h>
#include <float.h>

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (unsigned int)(meter_t)(current - previous);
}

int main(void)
{
    printf("DATA TYPE SIZES\n");
    printf("char       = %zu byte(s)\n", sizeof(char));
    printf("short      = %zu byte(s)\n", sizeof(short));
    printf("int        = %zu byte(s)\n", sizeof(int));
    printf("long       = %zu byte(s)\n", sizeof(long));
    printf("long long  = %zu byte(s)\n", sizeof(long long));
    printf("float      = %zu byte(s)\n", sizeof(float));
    printf("double     = %zu byte(s)\n", sizeof(double));
    printf("meter_t    = %zu byte(s)\n", sizeof(meter_t));

        printf("\nFLOATING POINT RANGES\n");
    printf("float  = approximately %e to %e\n",
           (double)-FLT_MAX, (double)FLT_MAX);
    printf("double = approximately %e to %e\n",
           -DBL_MAX, DBL_MAX);
    printf("FLT_MIN     = %e\n", (double)FLT_MIN);
    printf("DBL_MIN     = %e\n", DBL_MIN);
    printf("FLT_EPSILON = %e\n", (double)FLT_EPSILON);

    printf("\nFLOATING POINT LIMITS\n");
    printf("FLT_MAX     = %e\n", (double)FLT_MAX);
    printf("DBL_MAX     = %e\n", DBL_MAX);
    printf("FLT_EPSILON = %e\n", (double)FLT_EPSILON);

    printf("\nMETER ROLLOVER TEST\n");
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));

    printf("\nCURRENCY PRECISION TEST (4000 BILLS)\n");

    float float_total = 0.0f;
    long long paise_total = 0;

    for (int i = 0; i < 4000; i++) {
        float_total += 0.01f;
        paise_total += 1;
    }

    printf("Float total       = %.9f rupees\n", (double)float_total);
    printf("Integer paise     = %lld paise\n", paise_total);
    printf("Integer total     = %lld.%02lld rupees\n",
           paise_total / 100, paise_total % 100);

    return 0;
}
