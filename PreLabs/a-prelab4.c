/* a-prelab4.c - Calculates  the  Average  Score  Point(ASP)  of  a  student
 * taking  N  courses in  a semester */
// Created by Natalie Myers on 9/20/18.

#include <stdio.h>
#include <math.h>

int courseNumCheck(int); /* Takes the user input as an argument (integer type) and checks if the number of
courses is greater than 1. Returns 1 if true else 0 */
float getScore(void); // Takes no argument, and Returns the course score input by the user
float getScorePoint(float); // Takes the course score as an argument (float type) and Returns the score point
void printComment(float); /* Takes the ASP as an argument (float type) and prints the comment associated
with an ASP */

int courseNumCheck(int course_total) {
    if (course_total > 1) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    int course_number;
    float temperary_x, score_got,x;
    x = 0;

    printf("========================================\n"
           "STUDENT ASP CALCULATOR\n"
           "========================================\n"
           "Enter the Number of Courses: ");
    scanf("%d", &course_number);
    while (course_number <= 1) {
        printf("Error! Please enter a Number of Courses greater than 1: ");
        scanf("%d", &course_number);
    }
    for (int i = 1; i<= course_number; i++) {
        printf("Enter the Student Score for Course %d (Percent): ", i);
        score_got = getScore();
        temperary_x = getScorePoint(score_got);
        printf("Point = %.2lf\n", temperary_x);
        x = temperary_x + x;
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
    return score;
}

float getScorePoint(float score) {

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

    printf("The Student ASP: %.2f\n"
           "========================================\n"
           "COMMENT: ", average_score_point);

    if (average_score_point >= 3.8 && average_score_point <= 4.0) {
        printf("Excellent");
    } else if (average_score_point >= 3.5 && average_score_point <= 3.7) {
        printf("Very Good");
    } else if (average_score_point >= 3.0 && average_score_point <= 3.49) {
        printf("Good");
    } else if (average_score_point >= 2.5 && average_score_point <= 2.99) {
        printf("Satisfactory");
    } else if (average_score_point >= 2.0 && average_score_point <= 2.49) {
        printf("Not Passed");
    } else {
        printf("Unofficial Drop");
    }

    printf("\n========================================");
}
