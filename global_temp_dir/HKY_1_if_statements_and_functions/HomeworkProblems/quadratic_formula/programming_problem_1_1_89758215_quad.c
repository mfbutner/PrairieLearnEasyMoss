/*
a program that takes in the input of 3 numbers (a, b, c) and 
puts them in the format ax^2 + bx + c
the program will return how many solutions exist, and what those solutions are

"%.2lf
*/

// imports all necessary functions
#include <stdio.h> // imports input and output functions
#include <stdbool.h> // imports boolean functions 
#include <math.h> // imports math functions

// function that checks whether there's zero solutions
// 'numA', 'numB', and 'numC' all correspond to the variables a, b, and c
// returns true when there's zero solutions; returns false otherwise
bool zeroSolutions(double numA, double numB, double numC) {
    // the value inside the square root of the equation
    double insideOfSquare = (numB * numB) - (4 * numA * numC);
    
    // if the inside of the square is a negative number
    if (insideOfSquare < 0) {
        return true; // there's no solution
    } else {
        return false; // there's at least one solution
    }
}

// function that checks whether there's only one solution
// 'numA', 'numB', and 'numC' all correspond to the variables a, b, and c
// returns true when there only one solution; returns false otherwise
bool oneSolution(double numA, double numB, double numC) {
    // the value of the square root in the equation
    double squareRootNum = sqrt((numB * numB) - (4 * numA * numC));

    // the numerator of the equation if the sign is negative
    double numeratorNeg = (-1 * numB) - squareRootNum;

    // the numerator of the equation if the sign is positive
    double numeratorPos = (-1 * numB) + squareRootNum;

    // if the values are the same regardless of sign
    if (numeratorNeg == numeratorPos) {
        return true; // there's only one solution
    } else {
        return false; // there's more than one solution 
    }
}

// 'main' program needed for function to run. no parameters.  
// will return 0 if program is successful
int main() {
    double numA, numB, numC; // initializes double / decimal variables for calculation
    int numSolutions; // initializes integer variable to keep track of how many solutions exist

    // ---- ASK FOR USER INPUT ----
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: \n");
    scanf("%lf", &numA);

    printf("Please enter b: \n");
    scanf("%lf", &numB);

    printf("Please enter c: \n");
    scanf("%lf", &numC);

    // ---- CHECK NUMBER OF RESULTS ----
    if (zeroSolutions(numA, numB, numC)) {
        numSolutions = 0;
    } else if (oneSolution(numA, numB, numC)) {
        numSolutions = 1;
    } else {
        numSolutions = 2;
    }

    // ---- CALCULATE + PRINT RESULTS ----
    if (numSolutions > 0) {
        if(numSolutions == 1) {
            // initialize variable called 'the solution', since there's only one
            double theSolution;

            theSolution = ((-1 * numB) - sqrt((numB * numB) - (4 * numA * numC))) / (2 * numA);
            printf("There is one real solution: %.2lf\n", theSolution);
        }
        
        if (numSolutions == 2) {
            // initializes two variables, both solutions
            double solution1, solution2;

            solution1 = ((-1 * numB) + sqrt((numB * numB) - (4 * numA * numC))) / (2 * numA);
            solution2 = ((-1 * numB) - sqrt((numB * numB) - (4 * numA * numC))) / (2 * numA);

            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", solution1);
            printf("Solution 2: %.2lf\n", solution2);
        }
    } else { // if there's no solution
        printf("There are no real solutions\n");
    }

    return 0; // will return 0 if successful
}