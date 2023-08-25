#include <stdio.h>
#include <math.h>
// it uses the quadratic formula to find the solution of quadratic formula.
void calcQuadFormula(double a, double b, double c); // This function uses the quadratic equations. The parameters are the coefficients needed to use the quadratic formula.
double calcDiscriminant(double a, double b, double c); // This function calculate the discriminat of a quadratic formula. The parameters are the coefficients needed to use the quadratic formula.
int main()
{
    double a = 0, b = 0, c = 0;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("\nPlease enter b: ");
    scanf("%lf", &b);
    printf("\nPlease enter c: ");
    scanf("%lf", &c);
    calcQuadFormula(a, b, c);
    return 0;
}

void calcQuadFormula(double a, double b, double c)
{

    if (calcDiscriminant(a, b, c) > 0)
    { // two solutions
        double result1 = (-b + sqrt(calcDiscriminant(a, b, c))) / (2.0 * a);
        double result2 = (-b - sqrt(calcDiscriminant(a, b, c))) / (2.0 * a);
        printf("\nThere are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", result1);
        printf("Solution 2: %.2lf\n", result2);
    }
    else if (calcDiscriminant(a, b, c) == 0)
    { // one solution
        double result1 = (-b + sqrt(calcDiscriminant(a, b, c))) / (2.0 * a);
        printf("\nThere is one real solution: %.2lf\n", result1);
    }
    else
    { // no solution
        printf("\nThere are no real solutions\n");
    }
}

double calcDiscriminant(double a, double b, double c)
{
    return pow(b, 2) - (4 * a * c); // this the discrimant
}
