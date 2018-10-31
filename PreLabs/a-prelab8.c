// Use pointer notation to calculate and print factorials.
// Created by Natalie Myers on 10/18/18

#include <stdio.h>

int errorCheck(int);
void factorial(int *, int);
void printArray(int*, int);

int main() {
    int value;
    int array[10];
    int *output = array;

    printf("Enter a value to calculate the factorial: ");
    scanf("%d", &value);
    errorCheck(value);
    while (errorCheck(value) == 1) {
        printf("Input must be larger than 0 and less than or equal to 10. Please enter again: ");
        scanf("%d", &value);
    }
    factorial(output, value);
    printArray(output, value);
}

void factorial(int *output, int value) {
    int factorial = 1;
    for (int i = 1; i <= value; i++) {
        factorial = factorial * i;
        *output = factorial;
        output++;
    }
}

void printArray(int *output, int value) {
    printf("The array of the stored factorial values:\n");
    for (int i = 1; i <= value; i++) {
        printf("%d ", *output);
        output++;
    }
    printf("\n");
}

int errorCheck(int value) {
    if (value < 1 || value > 10) {
        return 1;
    }
    return 0;
}
