#include <stdio.h>
#include <math.h>

/* This program is to solve the roots of quadratic equation */

//Function determine the value of discriminant
double Discriminant(double a, double b, double c) {
   double valueD = b * b - 4 * a * c; //Function of discriminant to determine how many roots the quadratic equations have

   return valueD;
}

int main(void) {
    double A;
    double B;
    double C;
    double root1;
    double root2;
    double root3;
    double D;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &A);
    printf("Please enter b: ");
    scanf("%lf", &B);
    printf("Please enter c: ");
    scanf("%lf", &C);

    D = Discriminant(A, B, C); //return value from function Discriminant
    root1 = (-B + sqrt(D)) / (2 * A);
    root2 = (-B - sqrt(D)) / (2 * A);
    root3 = -B / (2 * A);

    if (D > 0) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root1);
        printf("Solution 2: %.2lf\n", root2);
    }
    else if (D == 0) {
        printf("There is one real solution: %.2lf", root3);
    }
    else {
        printf("There are no real solutions");

    }

    return 0;
}
