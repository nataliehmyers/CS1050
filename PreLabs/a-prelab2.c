/* a-prelab2.c - Reads two non-negative integer numbers from
the user and then perform arithmetic operations using these two variables.*/
// Authored by Natalie Myers


#include <stdio.h>

int main(void){

    int num1, num2, sum, product;

    printf("Enter the first number: "); // prompts user
    scanf("%d", &num1); // reads input and assigns to variable

    if (num1>0){ // checks number is positive
        printf("\n"); // if positive, moves on
    }

    while (num1<0){ // adds contingency for negative number
        printf("Enter a non-negative number: "); // if negative, prompts user again
        scanf("%d", &num1); // reads input
        if (num1>0){ // checks
            printf("\n"); // moves on
        }
    }

    printf("Enter the second number: "); // prompts user
    scanf("%d", &num2); // reads input and assigns to variable

    if (num2>0){ // checks number is positive
        printf("\n"); // if positive, moves on
    }

    while (num2<0){ // adds contingency for negative number
        printf("Enter a non-negative number: "); // if negative, prompts user again
        scanf("%d", &num2); // reads input
        if (num2>0){ // checks
            printf("\n"); // moves on
        }
    }

    sum = num1 + num2;
    product = num1 * num2;

    printf("ADDITION\n"); // labels output
    printf("The sum of %d and %d is %d.\n\n", num1, num2, sum); // prints addition statement

    printf("MULTIPLICATION\n"); // labels output
    printf("The product of %d and %d is %d.\n", num1, num2, product); // prints multiplication statement

    return 0;

}