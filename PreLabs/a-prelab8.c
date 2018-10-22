// Use pointer notation to calculate and print factorials.
// Created by Natalie Myers on 10/18/18

#include <stdio.h>

int errorCheck(int);
void factorial(int *output, int limit);
void printArray(int*, int);

int main() {
    int value;
    int array[20];
    int *output = array;

    printf("Enter a value to calculate the factorial: ");
    scanf("%d", &value);
    errorCheck(value);
    while (errorCheck(value) == 1) {
        printf("Input must be larger than 0 and less than 20. Please enter again: ");
        scanf("%d", &value);
    }
    // printf("made it here");
    factorial(*output, value);
}

void factorial(int *output, int value) {
    int i;
    int factorial = 1;
    // *output = 1;
    // printf("made it this far");

    for (i = 0; i <= value; i++) {
        factorial = factorial * i;
        *output = factorial;
        printf("%d", *output);
        // printf("please work");
    }
}

void printArray(int *output, int value) {
    printf("%d", *output);
}

int errorCheck(value) {

    if (value < 1 || value > 19) {
        return 1;
    }
    return 0;
}