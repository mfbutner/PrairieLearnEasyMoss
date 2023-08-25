//find roots of the quadratic equation using the formula
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double onesolution(double a,double b)
//double function
//returns r1
//takes coefficient a and b as parameters
{
    double r1;
    r1 = -b / (2 * a);
    return r1;
}
int main (void) 
{
 //main function
 //takes void as parameter
 //performs the calculations
double a, b, c, disc, r1, r2;

printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf("%lf",&a);

printf("Please enter b: ");
scanf("%lf",&b);

printf("Please enter c: ");
scanf("%lf",&c);

disc=b*b-(4*a*c);

if (disc > 0) {
        r1 = (-b + sqrt(disc)) / (2 * a);
        r2 = (-b - sqrt(disc)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", r1);
        printf("Solution 2: %.2lf", r2);

    }
    else if (disc == 0) {
        r1=onesolution(a,b);
        printf("There is one real solution: %.2lf", r1);
    }
    else {
        printf("There are no real solutions");
    }

    return 0;
}










