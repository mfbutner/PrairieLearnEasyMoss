#include <stdio.h>
#include <math.h>

// This program calculates solutions to a quadratic equation using the quadratic formula

// Calculate the real roots of the quadratic equation
int quadratic_roots(double a, double b, double c, double *root_1, double *root_2) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    } else if (discriminant == 0) {
        *root_1 = -b / (2 * a);
        return 1;
    } else {
        *root_1 = (-b + sqrt(discriminant)) / (2 * a);
        *root_2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2;
    }
}

// Ask the user for the values of a, b, and c
int main(void) {
    double a, b, c;
    double root_1, root_2;
    int roots;

    // Ask the user for the values of a, b, and c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); // Tell the user to provide numbers in the format ax^2 + bx + c
    
    printf("Please enter a: "); // Let the user enter their first number, a, and record it
    scanf("%lf", &a);

    printf("Please enter b: "); // Let the user enter their second number, b, and record it
    scanf("%lf", &b);

    printf("Please enter c: "); // Let the user enter their third number, c, and record it
    scanf("%lf", &c);


    roots = quadratic_roots(a, b, c, &root_1, &root_2);

    // the real roots of the equation
    if (roots == 0) {
        printf("There are no real solutions"); //
    } else if (roots == 1) {
       printf("There is one real solution: %.2lf\n", root_1); // If it equals 0, then the problem has 1 real solution: -b divided by 2 times a. Display this to the user
    } else {
        printf("There are 2 real solutions\n"); // Display that the problem has 2 real solutions 
        printf("Solution 1: %.2lf\n", root_1); // Display  solution 1 calculated
        printf("Solution 2: %.2lf\n", root_2);// Display  solution 2 calculated
    }

    return 0;
}
