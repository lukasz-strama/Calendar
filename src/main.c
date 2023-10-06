#include "common.h"
#include "calendar.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h> // for string comparison

int main(int argc, char *argv[]) {
    int selected_month = 0; // Variable to store the selected month (1-12)
    int current_month = 0;  // Variable to store the current month (1-12)

    // Get the current time
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    current_month = tm_info->tm_mon + 1; // Adjust for zero-based indexing
    int current_day = tm_info->tm_mday;  // Current day

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT;
    SetConsoleMode(hStdin, fdwMode);

    // Check for command-line arguments
    if (argc > 1) {
        // Check if a month argument is provided
        if (argc == 2) {
            char *month_arg = argv[1];
            // Compare the argument to month names and set selected_month accordingly
            for (int month = 1; month <= 12; month++) {
                if (stricmp(month_arg, month_names[month]) == 0) {
                    selected_month = month;
                    break;
                }
            }
        }
    }

    if (selected_month != 0) {
        // Clear the screen before displaying the calendar
        system("cls");

        // Display the calendar for the selected month
        displayCalendar(selected_month, current_month, current_day);

        // Add a pause to wait for a key press
        printf("\nPress any key to continue...");
        _getch(); // Wait for user input
    } else {
        // Run the interactive menu loop
        while (1) {
            // Clear the screen for better readability 
            system("cls");

            // Display a menu to choose a month
            printf("Choose a month:\n");

            int highlight_month = 1; // The initially highlighted month

            while (1) {
                // Clear the menu area before redrawing
                COORD menuPosition = {0, 3}; // Adjust the position as needed
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuPosition);
                for (int month = 1; month <= 12; month++) {
                    if (month == current_month) {
                        // Highlight the current month in red
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
                    }

                    if (month == highlight_month) {
                        printf("-> ");
                    } else {
                        printf("   ");
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

                    if (month == current_month) {
                        // Reset text color
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }

                    printf("\n");
                }

                // Check for keyboard input
                if (_kbhit()) {
                    int key = _getch();
                    if (key == 224) {
                        key = _getch();
                        if (key == 80) { // Down arrow
                            highlight_month = (highlight_month % 12) + 1; // Move to the next month
                        } else if (key == 72) { // Up arrow
                            highlight_month = ((highlight_month - 2 + 12) % 12) + 1; // Move to the previous month
                        }
                    } else if (key == 13) { // Enter key
                        selected_month = highlight_month;
                        break; // Exit the loop if Enter is pressed
                    }
                }

                Sleep(50); // Shorter sleep duration for smoother interaction
            }

            if (selected_month == 0) {
                break; // Exit the loop if 0 is entered
            }

            // Clear the screen again before displaying the calendar
            system("cls");

            // Display the calendar for the selected month
            displayCalendar(selected_month, current_month, current_day);

            // Clear the input buffer
            while (_kbhit()) {
                _getch();
            }

            // Add a pause to wait for a key press
            printf("\nPress any key to back...");
            _getch(); // Wait for user input
        }
    }

    return 0;
}
