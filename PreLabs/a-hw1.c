/* a-hw1.c - Calculates the monthly Electricity utility bill based on the number
* of units consumed*/
// Created by Natalie Myers on 9/16/18.

#include <stdio.h>
#include <math.h>

void displayMenu(float, float, float);
int first_function(int);
int errorCheck(int);

int main(void) {
    int selected_calculation;
    do {
        printf("***** ELECTRICITY BILL CALCULATOR *****\n\n\n1. Residential\n2. Commercial\n"
               "3. Industrial\n\n\nChoose the type of connection: ");
        scanf("%d", &selected_calculation);
    } while (selected_calculation <= 0 || selected_calculation > 3);
    printf("Invalid Choice! Please enter a valid choice ");
    return 0;
}

void displayMenu(float total_energy, float charge, float bill) {

    printf("Total energy charge for the customer is: $%.2f", total_energy);
    printf("Connection charge for the customer is: $%.2f", charge);
    printf("Total bill due from this connection is: $%.2f", bill);
}

int first_function(int units) {

    int chosen_function = main();
    if (chosen_function == 1) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", units);
        while (units <= 0) {
            printf("Invalid input!");
        }
    }
    return units;
}

int errorCheck(int units) {
    if (units < 0) {
        return 0;
    } else {
        return 1;
    }
}

float getRate(int units, )






































//---------------------------------------------------------------------------------------------

/*

#include <stdio.h>
#include <math.h>

void displayMenu();
int selected_function();
int choice1_function();
int choice2_function();
int choice3_function();

void displayMenu() {
    printf("Total energy charge for the customer is: $%.2f", );
    printf("Connection charge for the customer is: $%.2f", );
    printf("Total bill due from this connection is: $%.2f", );
}

int selected_function() {
    int selected_calculation;
    do {
        printf("***** ELECTRICITY BILL CALCULATOR *****\n\n\n1. Residential\n2. Commercial\n"
               "3. Industrial\n\n\nChoose the type of connection: ");
        scanf("%d", &selected_calculation);
    } while (selected_calculation <= 0 || selected_calculation > 3);
    printf("Invalid Choice! Please enter a valid choice ");
    return selected_calculation;
}

int choice1_function() {

    int calc_choice1 = selected_function();
    int num_units_choice1, continue_select_function1;
    float total_energy_charge1, connection_charge1, total_bill1;

    if (calc_choice1 == 1) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &num_units_choice1);
        while (num_units_choice1 <= 0) {
            printf("Invalid input!");
            return choice1_function();
        }
    }
    printf("Do you want to continue and calculate another bill?\nIf Yes enter 1, else 0: ");
    scanf("%d", &continue_select_function1);
    if (continue_select_function1 == 1) {
        return selected_function();
    } else {
        return 0;
    }
}

int choice2_function() {

    int calc_choice2 = selected_function();
    int num_units_choice2, continue_select_function2;
    float total_energy_charge2, connection_charge2, total_bill2;

    if (calc_choice2 == 2) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &num_units_choice2);
        while (num_units_choice2 <= 0) {
            printf("Invalid input!");
            return choice2_function();
        }
    }
    printf("Do you want to continue and calculate another bill?\nIf Yes enter 1, else 0: ");
    scanf("%d", &continue_select_function2);
    if (continue_select_function2 == 1) {
        return selected_function();
    } else {
        return 0;
    }
}

int choice3_function() {

    int calc_choice3 = selected_function();
    int num_units_choice3, continue_select_function3;
    float total_energy_charge3, connection_charge3, total_bill3;

    if (calc_choice3 == 3) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &num_units_choice3);
        while (num_units_choice3 <= 0) {
            printf("Invalid input!");
            return choice3_function();
    }
        printf("Do you want to continue and calculate another bill?\nIf Yes enter 1, else 0: ");
        scanf("%d", &continue_select_function3);
        if (continue_select_function3 == 1) {
            return selected_function();
        } else {
            return 0;
        }
    }
}

// total_energy_charge = num_units_choice*()...

if ()

    */