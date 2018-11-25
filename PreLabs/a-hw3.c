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

int main(int argc, char *argv[]) {
    if (argc < 3) { // checks for appropriate number of command line arguments
        printf("Incorrect number of arguments\nSyntax: ./a.out input_file_name output_file_name\n");
        return 1;
    }
    char *input_file = argv[1];
    char *output_file = argv[2];
    int record_count = get_record_count(input_file);
    int *accounts = malloc(sizeof(int) * record_count);
    float *balances = malloc(sizeof(float) * record_count);

    load_data(input_file, accounts, balances, record_count);
    print_data(accounts, balances, record_count);
    int max_index = highest_amount(balances, record_count);
    printf("\nThe highest amount of $%.2f is in the account number %d", balances[max_index], accounts[max_index]);
    int min_index = lowest_amount(balances, record_count);
    printf("\nThe lowest amount of $%.2f is in the account number %d", balances[min_index], accounts[min_index]);
    float calc_average = average_amount(balances, record_count);
    printf("\nThe average amount is $%.2f\n", calc_average);
    write_data(output_file, accounts, balances, record_count, max_index, min_index, calc_average);

    free(accounts);
    free(balances);
}

int get_record_count(char *filename) {
    int num_count = 1;
    int next_char;
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    next_char = fgetc(fp);
    while(next_char != EOF)
    {
        if(next_char == '\n')
        {
            num_count++;
        }
        next_char = fgetc(fp);
    }
    fclose(fp);
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

int highest_amount(float *balances, int record_count) {
    float max = -2147483648;
    int index = -1;
    for (int i = 0; i < record_count; i++) {
        if (balances[i] > max) {
            max = balances[i];
            index = i;
        }
    }
    return index;
}

int lowest_amount(float *balances, int record_count) {
    float min = 2147483647;
    int index = -1;
    for (int i = 0; i < record_count; i++) {
        if (balances[i] < min) {
            min = balances[i];
            index = i;
        }
    }
    return index;
}

float average_amount(float *balances, int record_count) {
    float total = 0;
    for (int i = 0; i < record_count; i++) {
        total += balances[i];
    }
    return total/record_count;
}

int write_data(char *output_file, int *accounts, float *balances, int record_count, int max_index, int min_index, float calc_average) {
    FILE *fp; // defines a FILE pointer
    fp = fopen(output_file, "w");
    if (fp == NULL) {
        printf("Unable to open the input file\n");
        return 1;
    }
    fprintf(fp, "Account No.\tAmount\n");
    for (int i = 0; i < record_count; i++) {
        fprintf(fp, "%d\t\t%.2f\n", accounts[i], balances[i]);
    }
    fprintf(fp, "\nhe highest amount of $%.2f is in the account number %d"
                "\nThe lowest amount of $%.2f is in the account number %d"
                "\nThe average amount is $%.2f\n",
            balances[max_index], accounts[max_index],
            balances[min_index], accounts[min_index],
            calc_average);
    return 0;
}