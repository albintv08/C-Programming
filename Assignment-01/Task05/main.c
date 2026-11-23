#include <stdio.h>
#include "billing.h"

int main(void)
{
    int readings[] = {0, 100, 150, 200, 350};
    int count = (int)(sizeof(readings) / sizeof(readings[0]));

    printf("RURAL ELECTRICITY BILL\n");

    for (int i = 0; i < count; i++) {
        long bill = calculate_bill_paise(readings[i]);

        if (bill < 0) {
            printf("Invalid units\n");
            continue;
        }

        printf("%3d units -> Rs. %ld.%02ld\n",
               readings[i], bill / 100, bill % 100);

        print_debug_info(readings[i], bill);
    }

    return 0;
}
