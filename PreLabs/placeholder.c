/* a-hw1.c - Calculates the monthly Electricity utility bill based on the number
* of units consumed*/
// Created by Natalie Myers on 9/16/18.

#include <stdio.h>
#include <math.h>
#include <getopt.h>

void displayMenu();
int errorCheck(int);
int errorCheckUnits(int);
float getRate(int, int);
int charge(int);

int main() {

    int selection, units, connectionCharge, repeat, timesRepeated, bonusInt, i, bonusCalc;
    float rate, totalBills;
    repeat = 1;
    timesRepeated = 0;
    bonusCalc = 1;

    printf("***** ELECTRICITY BILL CALCULATOR *****");
    while (repeat == 1) {
        displayMenu();
        scanf("%d", &selection);
        while (errorCheck(selection) == 0) {
            printf("Invalid Choice! Please enter a valid choice");
            displayMenu();
            scanf("%d", &selection);
        }
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &units);
        while (errorCheckUnits(units) == 0) {
            printf("Invalid Input!\nEnter the number of units (in kWh): ");
            scanf("%d", &units);
        }
        rate = getRate(units, selection);
        connectionCharge = charge(selection);
        printf("Total energy charge for the customer is: $%.2f\n", (units * (rate / 100)));
        printf("Connection charge for this customer is: $%d\n", connectionCharge);
        printf("Total bill due from this connection is: $%.2f\n", (connectionCharge + (units * (rate / 100))));
        printf("Do you want to continue and calculate another bill?  If Yes enter 1, else 0: ");
        scanf("%d", &repeat);
        timesRepeated += 1;
        totalBills = totalBills + (connectionCharge + (units * (rate / 100)));
    }
    printf("\n\nYou calculated the bill %d times and the total amount from all of the bills due is $%.2f", timesRepeated, totalBills);
    printf("\n\n\n*** BONUS Section ***\nEnter a number: ");
    scanf("%d", &bonusInt);
    while (errorCheckUnits(bonusInt) == 0) {
        printf("Please enter a positive number: ");
        scanf("%d", &bonusInt);
    }
    printf("The numbers are: ");
    for (i = 1; i <= bonusInt; i = i + 1) {
        printf("%d ", i);
    }
    for (i = 1; i <= bonusInt; i = i + 1) {
        bonusCalc = bonusCalc * i;
    }
    printf("\nThe product of all the numbers from 1 to %d is %d", bonusInt, bonusCalc);
    bonusCalc = 1;
    for (i = 1; i <= bonusInt; i = i + 1) {
        if (i % 2 == 0) {
            bonusCalc = bonusCalc * i;
        }
    }
    printf("\nThe product of all the even numbers is %d", bonusCalc);
    bonusCalc = 1;
    for (i = 1; i <= bonusInt; i = i + 1) {
        if (i % 2 == 1) {
            bonusCalc = bonusCalc * i;
        }
    }
    printf("\nThe product of all the odd numbers is %d", bonusCalc);
    return 0;
}

void displayMenu() {
    printf("\n\n1. Residential\n2. Commercial\n3. Industrial\n\n"
           "Choose the type of connection: ");
}

int errorCheck(int option) {
    if (option <= 0 || option > 3) {
        return 0;
    }
    return 1;
}

int errorCheckUnits(int units) {
    if (units < 0) {
        return 0;
    }
    return 1;
}

float getRate(int units, int option) {

    if (option == 1) {
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

    if (option == 2) {
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

    if (option == 3) {
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

int charge(int option) {

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



-------------------------------------------



#include <stdio.h>
#include <math.h>

void displayMenu(float, float, float);
int errorCheck(int);
int errorCheckUnits(int);
float getRate(int, int);
int charge(int);
int intro_function();
float function_flow(int);


int main(void) {
    function_flow(intro_function());
    // displayMenu();
}

void displayMenu(float total_energy, float charge, float bill) {

    // energy_charge = units * (rate / 100);
    // total_bill = energy_charge + connection_charge;

    printf("Total energy charge for the customer is: $%.2f\n", total_energy);
    printf("Connection charge for the customer is: $%.2f\n", charge);
    printf("Total bill due from this connection is: $%.2f\n", bill);
}

int errorCheck(int units) {
    if (units < 0) {
        return 0;
    } else {
        return 1;
    }
}




float getRate(int units, int option) {
}


int charge(int option){
}


int intro_function() {

    int selected_calculation;
    printf("***** ELECTRICITY BILL CALCULATOR *****\n\n\n1. Residential\n2. Commercial\n"
           "3. Industrial\n\n\nChoose the type of connection: ");
    scanf("%d", &selected_calculation);
    while (selected_calculation <= 0 || selected_calculation > 3) {
        printf("Invalid Choice! Please enter a valid choice\n\n\n1. Residential\n2. Commercial\n"
               "3. Industrial\n\n\nChoose the type of connection: ");
        scanf("%d", &selected_calculation);
    }
    return selected_calculation;
}








/*

float function_flow (int option) {

    int kWh;
    int answer = 1;
    float rate;

    if (option == 1) { // Residential sequence
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &kWh);
        while (answer == 1) {
            if (kWh > 0 && kWh <= 200) {
                rate = 7.50;
                answer = 0;
            } else if (kWh > 200 && kWh <= 700) {
                rate = 10;
                answer = 0;
            } else if (kWh > 700 && kWh <= 1250) {
                rate = 13.50;
                answer = 0;
            } else if (kWh > 1250) {
                rate = 15;
                answer = 0;
            } else {
                while (kWh <= 0) {
                    printf("Invalid input!\nEnter the number of units (in kWh): ");
                    scanf("%d", &kWh);
                }
            }
        }
    }

    if (option == 2) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &kWh);
        while (answer == 1) {
            if (kWh > 0 && kWh <= 300) {
                rate = 10.50;
                answer = 0;
            } else if (kWh > 300 && kWh <= 1000) {
                rate = 14;
                answer = 0;
            } else if (kWh > 1000 && kWh <= 2000) {
                rate = 17.50;
                answer = 0;
            } else if (kWh > 2000) {
                rate = 20;
                answer = 0;
            } else {
                while (kWh <= 0) {
                    printf("Invalid input!\nEnter the number of units (in kWh): ");
                    scanf("%d", &kWh);
                }
            }
        }
    }

    if (option == 3) {
        printf("Enter the number of units (in kWh): ");
        scanf("%d", &kWh);
        while (answer == 1) {
            if (kWh > 0 && kWh <= 500) {
                rate = 36.50;
                answer = 0;
            } else if (kWh > 500 && kWh <= 2000) {
                rate = 40;
                answer = 0;
            } else if (kWh > 2000 && kWh <= 3000) {
                rate = 45.50;
                answer = 0;
            } else if (kWh > 3000) {
                rate = 50;
                answer = 0;
            } else {
                while (kWh <= 0) {
                    printf("Invalid input!\nEnter the number of units (in kWh): ");
                    scanf("%d", &kWh);
            }
        }
    }

    return rate;
    }
}

*/