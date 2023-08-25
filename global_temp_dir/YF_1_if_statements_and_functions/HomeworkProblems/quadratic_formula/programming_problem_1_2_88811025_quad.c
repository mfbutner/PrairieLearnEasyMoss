//This program solves a quadratic equation given by the user.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // Initializing a, b, and c
    double a;
    double b;
    double c;
    double val; // b^2 - 4ac
    double sol1; //First solution
    double sol2; //Second solution

    //Provide the quadratic equation form ax^2 + b x + c.
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    //Ask the user to enter a, b, c respectively.
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    //Calculate b^2 - 4ac to determine the number of solutions
    val = pow(b, 2) - 4 * a * c;

    //No solution
    if (val < 0) {
        printf("There are no real solutions\n"); //Result: no solution
        exit(0); //Exit the program
    }

    //At least 1 solution
    sol1 = (-b + sqrt(val)) / (2 * a); //Calculate the first solution
    //Exactly one solution
    if (val == 0) {
        printf("There is one real solution: %.2lf\n", sol1);
    }
    //Two solutions
    else {
        sol2 = (-b - sqrt(val)) / (2 * a); //Calculate the second solution
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", sol1);
        printf("Solution 2: %.2lf\n", sol2);
    }

    return 0;
}
