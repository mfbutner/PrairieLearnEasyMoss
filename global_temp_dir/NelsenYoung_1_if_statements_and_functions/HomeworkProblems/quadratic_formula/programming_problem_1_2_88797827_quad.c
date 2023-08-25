#include <stdio.h>
#include <math.h>

/* This program will take 3 numbers as inputs and use the quadratic formula
to find the solutions for x.
*/
double SolvePositiveQuadraticEquation(double a, double b, double c) {
    double x = ((-b) + sqrt((pow(b, 2) - 4 * a * c)))/ (2 * a);

    return x;
}

double SolveNegativeQuadraticEquation(double a, double b, double c) {
    double x = (-b - sqrt((pow(b, 2) - 4 * a * c)))/ (2 * a);

    return x;
}

int main() {
    double a, b, c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);

    //Checks to see if there will be a negative within the square root.
    double simplifiedRoot = pow(b, 2) - 4 * a * c;

    if(simplifiedRoot < 0){
        printf("There are no real solutions\n");

    }else if(SolvePositiveQuadraticEquation(a, b, c) == SolveNegativeQuadraticEquation(a, b, c)){
        printf("There is one real solution: %.2lf\n", SolvePositiveQuadraticEquation(a, b, c));
    
    }else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", SolvePositiveQuadraticEquation(a, b, c));
        printf("Solution 2: %.2lf\n", SolveNegativeQuadraticEquation(a, b, c));
    }
return 0;
}