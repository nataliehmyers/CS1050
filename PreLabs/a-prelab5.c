/* a-prelab5.c - A program that will take the input for the number of array elements to be generated
 * and will store that amount of random numbers inside an array */
// Created by Natalie Myers on 9/27/18.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_error(int); /* Takes an integer number and checks if the number is between 1-50 or not,
 * if it is, returns 1, otherwise 0 */
void initialize_array(int[], int); /* takes an integer array and its size as arguments and\
 * initializes the integer 1D array ith random numbers between 0-9 (use for-loop) */
void print_array(int[], int); /* takes an integer array and its size and prints the content
 * of an array (use for-loop) */


int main() {
    int given_parameter;
    int array1[50] = {0};
    printf("Enter the size of the input: ");
    scanf("%d", &given_parameter);
    while (check_error(given_parameter) == 0) {
        printf("Invalid input enter the size of the input again: ");
        scanf("%d", &given_parameter);
    }
    initialize_array(array1, given_parameter);
    print_array(array1, given_parameter);
    return 0;
}

void initialize_array(int array1[], int given_parameter) {
    int i;
    srand(time(NULL));
    for (i = 0; i < given_parameter; i++) {
        array1[i] = rand() % 10;
    }
}

void print_array(int array1[], int given_parameter) {
    int i;
    printf("Input array 1\n");
    for (i = 0; i < given_parameter; i++) {
        printf("%d ", array1[i]);
    }
}

int check_error(int element_limit) {
    while (element_limit < 1 || element_limit > 50) {
        return 0;
    }
    return 1;
}


