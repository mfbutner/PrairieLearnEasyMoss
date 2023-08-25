/*
A quadratic equation is an equation in the form (ax^2 + bx + c)
Program to ask the user for a, b, and c and then displays the real roots of x if there are any.

- Must have at least one function besides main
- print all doubles to 2 decimal points
- inputs can be decimal points
*/
#include <stdio.h>
#include <math.h>           // need for pow() function and sqrt() function

/* function to calculate the discriminant, aids in simplifying calculations and determining number of real solutions
- returns double type discriminant

- first parameter coefficientA is the coefficient A in the quadratic equation
- second parameter coefficientB is the coefficient B in the quadratic equation
- third parameter coefficientC is the coefficient C in the quadratic equation
*/
double calculateDiscriminant(double coefficientA, double coefficientB, double coefficientC) {
    // declare discriminant variable with function-limited scope
    double valDiscriminant;
    
    // calculate discriminant
    valDiscriminant = (pow(coefficientB, 2.0) - (4 * coefficientA * coefficientC));

    return valDiscriminant;
}

/* 
- Compares discriminant to 0 and returns int value 0, 1, or 2 
- return values represent the number of extant real solutions
- function to be called to define an int variable as a flag to decide how to solve the quadratic formula 

- first parameter a_Val is the coefficient A in the quadratic equation
- second parameter b_Val is the coefficient B in the quadratic equation
- third parameter c_Val is the coefficient C in the quadratic equation
*/
int calculateNumRoots(double a_Val, double b_Val, double c_Val){
    // declare variables in scope of function
    double discriminant;                // holds value of discriminant to be calculated from user-given numbers and compared to zero

    // calculate discriminant using coefficients
    discriminant = calculateDiscriminant(a_Val, b_Val, c_Val);

    //compare discriminant to zero
    if (discriminant > 0) {
        return 2;                       // positive discriminant, 2 real solutions
    }
    else if (discriminant == 0) {
        return 1;                       // discriminant equal to zero, 1 real solution
    }
    else {
        return 0;                       // negative discriminant, 0 real solutions
    }
}

int main(){
    // declare variables
    double numA, numB, numC;        // numA, numB, and numC correspond to the coefficients in the equation (ax^2 + bx + c) 
    int numOfRealSolutions;         // Holds int value for how many real solutions there are (0, 1, or 2). Used as condition to calculate solutions  
    double largeRoot;               // Holds value for the larger of the two real roots if there are two real solutions
    double smallRoot;               // Holds value for the smaller of the two real roots if there are two real solutions
    double singleRoot;              // Holds value for the single root if there is one real solution

    // ask user for values of a, b, and c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &numA);

    printf("Please enter b: ");
    scanf("%lf", &numB);

    printf("Please enter c: ");
    scanf("%lf", &numC);

    // determine number of real solutions before calculating roots
    numOfRealSolutions = calculateNumRoots(numA, numB, numC);

    // if-else statement to calculate the root(s), output how many solutions there are, and then output any real solutions

    if (numOfRealSolutions == 2) {              // if there are 2 real solutions
        largeRoot = ((0 - numB) + sqrt(calculateDiscriminant(numA, numB, numC))) / (2 * numA);
        smallRoot = ((0 - numB) - sqrt(calculateDiscriminant(numA, numB, numC))) / (2 * numA);

        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", largeRoot);
        printf("Solution 2: %.2lf\n", smallRoot);
    }
    else if (numOfRealSolutions == 1) {         // if there is 1 real solution
        singleRoot = (0 - numB) / (2 * numA);

        printf("There is one real solution: %.2lf", singleRoot);
    }
    else if (numOfRealSolutions == 0) {         // if there are 0 real solutions
        printf("There are no real solutions\n");
    }
    return 0;                                   // returns 0 for main function
}