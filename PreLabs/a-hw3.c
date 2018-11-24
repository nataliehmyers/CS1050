// Program that uses command line arguments to read file names, memory allocation, and FILE pointers
// Created by Natalie Myers on 11/13/18

#include <stdio.h>

int get_record_count(char *);
int load_data(char *, int *, float *, int);
void print_data(int *, float *, int);
int highest_amount(float *, int);
int lowest_amount(float *, int);
float average_amount(float *, int);
int write_data(char *, int *, float *, int , int, int, float);

int main(int argc, char *filename[]) {
    if (argc < 2) { // checks for appropriate number of command line arguments
        printf("Incorrect number of arguments\nSyntax: ./a.out input_file_name output_file_name\n");
        return 1;
    }
    get_record_count(*filename);
}

int get_record_count(char *filename) {
    int x = 0;
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    while(!feof(fp))
    {
        x = fgetc(fp);
        if(x == '\n')
        {
            x++;
        }
    }
    return x;
}
