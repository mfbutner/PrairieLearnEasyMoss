/*
Code by Saee Patil and Ayush Maral 
This function works as the quadratic formulas; after taking in the user
inputs for a, b, and c, the code tells you the solutions
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
This function returns the value inside the sqaure root in the quadratic function
@double a - a value in quadratic function 
@double b - b value in quadratic function 
@double c - c value in quadratic function 
@return double squareValue - returns the value inside the sqaure root in the quadratic function
*/
double sqrtQuadratic(double a, double b, double c) 
{
    //variables
    double squareValue;

    // all calcuations and return
    squareValue = sqrt(pow(b, 2)-(4 * a * c));
    return squareValue;
}


/*
The main function finishes up solving the possible solutions of the 
quadratic formula and then evaluates the total number of solutions
*/
int main ()
{
    //variables
    double solutionOne;
    double solutionTwo;
    double a;
    double b;
    double c;

    //get all the user inputs 
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    // all calcuations 
    solutionOne = (-b + sqrtQuadratic(a, b, c))/(2 * a);
    solutionTwo = (-b - sqrtQuadratic(a, b, c))/(2 * a);

    // evalutions output statements 
    if ((4 * a * c) > pow(b, 2)) {  //if there is no solution
        printf("There are no real solutions");
    }
    else if (solutionOne == solutionTwo) {  //if there is one solution
        printf("There is one real solution: %.2lf", solutionOne);
    }
    else{   //if there is more than one solution (and which solution to list first)
        printf("There are 2 real solutions\n");
        if (solutionOne < 0 && solutionTwo < 0) {
            if (solutionOne > solutionTwo ) {
            printf("Solution 1: %.2lf\nSolution 2: %.2lf", solutionOne, solutionTwo);
        }
        else {
            printf("Solution 1: %.2lf\nSolution 2: %.2lf", solutionTwo, solutionOne);
        }
        }

        else {
            if (solutionOne < solutionTwo) {
                printf("Solution 1: %.2lf\nSolution 2: %.2lf", solutionOne, solutionTwo);
            }
            else {
            printf("Solution 1: %.2lf\nSolution 2: %.2lf", solutionTwo, solutionOne);
            }
        }
        
    }

    return 0;
}