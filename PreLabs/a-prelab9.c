// a-prelab9.c - An exercise in pointer notation.
// Created by Natalie Myers on 10/29/18

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void get_size(int *);
int check_size(int);
void initialize_pointerArray(int *, int);
void print_pointerArray(int *, int);
int find_max(int *, int);

main(void) {
    int array[MAX];
    int *pointer = array;
    int size;
    srand(time(NULL)); // calls time for random number generator
    get_size(&size); // gets the size of the array from user
    initialize_pointerArray(pointer, size); // initializes random numbers to array
    find_max(pointer, size); // finds the largest element in the array
    printf("The largest value in the pointer is:\n");
    printf("%d", find_max(pointer, size)); // prints largest element
    printf("\n");
}

void get_size(int *pointer) { // gets the size of the array from the user
    int size;
    printf("Enter the size of the input: ");
    scanf("%d", &size);
    check_size(size); // error checks input from user
    while (check_size(size) == 0) { // checks for invalid input
        printf("Invalid input enter the size of the array again: ");
        scanf("%d", &size);
    }
    *pointer = size;
}

void initialize_pointerArray(int *pointer, int size) { // initializes random integers to the elements of the array
    int i;
    for (i = 0; i < size; i++) { // iterates through the array
        *pointer = rand() % 11; // assigns random integers to the elements of the array
    }
    print_pointerArray(pointer, size); // calls print function to print array
}

void print_pointerArray(int *pointer, int size) { // prints array
    printf("\nInput array:\n");
    for (int i = 0; i < size; i++) { // iterates through the array
        *pointer = rand() % 11; // assigns random integers to the elements of the array
        printf("%d ", *pointer);
        pointer++;
    }
    printf("\n\n");
}

int find_max(int *pointer, int size) { // finds largest element in the array
    int max = *pointer;
    for (int i = 0; i < size; i++) { // iterates through the array
        if (*(pointer+i) > max) { /* checks if the nest element in the series is larger than the current
 *                                  largest element */
            max = *(pointer+i);
        }
    }
    return max;
}

int check_size(int size) { // checks size for validity
    while (size <= 0 || size > 50) { // checks for invalid input
        return 0;
    }
    return 1;
}