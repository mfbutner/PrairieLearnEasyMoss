#include <stdio.h>
#include <math.h>

/*
Function that calculates the roots of the quadratic equation
a * x^2 + b * x + c = 0

Inputs:
- a: coefficient of x^2
- b: coefficient of x
- c: constant term

Output:
- Returns the roots through the pointers x1 and x2 (if they exist)
*/


void quad(double a, double b, double c,double x1, double x2)
{
    double disc = b * b - 4 * a * c;
    
    // Checking if values of roots are real or imaginary and then printing result according to inferences
    if (disc < 0) {
        printf("There are no real solutions\n");
    } else if (disc == 0) 
    {
        x1 = -b / (2 * a);
        printf("There is one real solution: %0.2lf",x1);
    } else {
        double sqrtdisc = sqrt(disc);
        x1 = (-b + sqrtdisc) / (2 * a);
        x2 = (-b - sqrtdisc) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %0.2lf\n", x1);
        printf("Solution 2: %0.2lf\n", x2);
    }
}

int main() 
{
    //declaring variables
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    // Taking input
    printf("Please enter a:");
    scanf("%lf",&a);
    printf("Please enter b:");
    scanf("%lf",&b);
    printf("Please enter c:");
    scanf("%lf",&c);
    
    quad(a,b,c,x1,x2);

}
