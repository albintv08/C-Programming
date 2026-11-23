#include <stdio.h>
#include <limits.h>
#include "billing.h"

int main(void)
{
    unsigned short previous, current;
    unsigned int units;
    long bill;

    printf("RURAL ELECTRICITY BILLING\n");
    printf("Enter previous and current meter readings (0-65535): ");

    if (scanf("%hu %hu", &previous, &current) != 2) {
        printf("Error: Invalid input. Enter numeric meter readings.\n");
        return 1;
    }

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = (unsigned int)(USHRT_MAX - previous) + current + 1U;

    bill = calculate_bill_paise((int)units);

    printf("Previous reading : %hu\n", previous);
    printf("Current reading  : %hu\n", current);
    printf("Units consumed   : %u\n", units);
    printf("Total bill       : Rs. %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
