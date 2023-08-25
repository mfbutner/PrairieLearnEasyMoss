#include <stdio.h>
#include <math.h>
//This program solves for the roots of a quadratic equation using the quadratic formula

//This function only happens if there are 2 solutions and prints out both solutions
//Parameter double a, double b, double c are for plugging into the formula
void quadRootFormula(double a, double b, double c){  
    double positiveFormula = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    double negativeFormula = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", positiveFormula, negativeFormula);
    
}

//This functions say if there is no real solution or one solution if there is 2 solutions calls function quadRootFormula()
//Parameter double a, double b, double c are for plugging into the formula
void numSolutions(double a, double b, double c){
    double innerSqrt = b * b - 4 * a * c;
    if (innerSqrt < 0){
    printf("There are no real solutions\n");
    }
    else if (innerSqrt == 0){
    printf("There is one real solution: %.2lf\n", (-b / (2 * a)));
    }
    else {
    quadRootFormula(a, b, c); //calls quadRootFormula
    }
}

int main() {
double numA, numB, numC;
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

printf("Please enter a: ");
scanf("%lf", &numA);

printf("Please enter b: ");
scanf("%lf", &numB);

printf("Please enter c: ");
scanf("%lf", &numC);

numSolutions(numA, numB, numC); //calls numSolutions

return 0;

}