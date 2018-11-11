/* a-prelab10.c - Uses malloc function to allocate space (to store the string)
 * instead of creating fixed size character array */
// Created by Natalie Myers on 11/4/18

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20

int getString(char *);
int checkString(char *, int);
int errorCheck(int);
void string_length(char *, int);
void invalid_string_message(char *, int);
void error_check_cont(int);
// void getSafeString(char *, int);

int main(void) {
    int size;
    char *pointer = malloc(sizeof(char) * MAX);

    size = getString(pointer);
    printf("\nYou entered: %s which is size %d\n", pointer, size);
}

int getString(char *pointer) {
    int size;

    printf("Enter the size of the string: ");
    scanf("%d", &size);


    error_check_cont(size);
    printf("\nPlease enter the string: ");
    scanf("%20s", pointer);


    string_length(pointer, size);


    invalid_string_message(pointer, size);



    size = strlen(pointer);
    return size;
}

int errorCheck(int size) {
    if (size < 1 || size > 20) {
        return 0;
    }
    return 1;
}

int checkString(char *pointer, int size) {
    int i;
    for (int i = 0; i < size; i++) {
        *(pointer + i) = toupper(*(pointer + i));
    }
    for (i = 0; i < size; i++) {
        if ((*(pointer + i) < 65 || *(pointer + i) > 90) && *(pointer + i) != '\0') {
            return 0;
        }
    }
    return 1;
}


void string_length(char *pointer, int size) {
    while (strlen(pointer) > size) {
        printf("\nThe string entered is longer than the allowed size\n"
               "\nPlease enter a valid string: ");
        scanf("%20s", pointer);
        invalid_string_message(pointer, size);
    }
}


void invalid_string_message(char *pointer, int size) {
    while (checkString(pointer, size) == 0) {
        printf("\nPlease enter a valid string: ");
        scanf("%20s", pointer);
        string_length(pointer, size);
    }
}

void error_check_cont(int size) {
    while (errorCheck(size) == 0) {
        printf("\nPlease enter again: ");
        scanf("%d", &size);
    }
}



/*
void getSafeString(char *pointer, int maxsize) {

    int indexcur = 0;
    char charcur = '\n';

    while ('\n'==charcur){
        charcur = getc(stdin);
    }
    while (indexcur<(maxsize-1) && '\n'!=charcur)
    {
        if ('\n'!=charcur)
        {
            pointer[indexcur] = charcur;
        }
        indexcur++;
        charcur = getc(stdin);
    }
    pointer[indexcur] = '\0';

    while ('\n'!=charcur)
    {
        charcur = getc(stdin);
    }
}
 */
