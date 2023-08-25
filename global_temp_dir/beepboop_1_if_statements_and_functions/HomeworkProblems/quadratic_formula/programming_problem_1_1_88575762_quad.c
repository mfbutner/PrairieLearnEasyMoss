//! tuukka virtanen, 30-1-23
//? This program solves quadratic equations using the quadratic formula.

#include <stdio.h>
#include <math.h>


double calc_discr(double a, double b, double c) {
    /*
    Calculates the value of the discriminant of a quadratic equation.
    @a: a value of quadratic equation.
    @b: b value of quadratic equation.
    @c: c value of quadratic equation.
    @return: Returns the value of the discriminant.
    */
    return (pow(b, 2) - 4 * a * c);
}

int main(void) {

    double a, b, c;
    double x1, x2;

    printf("Given a quadratic equation of the form ax^2 + b x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);


    double discriminant = calc_discr(a, b, c);

    if (discriminant < 0) {
        printf("There are no real solutions\n");
    }
    else if (discriminant > 0){
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\nSolution 2: %.2lf\n", x1, x2);
    }
    else {
        x1 = (-b / 2 * a);
        printf("There is one real solution: %.2lf\n", x1);
    }

    return 0;
}


// gcc -Wall -Werror -Wextra -o quad.out quad.c -lm