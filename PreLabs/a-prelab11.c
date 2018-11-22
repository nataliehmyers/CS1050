// An exercise in file I/O processing
// Created by Natalie Myers on 11/13/18

#include <stdio.h>
#define MAX 30

void get_size(int *);
int check_size(int);
void load_structdata(char *, int);
void print_data(int size);


struct student
{
    char name[MAX];
    int id;
    int grade;
};

// global variable as per instructions
struct student students[MAX];

int main(int argc, char *argv[]) {
    int size;
    if (argc < 2) {
        printf("Incorrect number of arguments");
        return 1;
    }
    get_size(&size);
    check_size(size);
    load_structdata(argv[1], size);
    print_data(size);
    return 0;
}

void load_structdata(char *filename, int size) {
    FILE *fp;
    fp = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%s\t%d\t%d", students[i].name, &students[i].id, &students[i].grade);
    }
}

void print_data(int size) {
    printf("Student-Record\n\ns/no\tName\tId\tGrade\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%d\n", i+1, students[i].name, students[i].id, students[i].grade);
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
