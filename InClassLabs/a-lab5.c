/* a-lab5.c - A program that will take the input for the number of array elements to be generated
 * and will store that amount of random numbers inside an array */
// Created by Natalie Myers on 9/30/18.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int check_error(int); /* Takes an integer number and checks if the number is between 1-50 or not,
 * if it is, returns 1, otherwise 0 */
void initialize_array(int[], int); /* takes an integer array and its size as arguments and\
 * initializes the integer 1D array ith random numbers between 0-9 (use for-loop) */
void print_array(int[], int); /* takes an integer array and its size and prints the content
 * of an array (use for-loop) */
float average(int[], int); /* Takes an integer array and an integer, which is the size of
 * the input array, and returns the average of all the numbers present in the array */
float std_dev(int[], int); /* Takes an integer array and an integer that corresponds to the size of the array.
 * It returns the standard deviation of all the numbers in the array */
int max(int[], int); /* Takes an integer array and an integer and returns the index of the maximum
 * number in the array */

int main() { // calls functions and prints results
    int given_parameter;
    int array1[50] = {0};
    printf("Enter the number of elements to be generated: ");
    scanf("%d", &given_parameter);
    while (check_error(given_parameter) == 0) {
        printf("Please enter a number between 1 and 50: ");
        scanf("%d", &given_parameter);
    }
    initialize_array(array1, given_parameter);
    print_array(array1, given_parameter);
    average(array1, given_parameter);
    printf("\nThe average of the array is %.2f", average(array1, given_parameter));
    std_dev(array1, given_parameter);
    printf("\nThe standard deviation of the array is %.2f", std_dev(array1, given_parameter));
    max(array1, given_parameter);
    printf("\nThe index of the biggest element is %d", max(array1, given_parameter));
    return 0;
}

void initialize_array(int array1[], int given_parameter) { // assigns random values to the array
    int i;
    srand(time(NULL));
    for (i = 0; i < given_parameter; i++) {
        array1[i] = rand() % 10;
    }
}

void print_array(int array1[], int given_parameter) { // prints array values
    int i;
    printf("The array is:\n");
    for (i = 0; i < given_parameter; i++) {
        printf("%d ", array1[i]);
    }
}

float average(int array1[], int given_parameter) { // calculates average of array values
    int i;
    float average_calc;
    int total = 0;
    for (i = 0; i < given_parameter; i++) {
        total = total + array1[i];
        average_calc = total / given_parameter;
    }
    return average_calc;
}

float std_dev(int array1[], int given_parameter) { // calculates standard deviation of array values
    int i;
    float total;
    int result = 0;
    for (i = 0; i < given_parameter; i++) {
        total = total + array1[i];
    }
    for (i = 0; i < given_parameter; i++) {
        result = result + pow(array1[i] - given_parameter, 2);
    }
    return sqrt(result / given_parameter);
}

int max(int array1[], int given_parameter) { // finds the biggest index element of array values
    int i;
    int x = 0;
    int max = array1[x];
    for (i = 0; i < given_parameter; i++) {
        if (array1[i] > max) {
            max = array1[i];
            x = i;
        }
    }
    return x;
}

int check_error(int element_limit) { // checks for valid input
    while (element_limit < 1 || element_limit > 50) {
        return 0;
    }
    return 1;
}
