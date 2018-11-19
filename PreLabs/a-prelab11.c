// An exercise in file I/O processing
// Created by Natalie Myers on 11/13/18.

#include <stdio.h>
#define MAX 30

void get_size(int *);
int check_size(int);
void load_sructdata(char *, int);
void print_data(int size);

void main(void){
    int size;
    get_size(&size);
    check_size(size);
}

void get_size(int *pointer) { // gets the size of the array from the user
    int size;
    printf("Enter the size of the Input: ");
    scanf("%d", &size);
    printf("======================================================\n");
    check_size(size); // error checks input from user
    while (check_size(size) == 0) { // checks for invalid input
        printf("Invalid Size Entered! Minimum is 1 and Maximum is 50!\n");
        printf("======================================================\n");
        printf("Please enter again: ");
        scanf("%d", &size);
        printf("======================================================\n");
    }
    *pointer = size;
}

int check_size(int size) { // checks size for validity
    while (size < 1 || size > 50) { // checks for invalid input
        return 0;
    }
    return 1;
}
