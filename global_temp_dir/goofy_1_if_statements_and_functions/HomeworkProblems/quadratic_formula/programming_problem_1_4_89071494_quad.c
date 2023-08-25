/*
Program asks user for variables a, b, c, and returns the real roots of x 
through the quadratic equation, if there are any.
*/
#include <stdio.h>
#include <math.h>

double calc_root1(double a, double b, double c) {
    /*
    Calculates the first root solution by the "plus" quadratic equation.
    @a: user's real value for a
    @b: user's real value for b
    @c: user's real value for c
    @return: first root solution
    */
    double x_root1;
    x_root1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    return x_root1;
}

double calc_root2(double a, double b, double c) {
    /*
    Calculates the second root solution by the "minus" quadratic equation.
    @a: user's real value for a
    @b: user's real value for b
    @c: user's real value for c
    @return: second root solution
    */
    double x_root2;
    x_root2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    return x_root2;
}

void announce_results(double a, double b, double c) {
    /*
    Announces and prints out the result(s). There may be no real, one real, or two real solutions. 
    Existing roots are printed to 2 decimal points.
    @a: user's real value for a
    @b: user's real value for b
    @c: user's real value for c
    */
    double x_root1, x_root2;

    x_root1 = calc_root1(a, b, c);
    x_root2 = calc_root2(a, b, c);

    if (x_root1 == x_root2) {
        printf("There is one real solution: %.2lf\n", x_root1);
    }
    else if (pow(b,2) < (4*a*c)) {
        printf("There are no real solutions\n");
    }
    else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", x_root1);
        printf("Solution 2: %.2lf\n", x_root2);
    }
}

int main(void) {
    /*
    Set up function. Initializes variables needed for the quadratic equation. Informs and asks the 
    user for each variable, a, b, and c. Then calls to the function that announces results after
    being called to other functions to calculate roots.
    */
    double a, b, c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    announce_results(a, b, c);
}