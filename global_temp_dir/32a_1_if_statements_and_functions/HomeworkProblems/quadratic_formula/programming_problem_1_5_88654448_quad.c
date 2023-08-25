// Made by the collaboration of Sukhraj Johal and Sky Zhao
// Finds the solution of quadratic eqautions using the quadratic formula

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// calculates the solution of the positve root
double getSolutionPlus(double calcA, double calcB, double calcC) {
    double numerator1;
    double numerator2Plus; 
    double denominator;
    double finalSolutionPlus;

    // the plus and minus fucntions were done differently because the plus func
    // wasn't calculating properly. So we rewrote it differently and it worked.
    numerator1 = -1 * calcB;
    
    numerator2Plus = calcB * calcB - 4 * calcA * calcC;

    denominator = 2 * calcA; 

    finalSolutionPlus = (numerator1 + sqrt(numerator2Plus)) / denominator; 
       

    return finalSolutionPlus;
}

// calculates the solution of the negative root
double getSolutionMinus(double calcA, double calcB, double calcC) {
    double numerator1;
    double numerator2Minus;
    double denominator;
    double finalSolutionMinus;

    numerator1 = -1 * calcB;
    
    numerator2Minus = sqrt((pow(calcB, 2)) - (4 * calcA * calcC));

    denominator = 2 * calcA; 
       
    finalSolutionMinus = (numerator1 - numerator2Minus) / denominator;

    return finalSolutionMinus;
}


int main(){
/* calulate the quadratic formula */
double a;
double b;
double c;
double solutionPlus;
double solutionMinus;
double solutionNumerator;

// asking for input
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

printf("Please enter a: ");
scanf("%lf", &a);

printf("Please enter b: ");
scanf("%lf", &b);

printf("Please enter c: ");
scanf("%lf", &c);

solutionNumerator = (b * b) - (4 * a * c);

if (solutionNumerator > 0) { // checking to see if the root is positve cuz of math stuff
    solutionPlus = getSolutionPlus(a, b, c);
    solutionMinus = getSolutionMinus(a, b, c);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", solutionPlus);
    printf("Solution 2: %.2lf\n", solutionMinus);
} 
else if (solutionNumerator == 0) { // checking to see if its equal to zero cuz math
    solutionPlus = (-1 * b) / (2 * a);
    printf("There is one real solution: %.2lf", solutionPlus);
} 
else { // if its negative then there are no solutions cuz math
    printf("There are no real solutions");
}
    return 0;
}