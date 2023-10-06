# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -std=c99

# Source files directory
SRC_DIR = src

# Include directory
INCLUDE_DIR = include

# Output directory
BUILD_DIR = build

# Output executable name
OUTPUT = c_day

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Default target
all: $(BUILD_DIR) $(OUTPUT)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Link object files into the executable
$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# PHONY targets (targets that are not actual files)
.PHONY: all clean