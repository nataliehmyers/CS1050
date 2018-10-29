// Created by Natalie Myers on 10/29/18

#include <stdio.h>
#include <math.h>
#define MAX 10

int errorCheck(int);
int factorial(int);
void printArray(float*, int);
void maclaurinSeries(float*, int, int);
void reverseArray(float*, int); // attempted again

int main() {
    int value, size;
    float array[MAX];
    float *ptrArray = array;

    printf("Enter a value to compute the Maclaurin series expansion (x): " );
    scanf("%d", &value);
    errorCheck(value);
    while (errorCheck(value) == 1) { // calls error check function
        printf("x must be larger than 0 and less than 10. Please enter again: ");
        scanf("%d", &value);
    }
    factorial(value);
    printf("Enter a value for the Maclaurin series to run (n): ");
    scanf("%d", &size);
    errorCheck(size);
    while (errorCheck(size) == 1) { // calls error check function
        printf("n must be larger than 0 and less than 10. Please enter again: ");
        scanf("%d", &size);
    }
    maclaurinSeries(ptrArray, size, value);
}

int factorial(int value) { // takes the factorial of a given int
    int factorial = 1;
    for (int i = 1; i <= value; i++) { // iterates through values until the int
        factorial = factorial * i;
    }
    return factorial;
}



void printArray(float *ptrArray, int size) { // prints array values
    int i;
    printf("The array for the Maclaurin series is:\n");
    for (i = 0; i < size; i++) { // iterates through array values
        printf("%f ", *(ptrArray + i));
    }
}

void maclaurinSeries(float *ptrArray, int size, int value) { // calculates array values
    int i;
    float total = 1;
    int x = value;
    int n = size;
    *ptrArray = 1;

    for (i = 1; i < n; i++) {
        if (i % 2 == 0){ // checks odds or evens
            total = total + (pow(x, i*2)/factorial(i*2));
        } else {
            total = total - (pow(x, i*2)/factorial(i*2));
        }
    *(ptrArray + i) = total;
    }
    printArray(ptrArray, size);
}

int errorCheck(int value) { // check for valid inputs
    if (value < 1 || value > 10) { // checks if value is incorrect
        return 1;
    }
    return 0;
}

/*
void reverseArray(float *ptrArray, value) {
    float reversedArray[MAX];
    float array_size = sizeof(ptrArray);
    float *ptrReversedArray = ptrArray + array_size - 1;
    int i, x;

    for (i = value - 1, x = 0; i >= 0; value--, x++) {
        ptrReversedArray = ptrArray;
    }
}
*/