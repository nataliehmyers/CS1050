/* a-lab2.c - Reads two non-negative numbers from the user and then performs various
 * arithmetic operations using the two variables. */
// Created by Natalie Myers on 9/10/18.

#include <stdio.h>
#include <math.h>

int main(void){

    int num1, num2, sum, difference, product, quotient; // sets variables
    float num3, root; // define variables

    printf("Enter the first number: "); // prompts user
    scanf("%d", &num1); // assigns value

    if (num1>0){ // checks value is positive
        printf("\n"); // moves on
    }

    while (num1<0){ // adds contingency for negative number
        printf("Enter a non-negative number: "); // prompts user again
        scanf("%d", &num1); // assigns value again

        if (num1>0){ // checks value is positive
            printf("\n"); // moves on
        }
    }

    printf("Enter the second number: "); // prompts user
    scanf("%d", &num2); // assigns value

    while (num2==0){ //checks for division by 0
        printf("Cannot divide by 0!\nEnter a new number: "); // prompts user again
        scanf("%d", &num2); // assigns value again

        if (num2 != 0){ // checks value is not 0
            printf("\n"); // moves on
        }
    }

    if (num2>0){ // checks number is positive
        printf("\n"); // moves on
    }

    while (num2<0){ // adds contingency for negative number
        printf("Enter a non-negative number: "); // prompts user again
        scanf("%d", &num2); // assigns value again

        if (num2>0){ // checks value is positive
            printf("\n"); // moves on
        }
    }

    sum = num1 + num2; // assigns sum value
    difference = num1 - num2; // assigns difference value
    product = num1*num2; // assigns product value
    quotient = num1 / num2; // assigns quotient value

    printf("ADDITION\n"); // prints header
    printf("The sum of %d and %d is %d.\n\n", num1, num2, sum); // prints body
    printf("SUBTRACTION\n"); // prints header
    printf("The difference of %d and %d is %d.\n\n", num1, num2, difference); // prints body
    printf("MULTIPLICATION\n"); // prints header
    printf("The product of %d and %d is %d.\n\n", num1, num2, product); // prints body
    printf("DIVISION\n"); // prints header
    printf("%d divided by %d is %d.\n\n", num1, num2, quotient); // prints body

    if (num1>num2){ // checks for larger number
        printf("%d is the bigger number\n\n", num1); // prints larger number statement
    }

    if (num2>num1){ // checks for larger number
        printf("%d is the bigger number\n\n", num2); // prints larger number statement
    }

    printf("Enter a number for the square root operation: "); // prompts user
    scanf("%f", &num3); // assigns value

    root = sqrt(num3); // assigns root value

    if (num3>0){ // checks number is positive
        printf("The square root of %0.1f is %0.2f", num3, root); // prints root statement
    }

    while (num3<0){ // adds contingency for negative number
        printf("Cannot take the square root of a negative number.\nTry again: "); // prompts user again
        scanf("%f", &num3); // assigns variable again

        if (num3>0){ //checks n umber is positive
            printf("The square root of %0.1f is %0.2f", num3, root); //prints root statement
        }
    }

    return 0;
}