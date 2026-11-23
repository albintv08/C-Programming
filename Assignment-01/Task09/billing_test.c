#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "billing.h"

#define METER_MAX 65535L

int parse_reading(const char *text, long *value)
{
    char *end;
    long n;

    errno = 0;
    n = strtol(text, &end, 10);

    if (text == end || errno == ERANGE || n < 0 || n > METER_MAX)
        return 0;

    while (isspace((unsigned char)*end))
        end++;

    if (*end != '\0')
        return 0;

    *value = n;
    return 1;
}

int calculate_units(long previous, long current, int *units)
{
    if (previous < 0 || previous > METER_MAX ||
        current < 0 || current > METER_MAX)
        return 0;

    if (current >= previous) {
        *units = (int)(current - previous);
        return 1;
    }

    if (previous >= 65000 && current <= 1000) {
        *units = (int)(METER_MAX - previous + 1 + current);
        return 1;
    }

    return 0;
}

int main(void)
{
    struct Test {
        const char *name;
        int units;
        long expected;
    };

    struct Test tests[] = {
        {"Zero units", 0, 5000},
        {"100 units", 100, 5000},
        {"150 units", 150, 16250},
        {"200 units", 200, 27500},
        {"350 units", 350, 95000}
    };

    int count = (int)(sizeof(tests) / sizeof(tests[0]));
    int passed = 0;
    long total = 0;

    printf("TASK 9 - BILLING TEST RESULTS\n");
    printf("%-18s %-10s %-15s %-15s %s\n",
           "Test", "Units", "Expected", "Actual", "Result");

    for (int i = 0; i < count; i++) {
        long actual = calculate_bill_paise(tests[i].units);
        int ok = actual == tests[i].expected;

        printf("%-18s %-10d Rs.%7.2f    Rs.%7.2f    %s\n",
               tests[i].name, tests[i].units,
               tests[i].expected / 100.0,
               actual / 100.0, ok ? "PASS" : "FAIL");

        if (ok)
            passed++;

        total += actual;
    }

    printf("\nFive-bill total: Rs.%.2f\n", total / 100.0);
    printf("Expected total : Rs.1487.50\n");
    printf("Total check    : %s\n",
           total == 148750 ? "PASS" : "FAIL");

    printf("\nMETER ROLLOVER TEST\n");
    int units;
    if (calculate_units(65535, 0, &units))
        printf("65535 -> 0: %d unit(s), bill Rs.%.2f\n",
               units, calculate_bill_paise(units) / 100.0);

    printf("\nINPUT VALIDATION TESTS\n");
    long reading;
    printf("Letters (abc): %s\n",
           parse_reading("abc", &reading) ? "ACCEPTED" : "REJECTED");
    printf("Negative (-10): %s\n",
           parse_reading("-10", &reading) ? "ACCEPTED" : "REJECTED");
    printf("Out of range (70000): %s\n",
           parse_reading("70000", &reading) ? "ACCEPTED" : "REJECTED");

    printf("Invalid decrease (1200 -> 1100): %s\n",
           calculate_units(1200, 1100, &units) ? "ACCEPTED" : "REJECTED");

    printf("\nBilling tests passed: %d/%d\n", passed, count);
    return (passed == count && total == 148750) ? 0 : 1;
}
