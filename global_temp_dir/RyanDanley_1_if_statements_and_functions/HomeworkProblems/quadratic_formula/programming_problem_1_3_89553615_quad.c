#include <stdio.h>
#include <math.h>

// The below function calculates the real roots of x given the variables of a quadratic equation
// The parameters are a (coefficient of x^2), b (coefficient of x), and c (the constant)
// The function returns the number of real roots of x
int quadRoots(double a, double b, double c, double *root1, double *root2) {
    double sponge = b*b - 4*a*c;
    // sponge = Square Part Of Numerator (ge)
    if (sponge < 0) {
        // If there are no real roots, the function returns 0
        return 0;
    } else if (sponge == 0) {
        // If there is one real root, the function returns 1
        *root1 = -b / (2 * a);
        return 1;
    } else {
        // If there are two real roots, the function returns 2
        *root1 = (-b + sqrt(sponge)) / (2 * a);
        *root2 = (-b - sqrt(sponge)) / (2 * a);
        return 2;
    }
}

// The below function prompts the user for variables a, b, and c, and then prints any real roots of x
int main() {
    double a, b, c;
    double root1, root2;
    int roots;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    roots = quadRoots(a, b, c, &root1, &root2);
    if (roots == 0) {
        printf("There are no real solutions\n");
    } else if (roots == 1) {
        printf("There is one real solution: %.2lf\n", root1);
    } else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root1);
        printf("Solution 2: %.2lf\n", root2);
    }

    return 0;
}