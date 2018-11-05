// a-lab 9.c - An exercise in pointer notation.
// Created by Natalie Myers on 11/5/18

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void get_size(int *);
void initialize_pointerArray(int *, int);
void print_pointerArray(int *, int);
int find_min(int*, int);
int find_max(int *, int);
void bubble_sort(int*, int);
float find_median(int*, int);
int check_size(int);

int main(void) {
    int array[MAX];
    int *pointer = array;
    int size;
    srand(time(NULL)); // calls time for random number generator
    get_size(&size); // gets the size of the array from user
    initialize_pointerArray(pointer, size); // initializes random numbers to array
    find_max(pointer, size); // finds the largest element in the array
    printf("The minimum of all the numbers = %d\n", find_min(pointer, size)); // prints smallest element
    printf("The maximum of all the numbers = %d\n", find_max(pointer, size)); // prints largest element
    printf("\nThe sorted pointer is:\n");
    bubble_sort(pointer, size);
    print_pointerArray(pointer, size);
    printf("The median of the pointer is:\n");
    printf("%.2f", find_median(pointer, size));
    return 0;
}

void get_size(int *pointer) { // gets the size of the array from the user
    int size;
    printf("Enter the size of the pointer: ");
    scanf("%d", &size);
    check_size(size); // error checks input from user
    while (check_size(size) == 0) { // checks for invalid input
        printf("Please enter again: ");
        scanf("%d", &size);
    }
    *pointer = size;
}

void initialize_pointerArray(int *pointer, int size) { // initializes random integers to the elements of the array
    int i;
    for (i = 0; i < size; i++) { // iterates through the array
        *(pointer+i) = rand() % 11; // assigns random integers to the elements of the array
    }
    printf("\nThe pointer is:\n");
    print_pointerArray(pointer, size); // calls print function to print array
}

void print_pointerArray(int *pointer, int size) { // prints array
    for (int i = 0; i < size; i++) { // iterates through the array
        printf("%d ", *(pointer+i));
    }
    printf("\n\n");
}

int find_min(int *pointer, int size) { // finds largest element in the array
    int min = *pointer;
    for (int i = 0; i < size; i++) { // iterates through the array
        if (*(pointer+i) < min) { /* checks if the nest element in the series is larger than the current
 *                                  largest element */
            min = *(pointer+i);
        }
    }
    return min;
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

void bubble_sort(int *pointer, int size) {
    int i, j;
    int temp = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (*(pointer+j) > *(pointer+j+1)) {
                temp = *(pointer+j);
                *(pointer+j) = *(pointer+j+1);
                *(pointer+j+1) = temp;
            }
        }
    }
}

float find_median(int *pointer, int size) {
    bubble_sort(*pointer, size);
    if (size % 2 == 0) {
        return (*(pointer+size/2) + *(pointer+(size/2 - 1)) / 2.0);
    } else {
        return (*(pointer+size/2));
    }
}

int check_size(int size) { // checks size for validity
    while (size <= 0 || size > 50) { // checks for invalid input
        return 0;
    }
    return 1;
}