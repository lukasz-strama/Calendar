#include "calendar.h"
#include <stdio.h>
#include <time.h>

void displayCalendar() {
    // Get the current time
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    // Extract month and year
    int current_month = tm_info->tm_mon + 1; // Adjust for zero-based indexing
    int current_year = tm_info->tm_year + 1900; // Adjust for years since 1900
    int current_day = tm_info->tm_mday; // Current day

    // Print the calendar header
    printf("Calendar for %d/%d\n", current_month, current_year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Array to store the number of days in each month
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the number of days in the current month
    int days = days_in_month[current_month];

    // Calculate the day of the week on which the month starts (0 = Sunday, 1 = Monday, etc.)
    int starting_day = (tm_info->tm_wday - (tm_info->tm_mday % 7) + 7) % 7;

    // Print the calendar grid
    for (int day = 1; day <= days; day++) {
        // Print leading spaces for the starting day
        if (day == 1) {
            for (int i = 0; i < starting_day; i++) {
                printf("    ");
            }
        }

        // Print the day with proper spacing
        if (day == current_day) {
            printf("\x1b[31m%3d\x1b[0m ", day); // Red text for the current day
        } else {
            printf("%3d ", day);
        }

        // Move to the next line if it's a Saturday
        if ((day + starting_day) % 7 == 0 || day == days) {
            printf("\n");
        }
    }
}
