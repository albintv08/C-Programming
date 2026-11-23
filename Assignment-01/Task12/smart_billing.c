#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE 128

typedef struct {
    long long fixed_charge;
    long long normal_rate;
    int peak_percent;
    int peak_start;
    int peak_end;
} Tariff;

int load_tariff(const char *filename, Tariff *t)
{
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE];

    if (fp == NULL)
        return 0;

    while (fgets(line, sizeof(line), fp)) {
        long long value;

        if (line[0] == '#' || line[0] == '\n')
            continue;

        if (sscanf(line, "FIXED_CHARGE_PAISE=%lld", &value) == 1)
            t->fixed_charge = value;
        else if (sscanf(line, "NORMAL_RATE_PAISE_PER_KWH=%lld", &value) == 1)
            t->normal_rate = value;
        else if (sscanf(line, "PEAK_RATE_PERCENT=%lld", &value) == 1)
            t->peak_percent = (int)value;
        else if (sscanf(line, "PEAK_START_HOUR=%lld", &value) == 1)
            t->peak_start = (int)value;
        else if (sscanf(line, "PEAK_END_HOUR=%lld", &value) == 1)
            t->peak_end = (int)value;
        else {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);

    return t->fixed_charge >= 0 &&
           t->normal_rate > 0 &&
           t->peak_percent >= 100 &&
           t->peak_start >= 0 && t->peak_start <= 23 &&
           t->peak_end >= 1 && t->peak_end <= 24 &&
           t->peak_start < t->peak_end;
}

int main(void)
{
    Tariff tariff = {0};
    long long total_wh = 0;
    long long peak_wh = 0;
    long long normal_wh;
    long long normal_cost;
    long long peak_cost;
    long long total_bill;
    int hour;
    long long wh;
    int count = 0;

    printf("SMART METER BILLING SYSTEM\n");

    if (!load_tariff("tariff.conf", &tariff)) {
        printf("Error: Invalid or missing tariff configuration.\n");
        return 1;
    }

    printf("Tariff configuration loaded successfully.\n");
    printf("Normal rate: %lld paise/kWh\n", tariff.normal_rate);
    printf("Peak rate: %d%% of normal rate\n", tariff.peak_percent);
    printf("Peak period: %02d:00 to %02d:00\n\n",
           tariff.peak_start, tariff.peak_end);

    printf("Enter number of readings (maximum 35040): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 35040) {
        printf("Error: Invalid reading count.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter hour (0-23) and energy (Wh) for reading %d: ", i + 1);

        if (scanf("%d %lld", &hour, &wh) != 2 ||
            hour < 0 || hour > 23 || wh < 0 ||
            total_wh > LLONG_MAX - wh) {
            printf("Error: Invalid reading.\n");
            return 1;
        }

        total_wh += wh;

        if (hour >= tariff.peak_start && hour < tariff.peak_end)
            peak_wh += wh;
    }

    normal_wh = total_wh - peak_wh;

    normal_cost = normal_wh * tariff.normal_rate / 1000;
    peak_cost = peak_wh * tariff.normal_rate *
                tariff.peak_percent / 100000;

    total_bill = tariff.fixed_charge + normal_cost + peak_cost;

    printf("\nBILL SUMMARY\n");
    printf("Total energy: %lld Wh\n", total_wh);
    printf("Normal energy: %lld Wh\n", normal_wh);
    printf("Peak energy: %lld Wh\n", peak_wh);
    printf("Fixed charge: %lld paise\n", tariff.fixed_charge);
    printf("Normal energy charge: %lld paise\n", normal_cost);
    printf("Peak energy charge: %lld paise\n", peak_cost);
    printf("Total bill: Rs. %lld.%02lld\n",
           total_bill / 100, total_bill % 100);

    return 0;
}
