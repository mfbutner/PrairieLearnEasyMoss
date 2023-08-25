#include <stdio.h>
#include <math.h>
/*This program asks the user for the coeffiencts they would like to replace as the a, b, and c in the equation ax^2 + b x + c.
It takes these coefficients and uses the quadratic formula to calulate the solutions, returning only the real solution, which
is known by if the discriminant is greater than zero(2), equal to zero(1), or less than zero(none).*/

/*
Calculates the discriminant of the quadratic formula (the number inside the square root)
@a: the first coeffienct (attached to x^2)
@b: the second coefficient (attached to x)
@c: the constant at the end
@returns: the calculated discriminant which is b squared minus a multiplied by 4 and c
*/
double discriminant(double a, double b, double c)
{
    double discrim = (b * b) - (4 * a * c);
    return discrim;
}

/*
Calculates the denominator of the quadratic formula 
@a: the first coeffienct (attached to x^2)
@returns: the denominator, which is a multiplied by 2
*/
double denominator(double a)
{
    double denom = 2 * a;
    return denom;
}



int main()
{
    double a;
    double b;
    double c;
    double solution1;
    double solution2;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c");
    printf("Please enter a: \n");
    scanf("%lf", &a);
    printf("Please enter b: \n");
    scanf("%lf", &b);
    printf("Please enter c: \n");
    scanf("%lf", &c);
    solution1 = ((-b + sqrt(discriminant(a, b, c))) / denominator(a));
    solution2 = ((-b - sqrt(discriminant(a, b, c))) / denominator(a));
    if(discriminant(a, b, c) > 0)
    {

        printf("There are 2 real solutions \n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }
    else if(discriminant(a, b, c) == 0 )
    {
        printf("There is one real solution: %.2lf\n", solution1);
    }
    else
    {
        printf("There are no real solutions\n");
    }
    return 0;
}