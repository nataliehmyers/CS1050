// Program that uses command line arguments to read file names, memory allocation, and FILE pointers
// Created by Natalie Myers on 11/13/18

#include <stdio.h>

void print_data(int*, float*, int);
int highest_amount(float*, int);
int lowest_amount(float*, int);
float average_amount(float*, int);
int write_data(char*, int*, float *, int , int, int, float);

int main(int argc, char *filename[]) {
    int size;
    if (argc < 2) { // checks for appropriate number of command line arguments
        printf("Incorrect number of arguments\nSyntax: ./a.out input_file_name output_file_name\n");
        return 1;
    }
    FILE *fp;
    fp = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        //
    }
    return 0;
}
