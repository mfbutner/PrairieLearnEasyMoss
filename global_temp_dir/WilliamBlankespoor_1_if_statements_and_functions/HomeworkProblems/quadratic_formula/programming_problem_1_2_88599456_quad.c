#include <stdio.h>
#include <math.h>
//This program calculates the real solutions to a quadratic equation


/* This function calculates the discriminant of a quadratic equation
@param a the coefficient for x squared
@param b the coefficient for x
@param c the constant
@return the discriminant calculated from a, b, and c
*/
double calcDiscriminant(double a, double b, double c) {
    return pow(b, 2) - (4 * a * c);
}

/* This fuction calculates the solution using the plus of the +/- in the quadratic equation
@param a the coefficient for x squared
@param b the coefficient for x
@param c the constant
@return the calculated solution
*/
double solutionForPlus(double a, double b, double c) {
    return (-b + sqrt(calcDiscriminant(a, b, c))) / (2 * a);
}

/* This fuction calculates the solution using the minus of the +/- in the quadratic equation
@param a the coefficient for x squared
@param b the coefficient for x
@param c the constant
@return the calculated solution
*/
double solutionForMinus(double a, double b, double c) {
    return (-b - sqrt(calcDiscriminant(a, b, c))) / (2 * a);
}



int main() {
    //Doubles to store the coefficients
    double a = 0;
    double b = 0;
    double c = 0;

    //Get inputs from the user
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    //If/else if chain uses the discriminant to determine the number of solutions and proceed appropriately
    double discriminant = calcDiscriminant(a, b, c);
    if(discriminant < 0) {
        printf("There are no real solutions\n");
    }
    else if(discriminant == 0) {
        printf("There is one real solution: %.2lf\n", solutionForPlus(a, b, c));
    }
    else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solutionForPlus(a, b, c));
        printf("Solution 2: %.2lf\n", solutionForMinus(a, b, c));
    }

    return 0;
}