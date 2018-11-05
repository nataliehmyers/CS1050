/* a-prelab10.c - Uses malloc function to allocate space (to store the string)
 * instead of creating fixed size character array */
// Created by Natalie Myers on 11/4/18

#include <stdio.h>
#include <ctype.h>
#define MAX 20

int getString(char *);
int checkString(char*, int);
int errorCheck(int);

int main(void) {
    char array[MAX];
    char *pointer = array;

    getString(*pointer);
}

int getString(char *pointer) {
    int size;
    char string[MAX];

    printf("Enter the size of the string: ");
    scanf("%d", &size);
    errorCheck(size);
    printf("Please enter the string: ");
    scanf("%s", &string);
    printf("%s", string);
    // checkString()
}

int errorCheck(int size) {
    while (size < 1 || size > 20) {
        printf("Please enter again: ");
        scanf("%d", &size);
    }
}

int checkString(char *pointer, int string) {

}

/*
void getSafeString(char *string, int maxsize) {

    int indexcur = 0;
    char charcur = '\n';

    while ('\n'==charcur){
        charcur = getc(stdin);
    }
    while (indexcur<(maxsize-1) && '\n'!=charcur)
    {
        if ('\n'!=charcur)
        {
            string[indexcur] = charcur;
        }
        indexcur++;
        charcur = getc(stdin);
    }
    string[indexcur] = '\0';

    while ('\n'!=charcur)
    {
        charcur = getc(stdin);
    }
}
*/