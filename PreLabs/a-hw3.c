// Program that uses command line arguments to read file names, memory allocation, and FILE pointers
// Created by Natalie Myers on 11/13/18

#include <stdio.h>
#include <stdlib.h>

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
    int record_count = get_record_count(*filename);
    int *accounts = malloc(sizeof(int) * record_count);
    float *balances = malloc(sizeof(float) * record_count);

    printf("\nLines: %d\n\n", record_count);

    load_data(*filename, accounts, balances, record_count);
    print_data(accounts, balances, record_count);



    free(accounts);
    free(balances);
}

int get_record_count(char *filename) {
    int num_count = 1;
    int next_char;
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    while(!feof(fp))
    {
        next_char = fgetc(fp);
        if(next_char == '\n')
        {
            num_count++;
        }
    }
    return num_count;
}

int load_data(char *filename, int *accounts, float *balances, int record_count) {
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    if (fp == NULL) {
        printf("Unable to open the input file\n");
        return 1;
    }
    for (int i = 0; i < record_count; i++) { // iterates from 0 up to the given size
        fscanf(fp, "%d %f", &accounts[i], &balances[i]); // scans file for selected information
    }
    return 0;
}

void print_data(int *accounts, float *balances, int record_count){
    printf("Account No.\tAmount\n");
    for(int i = 0; i < record_count; i++) {
        printf("%d\t\t%.2f\n", accounts[i], balances[i]);
    }
}