#include "calendar.h"
#include <stdio.h>
#include <time.h>

// Define an array of month names for reference
const char *month_names[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void displayCalendar(int selected_month, int current_month, int current_day) {
    // Print the calendar header with the selected month highlighted in red
    printf("Calendar\n");

    // Get the name of the selected month
    const char *selected_month_name = month_names[selected_month];

    // Print the name of the selected month
    printf("\x1b[34m%s\x1b[0m\n", selected_month_name);

    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Array to store the number of days in each month
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the number of days in the selected month
    int days = days_in_month[selected_month];

    // Calculate the day of the week on which the selected month starts (0 = Sunday, 1 = Monday, etc.)
    // Note: You may want to adjust this calculation based on user preferences for the starting day.
    int starting_day = 0; // Assuming Sunday as the starting day

    

    // Print the calendar grid
    for (int day = 1; day <= days; day++) {
        // Print leading spaces for the starting day
        if (day == 1) {
            for (int i = 0; i < starting_day; i++) {
                printf("    ");
            }
        }

        // Print the day with proper spacing and highlight the current day in red
        if (day == current_day && selected_month == current_month) {
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