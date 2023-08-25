#include <stdio.h>
#include <math.h>

//declaring functions
void userInput(double *a, double *b, double *c);
void calculateQuadFormula(double a, double b, double c);

int main() {
    double a;
    double b;
    double c;

    userInput(&a, &b, &c);

    calculateQuadFormula(a, b, c);
    return 0;
}

// gets the user input and stores them 
void userInput(double *a, double *b, double *c) {
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", a);
    printf("Please enter b: ");
    scanf("%lf", b);
    printf("Please enter c: ");
    scanf("%lf", c);
}

// makes a positivie and negative solution
 
void calculateQuadFormula(double a, double b, double c) {
    double positiveSolution = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double negativeSolution = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    // checks the solution and output the answer depending on 3 factors 
    if (isnan(negativeSolution) && isnan(positiveSolution)) {
        printf("There are no real solutions\n");
    } else if (negativeSolution == positiveSolution) {
        printf("There is one real solution: %.2f\n", positiveSolution);
    } else if(negativeSolution != positiveSolution) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", positiveSolution);
        printf("Solution 2: %.2f\n", negativeSolution);
    }
}