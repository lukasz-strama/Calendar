#include "common.h"
#include "calendar.h"

int main() {
    displayCalendar();
    
    // Add a pause to wait for a key press
    printf("\nPress any key to exit...");
    getchar(); // Wait for user input

    return 0;
}