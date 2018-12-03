// Counts words!

#include <stdio.h>

int count_lines(char *, int);

int main(int argc, char *argv[]) {
    char *input_file = argv[1];
    int count = 0;

    if (argc < 2) {
        printf("Do not forget to give an input text file!");
        return 1;
    }
    if (count_lines(input_file, count) == -1) {
        return 1;
    } if (count_lines(input_file, count) == 0) {
        printf("Input file is empty!\n");
    } else {
        printf("Word count: %d\n", count_lines(input_file, count));
    }
}

int count_lines(char *input_file, int count) { // scans data form input file
    int next_char;
    FILE *fp; // defines a FILE pointer
    fp = fopen(input_file, "r"); // opens a file in read mode and sets the command to a variable
    if (fp == NULL) { // checks for valid input
        printf("Unable to open input file.\n");
        return -1;
    }
    next_char = fgetc(fp);
    while (next_char != EOF) { // loops through file characters that are not end of file
        if (next_char == ' ' || next_char == '\n' || next_char == '\t') { // checks for new line escape character
            count++;
        }
        next_char = fgetc(fp);
    }
    fclose(fp);
    return count;
}
