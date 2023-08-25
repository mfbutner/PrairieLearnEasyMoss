#include <stdio.h>
#include <math.h>
//this code helps find the solution to the quadratic formula given the three coefficients

// (-b + sqrt(b^2 - 4ac))/ 2a)
double PositiveQuadraticFormula(double a, double b, double c){
    return ((-1 * b + sqrt(pow(b,2) - (4 * a * c))) / (2 * a));
}
// (-b - sqrt(b^2 - 4ac))/ 2a)
double NegativeQuadraticFormula(double a, double b, double c){
    return ((-1 * b - sqrt(pow(b,2) - (4 * a * c))) / (2 * a));
}

// function scans the coefficients to put into the quadratic formula and also outputs if there are 2 solutions, one solution, or no solution
int main(void){
    double coefficientA;
    double coefficientB;
    double coefficientC;
    double positiveResult;
    double negativeResult;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf", &coefficientA);

    printf("Please enter b: ");
    scanf("%lf", &coefficientB);

    printf("Please enter c: ");
    scanf("%lf", &coefficientC);

    positiveResult = PositiveQuadraticFormula(coefficientA, coefficientB, coefficientC);
    negativeResult = NegativeQuadraticFormula(coefficientA, coefficientB, coefficientC);

    if((pow(coefficientB,2) - 4 * coefficientA * coefficientC) < 0){
        printf("There are no real solutions");
    }
    else if(positiveResult == negativeResult){
        printf("There is one real solution: %.2lf", positiveResult);
    }
    else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", positiveResult);
        printf("Solution 2: %.2lf", negativeResult);
    }
    
}
