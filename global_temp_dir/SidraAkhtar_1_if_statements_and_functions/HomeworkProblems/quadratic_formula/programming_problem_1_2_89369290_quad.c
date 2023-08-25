#include <stdio.h> // Imports the stdio.h library
#include <math.h> // Imports the math.h library

// Void function that exists to show that the roots are floating point numbers
void calcRoots(double a, double b, double c) {
}

// This program uses the quadratic formula to determine how many real solutions there are and what they are based on 3 number inputs from the user.
int main() {
    double a, b, c; // The 3 variable inputs can be floating point numbers
    double rootOne, rootTwo, oneSol, discriminant; // The solutions and the discriminant can be floating point numbers

    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n"); // Print the form the quadratic equation takes

    printf("Please enter a: "); // Prompt user to enter first number input
    scanf("%lf", &a); // Reads the floating point number from user input 

    printf("Please enter b: "); // Prompt user to enter second number input
    scanf("%lf", &b); // Reads the floating point number from user input

    printf("Please enter c: "); // Prompt user to enter third number input
    scanf("%lf", &c); // Reads the floating point number from user input 

    discriminant = (b * b) - (4 * a * c); // Defines the discriminant as the number that is in the square root

    if (discriminant < 0) {
        printf("There are no real solutions\n"); // If the discriminant is negative, then it prints that there are no real solutions
    } 
    else if (discriminant > 0) {
        rootOne = (-b + sqrt(discriminant)) / (2 * a); // If the discriminant is positive, there are 2 real solutions and is solves the 'plus' solution first
        rootTwo = (-b - sqrt(discriminant)) / (2 * a); // and the 'minus' solution is solved second
        printf("There are 2 real solutions\n"); // States that there are 2 real solutions
        printf("Solution 1: %.2lf\n", rootOne); // Displays the positive solution first
        printf("Solution 2: %.2lf\n", rootTwo); // and the negative solution second
    }
    else {
        oneSol = -b / (2 * a); // If the discriminant equals 0, then there is one solution and it is solved by dividing -b by the denominator
        printf("There is one real solution: %.2lf\n", oneSol); // States that there is one real solution and displays the solution
    }

    return 0; // Ends program and returns the output
}
