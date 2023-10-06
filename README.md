# Calendar Application in C

This is a simple console-based calendar application written in C. It allows you to view and navigate through a calendar, highlighting the current month and day.

## Files Tree

calendar/
│
├── include/
│ └── common.h # Common header file for constants and libraries
│
├── src/
│ ├── calendar.c # Calendar logic implementation
│ ├── calendar.h # Header file for calendar.c
│ └── main.c # Main application logic
│
├── build/ # Directory for compiled object files and executables
│
├── makefile # Makefile for building the application
│
└── README.md # Documentation for the project


## Functionalities

- View a calendar for the current month.
- Navigate through months using arrow keys.
- Highlight the current day and month.
- Accept a command-line argument to display a specific month.
- Clear the screen for better readability.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/lukasz-strama/c_day.git
   ```

2. Navigate to the project directory:

  ```bash
  cd calendar-c
  ```
   
3. Build the calendar application using the provided ```makefile```:

  ```bash
  make
  ```

4. Run the calendar application:

To display the interactive menu:

  ```bash
  ./c_day
  ```

To display a specific month (e.g., May):

  ```bash
  ./c_day May
  ```