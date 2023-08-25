#include <stdio.h>
#include <math.h>

/*This code finds the number of real solutions to a quadratic equation using the quadratic formula. It also gives us the value
of those solutions.*/
double discriminant(double a, double b, double c);
double oneSolution(double a, double b, double c, double numerator, double denominator);
double twoSolution(double a, double b, double c, double numerator, double denominator);

/* This is my main function; all it does is call my other functions and prints out the answers. I coded this function so that
it calls the discriminant function to check whether the discriminant is less than zero, equal to zero, or greater than zero.
Based on the discriminant's value, I used if and else ifs to determine what the function would print. */
int main(void)
{
    double a;
    double b;
    double c;
    double numerator = 0.0;
    double denominator = 0.0;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: \n");
    scanf("%lf", &a);
    printf("Please enter b: \n");
    scanf("%lf", &b);
    printf("Please enter c: \n");
    scanf("%lf", &c);

    if (discriminant(a, b, c) < 0)
    {
        printf("There are no real solutions\n");
    }

    else if (discriminant(a, b, c) == 0)
    {
        printf("There is one real solution: %.2lf\n", oneSolution(a, b, c, numerator, denominator));
    }

    else if(discriminant(a, b, c) > 0)
    {
        printf("There are 2 real solutions \n");
        printf("Solution 1: %.2lf\n", oneSolution(a, b, c, numerator, denominator));
        printf("Solution 2: %.2lf\n", twoSolution(a, b, c, numerator, denominator));
    }
}

/* This function calculates the value of the discriminant which tells us how many solutions there are. The three parameters, 
a, b, and c are the values that are input. The function uses these three values to return the discriminant value.*/
double discriminant(double a, double b, double c)
{
    double discriminant;
    discriminant = pow(b,2) - (4 * a * c);

    return discriminant;
}

/* This function calculates one solution in the case that the equation has one or two solutions. It is called in the main function
for the cases that the equation has a discriminant equal to zero or greater than zero. The parameters are a, b, and c, which are
the input values. We also have the parameters double numerator and double denominator which are calculated using a, b, and c. The return
value is the solution when the discriminant is added. */
double oneSolution(double a, double b, double c, double numerator, double denominator)
{
    double solution1;
        
        numerator = (-1 * b) + sqrt(discriminant(a, b, c));
        denominator = 2 * a;
        solution1 = numerator / denominator;

    return solution1;
}

/* This function calculates the second solution in the case that the equation has two solutions. It is called in the main function
for the case that the equation has a discriminant greater than zero. The parameters are a, b, and c, which are the input values. We
also have the parameters double numerator and double denominator which are calculated using a, b, and c. The return value is the
solution when the discriminant is subtracted. */
double twoSolution(double a, double b, double c, double numerator, double denominator)
{
    double solution2;

        numerator = (-1 * b) - sqrt(discriminant(a, b, c));
        denominator = 2 * a;
        solution2 = numerator / denominator;

    return solution2;
}