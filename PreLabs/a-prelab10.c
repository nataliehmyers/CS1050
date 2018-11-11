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
// void getSafeString(char *, int); - unused function

int main(void) {
    int size;
    char *pointer = malloc(sizeof(char) * MAX); // allocates space in memory

    size = getString(pointer); // calls primary function that returns end result
    printf("\nYou entered: %s which is size %d\n", pointer, size); // prints end result
}

int getString(char *pointer) {
    int size;

    printf("Enter the size of the string: ");
    scanf("%d", &size);
    while (errorCheck(size) == 0) { // pulls return value from error check function
        printf("\nPlease enter again: ");
        scanf("%d", &size);
    }
    printf("\nPlease enter the string: ");
    scanf("%20s", pointer);
    while (strlen(pointer) > size) { // checks if string size is larger than assigned value
        printf("\nThe string entered is longer than the allowed size\n"
               "\nPlease enter a valid string: ");
        scanf("%20s", pointer);
    }
    while (checkString(pointer, size) == 0) { // checks for any invalid characters in string
        printf("\nPlease enter a valid string: ");
        scanf("%20s", pointer);

        while (strlen(pointer) > size) { /* checks new string for length if it had invalid
                                        * characters going into the first while loop */
            printf("\nThe string entered is longer than the allowed size\n"
                   "\nPlease enter a valid string: ");
            scanf("%20s", pointer);
        }
    }
    size = strlen(pointer); // assigns size to the size of the result string
    return size;
}

int errorCheck(int size) {
    if (size < 1 || size > 20) { // checks if size is invalid
        return 0;
    }
    return 1;
}

int checkString(char *pointer, int size) {
    int i;
    for (int i = 0; i < size; i++) { // iterates through string
        *(pointer + i) = toupper(*(pointer + i));
    }
    for (i = 0; i < size; i++) { // iterates through string
        if ((*(pointer + i) < 65 || *(pointer + i) > 90) && *(pointer + i) != '\0') { // makes string all uppercase
            return 0;
        }
    }
    return 1;
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
