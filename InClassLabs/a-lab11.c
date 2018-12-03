// An exercise in file I/O processing
// Created by Natalie Myers on 12/3/18

#include <stdio.h>
#include <string.h>
#define MAX 40

void get_size(int *);
int check_size(int);
void load_data(char *, int);
void print_data(int size);
void get_group(int *);
int check_group(int);
void classify(char *, int);
void frequency(char *, int, int);



struct address // defines struct parameter
{
    char county[MAX];
    int zip;
    char city[MAX];
    int group;
};

// global variable as per instructions
struct address addresses[MAX];

int main(int argc, char *argv[]) {
    int size, group;
    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }
    get_size(&size); // calls function to get input for the size
    load_data(argv[1], size); // calls function to read data file
    print_data(size); // calls function to print file data
    classify(argv[1], size);
    get_group(&group);
    frequency(argv[1], size, group);
    return 0;
}

void load_data(char *filename, int size) { // scans data
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    for (int i = 0; i < size; i++) { // iterates from 0 up to the given size
        fscanf(fp, "%s\t%d\t%s", addresses[i].county, &addresses[i].zip, addresses[i].city); // scans file for selected information
    }
}

void print_data(int size) { // prints data
    printf("s/no\tCounty\tZipCode\tCity\n");
    for (int i = 0; i < size; i++) { // iterates from 0 up to the given size
        printf("%d\t%s\t%d\t%s\n", i+1, addresses[i].county, addresses[i].zip, addresses[i].city); // prints select information
    }
}

void get_size(int *pointer) { // gets the size of the array from the user
    int size;
    printf("Enter the size of the Input: ");
    scanf("%d", &size);
    printf("======================================================\n");
    check_size(size); // error checks input from user
    while (check_size(size) == 0) { // checks for invalid input
        printf("Invalid Size Entered! Minimum is 4 and Maximum is 40!\n");
        printf("======================================================\n");
        printf("Please enter again: ");
        scanf("%d", &size);
        printf("======================================================\n");
    }
    *pointer = size;
}

int check_size(int size) { // checks size for validity
    while (size < 4 || size > 40) { // checks for invalid input
        return 0;
    }
    return 1;
}

void get_group(int *pointer2) {
    int group;
    printf("Enter the group number: ");
    scanf("%d", &group);
    printf("======================================================\n");
    check_group(group); // error checks input from user
    while (check_group(group) == 0) { // checks for invalid input
        printf("Invalid Group Number Entered! Minimum is 1 and Maximum is 3!\n");
        printf("======================================================\n");
        printf("Please enter again: ");
        scanf("%d", &group);
        printf("======================================================\n");
    }
    *pointer2 = group;
}

int check_group(int group) {
    while (group < 1 || group > 3) { // checks for invalid input
        return 0;
    }
    return 1;
}

void classify(char *filename, int size) {
    int group1 = 0;
    int group2 = 0;
    int group3 = 0;

    for (int i = 0; i < size; i++) {
        if (addresses[i].zip >= 63000 && addresses[i].zip <= 63999) {
            group1++;
            addresses[i].group = 1;
        }
        if (addresses[i].zip >= 64000 && addresses[i].zip <= 64999) {
            group2++;
            addresses[i].group = 2;
        }
        if (addresses[i].zip >= 65000 && addresses[i].zip <= 66000) {
            group3++;
            addresses[i].group = 3;
        }
    }

    printf("======================================================\n");
    printf("s/no\tCounty\tZipCode\tCity\tGroup\n");
    for (int i = 0; i < size; i++) { // iterates from 0 up to the given size
        printf("%d\t%s\t%d\t%s\t%d\n", i+1, addresses[i].county, addresses[i].zip, addresses[i].city, addresses[i].group); // prints select information
    }

    printf("======================================================\n");
    printf("Number of Information in Group 1: %d\nNumber of Information in Group 2: %d\nNumber of Information in Group 3: %d\n", group1, group2, group3);
    printf("======================================================\n");
}

void frequency(char *filename, int size, int group) {
    int j=1;
    int frequency1 = 1;
    int frequency2 = 1;
    int frequency3 = 1;

    printf("Cities in Group %d....\n", group);
    for (int i = 0; i < size; i++) {
        if (addresses[i].group == group) {
            printf("[%d]\t%s\n", j++, addresses[i].city);
        }
    }
    printf("======================================================\n");
    printf("FREQUENCY TABLE..........\n\n");
    printf("s/no\tCity\tFrequency\n");

    for (int i = 0; i < size; i++) {
        frequency1 = strcmp(addresses[1].city, addresses[i].city);
        if (strcmp(addresses[1].city, addresses[i].city) > 1) {
            frequency1++;
        }
        frequency2 = strcmp(addresses[2].city, addresses[i].city);
        if (strcmp(addresses[2].city, addresses[i].city) > 1) {
            frequency2++;
        }
        frequency3 = strcmp(addresses[3].city, addresses[i].city);
        if (strcmp(addresses[3].city, addresses[i].city) > 1) {
            frequency3++;
        }
    }

    printf("%d\t%s\t%d\n", 1, addresses[1].city, frequency1);
    printf("%d\t%s\t%d\n", 2, addresses[2].city, frequency2);
    printf("%d\t%s\t%d\n", 3, addresses[3].city, frequency3);

}