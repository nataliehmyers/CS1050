// Created by Natalie Myers on 10/15/18
/* a-lab6.c - Implements simple functions that initialize a 2D array with
 * random numbers (between 0-9) and displays the numbers stored in the 2D array */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int check_error(int); /* takes an integer number and checks if the number is between 1-20 or
 * not if it is it returns 1 otherwise 0 */
void initialize_2Darray(int[MAX][MAX], int); /* takes an integer number which is the
 * size of the input and initializes the 2D array with random numbers between 0-9 */
void print_2Darray(int[MAX][MAX], int); // prints the content of the 2D array
int findZeros(int[MAX][MAX], int); /* counts the number of zero’s in your 2-D array, returns
the count to the main() */
int findEvenOdd(int[][MAX], int); /* counts the number of odd and even in the array
 * and returns the value */
void printTranspose(int[][MAX], int); /* prints rows as columns and columns as rows */
void flattenArray(int[][MAX], int); /* converts the 2D array into a 1D array and prints */
void sortArray(int[][MAX], int); /* sorts array, sort of */

int main() {
    int parameter;
    int array1[MAX][MAX] = {};

    printf("Enter the size of the 2-D array: "); // prompts user
    scanf("%d", &parameter); // assigns input
    check_error(parameter); // calls error check function
    while (check_error(parameter) == 1) { // creates print function for invalid inputs
        printf("Please enter a value between 1-20 only: ");
        scanf("%d", &parameter);
    }
    initialize_2Darray(array1, parameter); // calls a function to initialize the array
    print_2Darray(array1, parameter); // calls print function for the array
    printf("\n\nThe number of zeros in 2-D Array: %d", findZeros(array1, parameter)); /* prints number
 *                                                        of zeros by calling the tallying function */
    int even_num = findEvenOdd(array1, parameter); // assigns even numbers to variable
    int total_index = parameter * parameter; // subtracts evens from total index
    printf("\nThe number of Even numbers: %d", even_num);
    printf("\nThe number of Odd numbers: %d", total_index - even_num);
    printTranspose(array1, parameter); // calls for transposed array
    printf("\n");
    flattenArray(array1, parameter); // calls for flattened array
    sortArray(array1, parameter); // calls for sorted array - INCOMPLETE
}

void initialize_2Darray(int array1[MAX][MAX], int parameter) { // initializes a 2D array
    int i, j;
    srand(time(NULL));
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            array1[i][j] = rand() % 10; // assigns random integers to array values
        }
    }
}

void print_2Darray(int array1[MAX][MAX], int parameter) { // prints the content of the 2D array
    int i, j;
    printf("\nTHE FIRST 2D ARRAY is:\n");
    for (i = 0; i < parameter; i++) {
        printf("\n"); // prints new line for formatting in a square
        for (j = 0; j < parameter; j++) {
            printf("%3d ", array1[i][j]); // prints results
        }
    }
}

int findZeros(int array1[MAX][MAX], int parameter) { // tallies zeros in the array
    int x = 0; // sets number of zeros to zero
    int i, j;
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            if (array1[i][j] == 0) { // checks for zeros
                x += 1; // adds 1 to count for every zero in the array
            }
        }
    }
    return x;
}

int findEvenOdd(int array1[MAX][MAX], int parameter) {
    int x = 0; // sets number of evens to zero
    int i, j;
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            if (array1[i][j] % 2 == 0) { // checks for even numbers
                x += 1; // adds 1 to count for every even number in the array
            }
        }
    }
    return x;
}

void printTranspose(int array1[MAX][MAX], int parameter) { // transposes array
    int i, j;
    printf("\nThe transpose of the 2-D Array is\n");
    for (j = 0; j < parameter; j++) { // assigns rows
        printf("\n");
        for (i = 0; i < parameter; i++) { // assigns columns
            printf("%3d ", array1[i][j]); // prints in column, row order
        }
    }
}

void flattenArray(int array1[MAX][MAX], int parameter) { // flattens array into 1D
    int i, j;
    printf("\nThe flattened array is:\n");
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            printf("%d ", array1[i][j]); // prints index in one line
        }
    }
}

void sortArray(int array1[][MAX], int parameter) { // I tried...
    int array2[400], i, j;
    int temp = 0;
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            array2[temp] = array1[i][j];
            temp++;
        }
    }
    parameter = parameter * parameter;
    for (i = 0; i < parameter - 1; i++) { // an attempt at bubble sort
        for (j = 0; j < parameter - i - 1; j++) {
            if (array2[j] > array2[j+1]) {
                temp = array2[j];
                array2[j] = array2[j+1];
                array2[j+1] = temp;
            }
        }
    }
    printf("\nThe sorted array is:\n");
    for (i = 0; i < parameter; i++) {
        printf("%d ", array2[i]);
    }
}

int check_error(int parameter) { // error check function
    while (parameter <= 0 || parameter > 20) { // checks for valid input
        return 1;
    }
    return 0;
}
