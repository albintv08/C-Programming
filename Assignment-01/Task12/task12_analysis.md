# Task 12 – Day-4 Design Challenge: Smart Meter Billing

## 1. Objective

Redesign the electricity billing program for smart meters that report energy consumption in watt-hours (Wh) every 15 minutes. The system must apply a 20% higher tariff during peak hours (6 PM to 10 PM) and allow tariff changes without recompiling the program.

## 2. Impact Analysis

The original billing design used a simple meter reading and fixed tariff constants. The new requirements introduce:

- 15-minute readings, producing 96 readings per day.
- 35,040 readings per household in a 365-day year.
- Energy measurement in watt-hours instead of only whole-unit consumption.
- A peak period from 18:00 to 22:00, with a 20% higher rate.
- Runtime tariff configuration instead of fixed compile-time tariff values.

An unsigned short meter value is not suitable for storing an annual cumulative energy total. The redesigned program uses `long long` for accumulated watt-hours and monetary calculations. A structure named `Tariff` stores the runtime tariff settings.

## 3. Annual Capacity Calculations

Readings per day:

96 readings

Readings per year:

96 × 365 = 35,040 readings

The program accepts up to 35,040 readings, matching the assignment requirement.

The assignment does not specify a maximum energy value for an individual reading. Therefore, an absolute maximum annual energy value cannot be calculated from the reading count alone.

### Illustrative annual energy calculation

Assume each of the 35,040 readings reports 1,000 Wh.

Annual energy:

35,040 × 1,000 = 35,040,000 Wh

35,040,000 Wh ÷ 1,000 = 35,040 kWh

Peak period:

6 PM to 10 PM = 4 hours per day.

At 15-minute intervals, this represents 16 readings per day.

Annual peak readings:

16 × 365 = 5,840 readings

Assuming 1,000 Wh in every interval:

- Peak energy = 5,840 kWh
- Normal energy = 29,200 kWh

At a normal tariff of 225 paise/kWh:

- Normal charge = 29,200 × Rs. 2.25 = Rs. 65,700
- Peak tariff = 225 × 120% = 270 paise/kWh
- Peak charge = 5,840 × Rs. 2.70 = Rs. 15,768
- Fixed charge = Rs. 50

Illustrative total annual bill:

Rs. 65,700 + Rs. 15,768 + Rs. 50 = Rs. 81,518

This is an illustrative calculation, not a measured household bill.

## 4. Redesigned Implementation

Files:

- `smart_billing.c` – smart meter billing implementation.
- `tariff.conf` – runtime tariff configuration.
- `normal_tariff_output.txt` – original tariff test evidence.
- `peak_test_output.txt` – modified tariff test evidence.
- `annual_capacity_output.txt` – annual reading capacity test evidence.

The program uses `long long` for energy totals and paise calculations. It separates normal and peak energy according to the reading hour.

The tariff configuration contains:

- Fixed charge in paise.
- Normal rate in paise per kWh.
- Peak rate percentage.
- Peak starting hour.
- Peak ending hour.

The program reads these settings from `tariff.conf` at runtime. Changing the configuration does not require recompilation.

### Billing formulas

Normal energy charge:

Normal Wh × Normal rate in paise/kWh ÷ 1,000

Peak energy charge:

Peak Wh × Normal rate × Peak percentage ÷ 100,000

Total bill:

Fixed charge + Normal energy charge + Peak energy charge

The current implementation uses integer arithmetic and truncates fractional paise.

## 5. Test Results

### Test 1 – Normal and peak consumption

Input:
- Reading 1: 17:00, 1,000 Wh
- Reading 2: 19:00, 1,000 Wh
- Normal rate: 225 paise/kWh
- Peak rate: 120%

Expected calculation:
- Normal charge = 225 paise
- Peak charge = 270 paise
- Fixed charge = 5,000 paise
- Total = 5,495 paise = Rs. 54.95

Actual result: Rs. 54.95 – PASS.

### Test 2 – Runtime tariff modification

The normal tariff was changed from 225 to 300 paise/kWh in `tariff.conf`, without recompiling the C program.

Expected calculation:
- Normal charge = 300 paise
- Peak charge = 360 paise
- Fixed charge = 5,000 paise
- Total = 5,660 paise = Rs. 56.60

Actual result: Rs. 56.60 – PASS.

The original tariff was restored after this test.

### Test 3 – Annual reading capacity

Input:
- Number of readings: 35,040
- Each reading: 12:00, 1 Wh
- Normal tariff: 225 paise/kWh

Actual result:
- Total energy: 35,040 Wh
- Normal energy: 35,040 Wh
- Peak energy: 0 Wh
- Normal charge: 7,884 paise
- Fixed charge: 5,000 paise
- Total bill: Rs. 128.84

Result: PASS.

## 6. Design Trade-offs and Limitations

- `long long` provides a much wider integer range than a 16-bit meter value and is suitable for the demonstrated annual accumulation.
- Integer paise avoids binary floating-point representation errors in currency calculations.
- A configuration file allows tariff changes without recompilation, but invalid or missing configuration must be handled carefully.
- The prototype accepts an hour for each reading rather than a complete date and timestamp. A production system should validate actual 15-minute timestamps and reject duplicate or missing intervals.
- The current calculation truncates fractional paise. A production billing system should define and consistently apply an appropriate rounding policy.
- Production software should also check multiplication and addition overflow for all large energy and tariff values.

## 7. Conclusion

The redesigned smart meter billing program supports annual reading capacity, normal and peak-hour billing, and runtime tariff configuration. Tests confirmed the expected bills for normal and peak consumption, successful tariff modification without recompilation, and processing of all 35,040 annual readings. Wider integer types and configurable tariff settings make the design more suitable for the expanded requirements.
