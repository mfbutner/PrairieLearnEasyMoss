/* Andrea Zhang Mingcheng Li
ECS 36A Butner */

/* Program will return the real roots of x based on the values of a, b, and c inputted by the user */
#include <stdio.h> // Allows us to use printf function 
#include <math.h> // Needed for math functions 

/* Main starts the program */
// {} will denote the start and end of main

int main() { 

    /* Double allows value to be a decimal point */
    double a; 
    double b; 
    double c; 

    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n"); // Quadratic equation formula 
    
    
    printf("Please enter a: "); // Asks user for value for variable a
    scanf("%lf", &a); // Assigns floating point number to a 

    printf("Please enter b: "); // Asks user for value for variable b
    scanf("%lf", &b); // Assigns floating point number to b 

    printf("Please enter c: "); // Asks user for value for variable c 
    scanf("%lf", &c); // Assigns floating point number to c 

    /* Double allows value to be a decimal point */
    double firstSolution; 
    double secondSolution; 
    double oneSolution;

    
    /* If formula returns a value greater than 0, function will return two possible real solutions */
    if (((b * b) - (4 * a * c)) > 0) { 
        printf ("There are 2 real solutions \n");
        firstSolution = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a); // Use the addition part of the quadratic formula to figure out the first solution
        secondSolution = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a); // Use the subtraction part of the quadratic formula to figure out the second solution

        /* Use %.2lf in order to set the values to two decimal points */
        printf("Solution 1: %.2lf\n", firstSolution);
        printf("Solution 2: %.2lf\n", secondSolution);   
    }

    /* If formula returns 0, function will return one real solution */
    else if (((b * b) - (4 * a * c)) == 0) { // Function will run if first if statement fails 
        oneSolution = (-b) / (2 * a); //  If values inputted in the quadratic formula, only one real solution will return
        printf("There is one real solution: %.2lf", oneSolution); // Use %.2lf in order to set the values to two decimal points

    }

    /* If the formula returns a negative number, function will return no real solution 
    Square root of a negative number will return an imaginary number */
    else if (((b * b) - (4 * a * c)) < 0)  { // Function will run if first and second if statement fails 
        printf("There are no real solutions\n");
    }

    return 0;

}
