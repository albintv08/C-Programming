#include <stdio.h>
#include "billing.h"

long calculate_bill_paise(int units)
{
    long bill = FIXED_CHARGE_PAISE;

    if (units < 0)
        return -1;

    if (units > SLAB2_UNITS) {
        bill += (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
        bill += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
    } else if (units > SLAB1_UNITS) {
        bill += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }

    return bill;
}

void print_debug_info(int units, long bill_paise)
{
#ifdef DEBUG
    printf("[DEBUG] Units: %d, Bill: %ld paise\n", units, bill_paise);
#else
    (void)units;
    (void)bill_paise;
#endif
}
