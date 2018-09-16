// a-prelab3.c - A C program that performs area calculation based on user choice.
// Created by Natalie Myers on 9/13/18.

#include <stdio.h>
#include <math.h>

int selection_function() {
    int user_selection;
    do{
        printf("Area calculation\n(1) Square\n(2) Cube\n(3) Circle\nPlease make a selection: ");
        scanf("%d", &user_selection);
    } while(user_selection <= 0 || user_selection > 3);
    return user_selection;
}

int main() {

    int selected_calculation = selection_function();
    int length_square, length_cube, radius;

    if (selected_calculation == 1) {
        printf("Enter a positive number: ");
        scanf("%d", &length_square);
        while (length_square <= 0) {
            printf("Number can't be negative or zero\n");
            scanf("%d", &length_square);
        }
        printf("Length of the side of the square is %d\nArea of the square is %.2f", length_square,
               pow(length_square, 2));
    } else if (selected_calculation == 2) {
        printf("Enter a positive number: ");
        scanf("%d", &length_cube);
        while (length_cube <= 0) {
            printf("Number can't be negative or zero\n");
            scanf("%d", &length_cube);
        }
        printf("Length of the side of the cube is %d\nArea of the cube is %.2f", length_cube,
               (6 * (pow(length_cube, 2))));
    } else if (selected_calculation == 3) {
        printf("Enter a positive number: ");
        scanf("%d", &radius);
        while (radius <= 0) {
            printf("Number can't be negative or zero\n");
            scanf("%d", &radius);
        }
        printf("Radius of circle is %d\nArea of circle is %.2f", radius, (3.14159 * (pow(radius, 2))));
    }
    return 0;
}