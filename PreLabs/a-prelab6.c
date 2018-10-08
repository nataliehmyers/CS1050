/* a-prelab6.c - Implements simple functions that initialize a 2D array with
 * random numbers (between 0-9) and displays the numbers stored in the 2D array */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int check_error(int); /* takes an integer number and checks if the number is between 1-20 or
 * not if it is it returns 1 otherwise 0 */
void initialize_2Darray(int[MAX][MAX], int); /* takes an integer number which is the
 * size of the input and initializes the 2D array with random numbers between 0-9 */
void print_2Darray(int[MAX][MAX], int); // prints the content of the 2D array
int findZeros(int[MAX][MAX], int); /* counts the number of zero’s in your 2-D array, returns
the count to the main() */

int main() {
    int parameter;
    int array1[MAX][MAX] = {};
    printf("Enter the size of the 2-D array: "); // prompts user
    scanf("%d", &parameter); // assigns input
    check_error(parameter); // calls error check function
    while (check_error(parameter) == 1) { // creates print function for invalid inputs
        printf("Please enter a value between 1-20 only: ");
        scanf("%d", &parameter);
    }
    initialize_2Darray(array1, parameter); // calls a function to initialize the array
    print_2Darray(array1, parameter); // calls print function for the array
    printf("\n\nThe number of zeros in 2-D Array: %d", findZeros(array1, parameter)); /* prints number
 *                                                        of zeros by calling the tallying function */
}

void initialize_2Darray(int array1[MAX][MAX], int parameter) { // initializes a 2D array
    int i, j;
    srand(time(NULL));
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            array1[i][j] = rand() % 10; // assigns random integers to array values
        }
    }
}

void print_2Darray(int array1[MAX][MAX], int parameter) { // prints the content of the 2D array
    int i, j;
    printf("\nTHE FIRST 2D ARRAY is:\n");
    for (i = 0; i < parameter; i++) {
        printf("\n"); // prints new line for formatting in a square
        for (j = 0; j < parameter; j++) {
            printf("%d ", array1[i][j]); // prints results
        }
    }
}

int findZeros(int array1[MAX][MAX], int parameter) { // tallies zeros in the array
    int x = 0; // sets number of zeros to zero
    int i, j;
    for (i = 0; i < parameter; i++) {
        for (j = 0; j < parameter; j++) {
            if (array1[i][j] == 0) { // checks for zeros
                x += 1; // adds 1 to count for every zero in the array
            }
        }
    }
    return x;
}

int check_error(int parameter) { // error check function
    while (parameter <= 0 || parameter > 20) { // checks for valid input
        return 1;
    }
    return 0;
}
