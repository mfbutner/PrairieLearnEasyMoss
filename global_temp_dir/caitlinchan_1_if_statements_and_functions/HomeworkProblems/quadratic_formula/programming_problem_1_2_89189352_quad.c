#include <stdio.h>
#include <math.h>

/*
given a quadratic equation in the form ax^2 + bx + c,
user inputs values of a, b, and c to get the value of the roots which cause the equation to equal 0
*/

void calculate_roots(double a, double b, double c) {
    /*
    calculates roots of quadratic equation
    param a: value of a from quadratic equation in the form ax^2 + bx + c
    param b: value of b from quadratic equation in the form ax^2 + bx + c
    param c: value of c from quadratic equation in the form ax^2 + bx + c
    return: None
    */
    double discriminant;
    double root1;
    double root2;

    discriminant = (pow(b, 2.00)) - (4.00 * a * c);   // calculates discriminant (what's inside the sqrt - tells you how many roots)

    if (discriminant < 0) {
        printf("There are no real solutions");   // no real solutions bc can't sqrt neg number
    }
    else {
        root1 = (-b + sqrt(discriminant)) / (2.00 * a);
        root2 = (-b - sqrt(discriminant)) / (2.00 * a);

        if (discriminant > 0) {
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", root1, root2);
        }

        else if (discriminant == 0) {
        printf("There is one real solution: %.2lf", root1);
        }
    }
}

int main() {
    /*
    asks for user input for values of a, b, c from quadratic equation
    calls calculate function with a, b, c values
    return: 0
    */
    double a;
    double b;
    double c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    calculate_roots(a, b, c);
    return 0;
}