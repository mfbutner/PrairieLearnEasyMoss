#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Program calculates the real solutions of a quadratic equation given values a, b, and c
// Prints number of roots (0, 1, or 2)

/* 
Check if discriminant is positive (determine there's at least one solution)  
@params: a, b, and c are the three values that will be plugged into quadratic equation
@returns: true if evaluated to a positive number 
*/
double DiscriminantIsPositive(double a, double b, double c) {
    return (b * b - (4 * a * c)) >= 0;
}

/*
double QuadraticPlusSolution(double a, double b, double c) {
    return ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
}
double QuadraticMinusSolution(double a, double b, double c) {
    return ((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
}*/

int main() {
    double a, b, c;
    // Ask user for values a, b, and c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    // Check if the discriminant is negative
    // Negative discriminant means no real solutions
    if (!(DiscriminantIsPositive(a, b, c))) {
        printf("There are no real solutions");
        return 0;
    }
    // Positive discriminant means at least one real solution
    else if (DiscriminantIsPositive(a, b, c)) {
        // Calculate roots using quadratic equation
        double quadraticPlusSolution = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double quadraticMinusSolution = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

        // Determine number of solutions
        if (quadraticPlusSolution == quadraticMinusSolution) {
            printf("There is one real solution: %.2lf\n", quadraticPlusSolution);
        } 
        else if (quadraticPlusSolution != quadraticMinusSolution) {
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", quadraticPlusSolution);
            printf("Solution 2: %.2lf\n", quadraticMinusSolution);
        }
    }
    return 0;
}

