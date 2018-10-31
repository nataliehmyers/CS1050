// a-lab4.c - A program to calculate a student's GPA.
// Created by Natalie Myers on 9/24/18.

#include <stdio.h>
#include <math.h>

int courseNumCheck(int); /* Takes the user input as an argument (integer type) and checks if the number of
courses is greater than 1. Returns 1 if true else 0 */
float getScore(void); // Takes no argument, and Returns the course score input by the user
int getUnit(void); // Takes no argument, and Returns the course score input by the user
int scoreErrorCheck(float); /* Takes the user input as an argument (float type) and checks if the course score is positive or not.
 * Returns 1 if true else 0 */
int unitErrorCheck(int); /* Takes the user input as an argument (integer type) and checks if the course unit is positive or not.
 * Returns 1 if true else 0. If 0 is returned it asks the user to type a number greater than zero. */
int getScorePoint(float); // Takes the course score as an argument (float type) and Returns the score point
void printComment(float); /* Takes the ASP as an argument (float type) and prints the comment associated
with an ASP */
int computeSCU(int, int); // bonus function in progress



int courseNumCheck(int course_total) {
    if (course_total > 1) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    int course_number;
    float temporary_x, score_got, x;
    x = 0;

    printf("========================================\n"
           "STUDENT GPA CALCULATOR\n"
           "========================================\n"
           "Enter the Number of Courses: ");
    scanf("%d", &course_number);
    while (course_number <= 1) {
        printf("Error! Please enter a Number of Courses greater than 1: ");
        scanf("%d", &course_number);
    }
    for (int i = 1; i <= course_number; i++) {
        printf("\nEnter the Student Score for Course %d (Percent): ", i);
        score_got = getScore();
        printf("Enter the Number of Units for course %d: ", i);
        getUnit();
        printf("MULTIPLICATION OF SCP AND CU:\n"); // INCOMPLETE
        temporary_x = getScorePoint(score_got);
        x = temporary_x + x;

        //INCOMPLETE
        // int unit_got = getUnit(); // ???
        // int bonus_score = getScorePoint(score_got);
        // computeSCU(unit_got, bonus_score);
    }
    float average_score_point = x / course_number;
    printComment(average_score_point);
    return 0;
}

float getScore(void) {
    float score;
    scanf("%e", &score);
    while (score < 0 || score > 100) {
        printf("Invalid score! Please try again: ");
        scanf("%f", &score);
    }
    scoreErrorCheck(score);
    return score;
}

int scoreErrorCheck(float score) {
    if (score > 0) {
        return 1;
    } else {
        return 0;
    }
}

int getUnit(void) {
    int units;

    scanf("%d", &units);
    while (units < 0 || units > 4) {
        printf("Invalid Number of Units! Please try again: ");
        scanf("%d", &units);
    }
    unitErrorCheck(units);
    return units;
}

int unitErrorCheck(int units) {
    if (units > 0) {
        return 1;
    } else {
        return 0;
    }
}

int getScorePoint(float score) {

    float point_result;

    if (score >= 95 && score <= 100) {
        point_result = 4;
    } else if (score >= 90 && score <= 94) {
        point_result = 3.5;
    } else if (score >= 85 && score <= 89) {
        point_result = 3;
    } else if (score >= 80 && score <= 84) {
        point_result = 2.5;
    } else if (score >= 75 && score <= 79) {
        point_result = 2;
    } else if (score >= 70 && score <= 74) {
        point_result = 1;
    } else {
        point_result = 0;
    }
    return point_result;
}

void printComment(float average_score_point) {

    printf("\nThe Student GPA: %.2f\n"
           "========================================\n"
           "COMMENT: ", average_score_point);

    if (average_score_point >= 3.8 && average_score_point <= 4.0) {
        printf("Outstanding!!");
    } else if (average_score_point >= 3.5 && average_score_point <= 3.7) {
        printf("Excellent!!");
    } else if (average_score_point >= 3.0 && average_score_point <= 3.49) {
        printf("Good!!");
    } else if (average_score_point >= 2.5 && average_score_point <= 2.99) {
        printf("Satisfactory!!");
    } else if (average_score_point >= 2.0 && average_score_point <= 2.49) {
        printf("Not Satisfactory!!");
    } else {
        printf("Do Better Next Semester.");
    }

    printf("\n========================================");
}

int computeSCU(int score, int units) {
    return score * units;
}