#include <stdio.h>
#include <math.h>
/* This program asks the user for a, b, and c of a quadratic equation,
calculates the roots given the quadratic equation and tells the user how
many solutions there are and what those solutions are */

/* This function calculates the roots given a quadratic equation and
tells the user how many solutions there are and what those solutions are */
void calculate_quad_roots(double a, double b, double c)
{
    double s1;
    double s2;
    // See how many solutions exist by calculating the discriminate (the part of the quadratic formula that is under the square root)
    // Check if the discriminant is negative, equal to 0, or positive.
    double discriminant = pow(b, 2) - 4 * a * c;
    // If it is negative, there is no solution.
    if (discriminant < 0)
    {
        printf("There are no real solutions");
    }
    else if (discriminant == 0) // If it is equal to 0, there is only one solution.
    {                           // Get the root of the quadratic equation for the one solution
        s1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        // print there's one solution and what it is
        printf("There is one real solution: %.2lf", s1);
    }
    else // If it is positive, then there are two solutions.
    {    // Get the roots of the quadratic equation for those two solutions
        s1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        s2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        // print the two solutions
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", s1, s2);
    }
}
// the main function prompts the user for values of a, b, and c
int main()
{
    double a;
    double b;
    double c;
    // Ask the user for values of a, b, and c
    // Store each of these numbers so we can refer to them later
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    calculate_quad_roots(a, b, c);

    return 0;
}
