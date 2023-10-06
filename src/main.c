#include "common.h"
#include "calendar.h"
#include <stdlib.h> 

int main() {
    int selected_month = 0; // Variable to store the selected month (1-12)
    int current_month = 0;  // Variable to store the current month (1-12)

    // Get the current time
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    current_month = tm_info->tm_mon + 1; // Adjust for zero-based indexing
    int current_day = tm_info->tm_mday;  // Current day

    while (1) {
        // Clear the screen for better readability 
        system("cls");

        // Display a menu to choose a month
        printf("Choose a month:\n");
        for (int month = 1; month <= 12; month++) {
            if (month == current_month) {
                // Highlight the current month in red
                printf("\x1b[31m  %d. ", month);
            } else {
                printf("  %d. ", month);
            }

            // Print month names here
            switch (month) {
                case 1: printf("January"); break;
                case 2: printf("February"); break;
                case 3: printf("March"); break;
                case 4: printf("April"); break;
                case 5: printf("May"); break;
                case 6: printf("June"); break;
                case 7: printf("July"); break;
                case 8: printf("August"); break;
                case 9: printf("September"); break;
                case 10: printf("October"); break;
                case 11: printf("November"); break;
                case 12: printf("December"); break;
                default: printf("Unknown");
            }

            printf("\n\x1b[0m"); // Reset text color
        }

        // Input validation: Ensure the selected month is between 1 and 12
        do {
            printf("Enter the number of the month (0 to exit): ");
            scanf("%d", &selected_month);
        } while (selected_month < 0 || selected_month > 12);

        if (selected_month == 0) {
            break; // Exit the loop if 0 is entered
        }

        // Clear the screen again before displaying the calendar
        system("cls");

        // Display the calendar for the selected month
        displayCalendar(selected_month, current_month, current_day);

        // Add a pause to wait for a key press
        printf("\nPress any key to continue...");
        getchar(); // Consume newline from previous input
        getchar(); // Wait for user input
    }

    return 0;
}
