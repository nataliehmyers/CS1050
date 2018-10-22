/* a-hw1.c - Calculates the monthly Electricity utility bill based on the number
* of units consumed*/
// Created by Natalie Myers on 9/16/18.

#include <stdio.h>
#include <math.h>

void displayMenu();
int errorCheck(int);
int errorCheckUnits(int);
float getRate(int, int);
int charge(int);


int main() {

    int selection, units, connectionCharge, repeat, timesRepeated, bonusInt, i, bonusCalc;
    float rate;
    float totalBills = 0;
    repeat = 1;
    timesRepeated = 0;
    bonusCalc = 1;

    printf("***** ELECTRICITY BILL CALCULATOR *****");
    while (repeat == 1) {
        displayMenu(); // prints options
        scanf("%d", &selection);
        while (errorCheck(selection) == 0) { // calls check for valid input
            printf("Invalid Choice! Please enter a valid choice");
            displayMenu(); // prints options
            scanf("%d", &selection);
        }
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &units);
        while (errorCheckUnits(units) == 0) { // calls check for valid input
            printf("Invalid Input!\nEnter the number of units (in kWh): ");
            scanf("%d", &units);
        }
        rate = getRate(units, selection); // calls rate function
        connectionCharge = charge(selection); // calls for connection charge
        printf("Total energy charge for the customer is: $%.2f\n", (units * (rate / 100)));
        printf("Connection charge for this customer is: $%d\n", connectionCharge);
        printf("Total bill due from this connection is: $%.2f\n", (connectionCharge + (units * (rate / 100))));
        printf("Do you want to continue and calculate another bill?  If Yes enter 1, else 0: "); // repeat prompt
        scanf("%d", &repeat);
        timesRepeated += 1; // increments equation counter by 1
        totalBills = totalBills + (connectionCharge + (units * (rate / 100))); // sums total
    }
    printf("\n\nYou calculated the bill %d times and the total amount from all of the bills due is $%.2f", timesRepeated, totalBills);
    printf("\n\n\n*** BONUS Section ***\nEnter a number: ");
    scanf("%d", &bonusInt);
    while (errorCheckUnits(bonusInt) == 0) { // checks for valid input
        printf("Please enter a positive number: ");
        scanf("%d", &bonusInt);
    }
    printf("The numbers are: "); // bonus print
    for (i = 1; i <= bonusInt; i = i + 1) { // increments bonus int by 1
        printf("%d ", i);
    }
    for (i = 1; i <= bonusInt; i = i + 1) { // factorial of bonus int
        bonusCalc = bonusCalc * i;
    }
    printf("\nThe product of all the numbers from 1 to %d is %d", bonusInt, bonusCalc);
    bonusCalc = 1;
    for (i = 1; i <= bonusInt; i = i + 1) { // product of even ints
        if (i % 2 == 0) {
            bonusCalc = bonusCalc * i;
        }
    }
    printf("\nThe product of all the even numbers is %d", bonusCalc);
    bonusCalc = 1;
    for (i = 1; i <= bonusInt; i = i + 1) { // product of odd ints
        if (i % 2 == 1) {
            bonusCalc = bonusCalc * i;
        }
    }
    printf("\nThe product of all the odd numbers is %d", bonusCalc);
    return 0;
}

void displayMenu() { // shows options
    printf("\n\n1. Residential\n2. Commercial\n3. Industrial\n\n"
           "Choose the type of connection: ");
}

int errorCheck(int option) { // checks if menu choice is valid
    if (option <= 0 || option > 3) {
        return 0;
    }
    return 1;
}

int errorCheckUnits(int units) { // checks for positive values
    if (units < 0) {
        return 0;
    }
    return 1;
}

float getRate(int units, int option) { // returns rate

    if (option == 1) { // for residential
        if (units >= 0 && units <= 200){
            return 7.50;
        } else if (units <= 700) {
            return 10;
        } else if (units <= 1250) {
            return 13.50;
        } else {
            return 15;
        }
    }

    if (option == 2) { // for commercial
        if (units >= 0 && units <= 300) {
            return 10.50;
        } else if (units <= 1000) {
            return 14;
        } else if (units <= 2000) {
            return 17.50;
        } else {
            return 20;
        }
    }

    if (option == 3) { // for industrial
        if (units >= 0 && units <= 500) {
            return 36.50;
        } else if (units <= 2000) {
            return 40;
        } else if (units <= 3000) {
            return 45.50;
        } else {
            return 50;
        }
    }

}

int charge(int option) { // flat rate charge

    if (option == 1) {
        return 25;
    }
    if (option == 2) {
        return 90;
    }
    if (option == 3) {
        return 850;
    }
}