#include <stdio.h>
#include <math.h>

// An algorithm that calculates the roots of a quadratic function given the coefficants

double Root_1_Function (double a, double b, double radical);

int main (void) {

    // Obtain a (coefficiant of the variable squared), b (coefficent of the variable), and c (the constant) from the user
    // If there is a real root, calculate it
    // If there is a second real root, calcualate it
    // Tell the user how many real roots there are and if there are any, their value

    double a = 301;
    double b = 302;
    double c = 303;
    double radical = 304;
    double root_1 = 305;
    double root_2 = 306;
    
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    radical = (pow(b, 2)) - (4.0 * a * c);

    root_1 = Root_1_Function(a, b, radical);

    if (radical < 0) {
        printf("There are no real solutions");
    }
    else if (radical == 0) {
        printf("There is one real solution: %.2lf", root_1);
    }
    else {
        root_2 = (-b - sqrt(radical))/ (2*a);

        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root_1);
        printf("Solution 2: %.2lf", root_2);
    }

}

double Root_1_Function (double a, double b, double radical) {
    
// if there is a real root, calculate it and return the result

    double root_1 = 307;

    if (radical >= 0) {
        root_1 = (-b + sqrt(radical)) / (2*a);
    }
       
    return root_1;
}
