#include <stdio.h>
#include <math.h>

int main (){
    double aVal;
    double bVal;
    double cVal;
    double inSqrt;
    double discriminant (double a, double b, double c);

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &aVal);

    printf("Please enter b: ");
    scanf("%lf", &bVal);

    printf("Please enter c: ");
    scanf("%lf", &cVal);

    inSqrt = discriminant(aVal, bVal, cVal);

    if(inSqrt < 0){
        printf("There are no real solutions\n");

    } else if (inSqrt == 0){
        double onlySolution = (-1 * bVal)/(2 * aVal);
        printf("There is one real solution: %.2lf\n", onlySolution);

    } else {
        printf("There are 2 real solutions \n");

        double firstSolution = (((-1 * bVal) + (sqrt(inSqrt)))/(2 * aVal));
        double secondSolution = (((-1 * bVal) - (sqrt(inSqrt)))/(2 * aVal));

        printf("Solution 1: %.2lf\n", firstSolution);
        printf("Solution 2: %.2lf\n", secondSolution);
    }

    
}

double discriminant(double a, double b, double c){
    double solution = (pow(b, 2) - (4 * a * c));
    return solution;
}
