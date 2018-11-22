// An exercise in file I/O processing
// Created by Natalie Myers on 11/13/18

#include <stdio.h>
#define MAX 30

void get_size(int *);
int check_size(int);
void load_structdata(char *, int);
void print_data(int size);


struct student // defines struct parameter
{
    char name[MAX];
    int id;
    int grade;
};

// global variable as per instructions
struct student students[MAX];

int main(int argc, char *argv[]) {
    int size;
    if (argc < 2) { // checks for appropriate number of command line arguments
        printf("Incorrect number of arguments");
        return 1;
    }
    get_size(&size); // calls function to get input for the size
    check_size(size); // calls function to check for a valid inout
    load_structdata(argv[1], size); // calls function to read data file
    print_data(size); // calls function to print file data
    return 0;
}

void load_structdata(char *filename, int size) { // scans data
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    for (int i = 0; i < size; i++) { // iterates from 0 up to the given size
        fscanf(fp, "%s\t%d\t%d", students[i].name, &students[i].id, &students[i].grade); // scans file for selected information
    }
}

void print_data(int size) { // prints data
    printf("Student-Record\n\ns/no\tName\tId\tGrade\n");
    for (int i = 0; i < size; i++) { // iterates from 0 up to the given size
        printf("%d\t%s\t%d\t%d\n", i+1, students[i].name, students[i].id, students[i].grade); // prints select information
    }
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
