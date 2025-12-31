#include <stdio.h>
#include "utils1.h"

// Clear input buffer to prevent infinite loops on invalid input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Get valid integer input with error handling
int getValidInt(const char* prompt) {
    int value;
    int result;
    
    while(1) {
        printf("%s", prompt);
        result = scanf("%d", &value);
        
        if (result == 1) {
            clearInputBuffer(); // Clear any extra characters
            return value;
        } else {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer(); // Clear invalid input
        }
    }
}

// Get integer in specific range
int getIntInRange(const char* prompt, int min, int max) {
    int value;
    while(1) {
        value = getValidInt(prompt);
        if (value >= min && value <= max) {
            return value;
        } else {
            printf("Please enter a number between %d and %d.\n", min, max);
        }
    }
}
