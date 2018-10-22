#include <stdio.h>
#define MAX 25

void printMessage(char name[], char num[]);

int main() {

    char name[] = "aaa";
    char num[] = "bbbbbbbbb";
    printMessage(name, num);
}

void printMessage(char name[], char num[]) {
    char message[MAX];
    int i = 0;
    int namei = 0;
    int numi = 0;

    while (1 == 1) {
        if (name[namei] != '\0') {
            message[i] = name[namei];
            namei++;
            i++;
        } if (num[numi] != '\0') {
            message[i] = num[numi];
            numi++;
            i++;
        }
        if (num[numi] == '\0' && name[namei] == '\0') {
            message[i] = '\0';
            break;
        }
    }
    printf("Your e-ticket number is: %s\n\n", message);
}
