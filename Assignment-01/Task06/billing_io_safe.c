#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "billing.h"

int main(void)
{
    char line[100];
    char *end;
    long previous, current;
    unsigned int units;
    long bill;

    printf("Enter previous and current readings: ");
    if (fgets(line, sizeof line, stdin) == NULL) {
        puts("Input error");
        return 1;
    }

    errno = 0;
    previous = strtol(line, &end, 10);
    if (end == line || errno == ERANGE || previous < 0 || previous > USHRT_MAX) {
        puts("Invalid previous reading");
        return 1;
    }

    while (isspace((unsigned char)*end)) end++;

    errno = 0;
    current = strtol(end, &end, 10);
    if (errno == ERANGE || current < 0 || current > USHRT_MAX) {
        puts("Invalid current reading");
        return 1;
    }

    while (isspace((unsigned char)*end)) end++;
    if (*end != 0) {
        puts("Unexpected extra input");
        return 1;
    }

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = (unsigned int)(USHRT_MAX - previous) + (unsigned int)current + 1U;

    bill = calculate_bill_paise((int)units);
    printf("Units consumed: %u\n", units);
    printf("Total bill: Rs. %ld.%02ld\n", bill / 100, bill % 100);
    return 0;
}
