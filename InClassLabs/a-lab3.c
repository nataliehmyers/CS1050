// a-lab3.c - A program for calculating the lengths of sides of right triangles.
// Created by Natalie Myers on 9/17/18.

#include <stdio.h>
#include <math.h>

// loops prompt
int selection_function() {
    int user_selection;
    do {
        printf("Right triangle calculation type\n\n(1) Two triangle legs\n(2) One leg one hypotenuse\nPlease make a selection: ");
        scanf("%d", &user_selection);
    } while (user_selection <= 0 || user_selection > 2);
    return user_selection;
}

// performs selected functions
int main() {

    int user_selected_input = selection_function();
    float hyp_leg, hyp_length, hyp_result, repeat_prompt1, repeat_prompt2;
    float first_leg, second_leg, hyp_calc, hyp_leg1_squared, hyp_leg2_squared;
    float missing_leg, hyp_leg_pt1, hyp_hyp_pt2;

    // for when user has two legs to compute
    if (user_selected_input == 1) {
        printf("Enter a length for the first leg: ");
        scanf("%f", &first_leg);
        while (first_leg <= 0 || first_leg > 100) {
            printf("Incorrect value, length should be between 1-100");
            scanf("%f", &first_leg);
        }
        printf("Enter a length for the second leg: ");
        scanf("%f", &second_leg);
        while (second_leg <= 0 || second_leg > 100) {
            printf("Incorrect value, length should be between 1-100");
            scanf("%f", &second_leg);
        }

        // calculations
        hyp_leg1_squared = pow(first_leg, 2);
        hyp_leg2_squared = pow(second_leg, 2);
        hyp_calc = pow(first_leg, 2)+pow(second_leg, 2);
        hyp_result = sqrt(hyp_calc);

        printf("Calculation: %.2f + %.2f = %.2f\n", hyp_leg1_squared, hyp_leg2_squared, hyp_calc);
        printf("Hypotenuse length = %.2f\nDo you wish to calculate again?\nPress 0 for no, 1 for yes: ", hyp_result);
        scanf("%f", &repeat_prompt1);
        if (repeat_prompt1 == 1){
            return selection_function();
        } else {
            return 0;
        }

    // for when user has a side and hypotenuse
    } else if (user_selected_input == 2) {
        printf("Enter a length for the first leg: ");
        scanf("%f", &hyp_leg);
        while (hyp_leg <= 0 || hyp_leg > 100) {
            printf("Incorrect value, length should be between 1-100");
            scanf("%f", &hyp_leg);
        }
        printf("Enter a length for the hypotenuse: ");
        scanf("%f", &hyp_length);
        while (hyp_length <= hyp_leg) {
            printf("Incorrect value, hypotenuse length cannot be less than or equal to leg length");
            scanf("%f", &hyp_length);
        }

        //calculations
        hyp_leg_pt1 = pow(hyp_leg, 2);
        hyp_hyp_pt2 = pow(hyp_length, 2);
        missing_leg = sqrt(hyp_hyp_pt2+hyp_leg_pt1);
        missing_leg_squared = pow(missing_leg, 2);

        printf("Calculation: %.2f + %.2f = %.2f\nMissing leg length = %.2f\nDo you wish to calculate again?"
               "\nPress 0 for no, 1 for yes: ", hyp_leg_pt1, hyp_hyp_pt2, (hyp_leg_pt1+hyp_hyp_pt2), missing_leg);
        scanf("%f", &repeat_prompt2);
        if (repeat_prompt2 == 1) {
            return selection_function();
        } else {
            return 0;
        }
    }
}
