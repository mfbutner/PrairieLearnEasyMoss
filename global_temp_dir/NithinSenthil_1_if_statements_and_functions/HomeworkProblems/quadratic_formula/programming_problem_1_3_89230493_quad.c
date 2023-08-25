#include <stdio.h>
#include <math.h>

/*
Name: Nithin Senthil

Description:
This program takes a quadratic function from the user and returns
the number of solutions along with the solutions.
*/

//Prototypes
void solver(const double a, const double b, const double c, double* solutions);

/*
Function: main();

Description: Main body of program

Inputs:
None

Output:
Return 0 if program runs successfully
*/
int main() {
    //Initialize variables
    double a = 0;
    double b = 0;
    double c = 0;
    double solutions[3];

    //Get the quadratic from the user
    printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    //Calculate quadratic solutions
    solver(a, b, c, solutions);

    //Tell user the result
    switch ((int) solutions[0]) {
        case 0: //0 Solutions
            printf("There are no real solutions\n");
            break;
        case 1: //1 Solution
            printf("There is one real solution: %.2lf\n", solutions[1]);
            break;
        case 2: //2 Solutions
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", solutions[1]);
            printf("Solution 2: %.2lf\n", solutions[2]);
            break;
    }

    return 0;
} //End main();


/*
Function: solver();
Description: Calculate the solutions of the quadratic

Inputs:
a - a value of quadratic
b - b value of quadratic
c - c value of quadratic
solutions - pointer to array that holds the number of solutions followed by the solutions

Output:
No output because the required values are stored through the solutions pointer
*/
void solver(const double a, const double b, const double c, double* solutions) {
    //Initialize variables
    double discriminant = 0;
    
    //Calculate the discriminant
    discriminant = (b * b) - (4 * a * c);
    
    //Use discriminant to provide solutions
    if (discriminant >= 0) { //Discriminant is greater than or equal to 0 
        double solution1 = 0;
        double solution2 = 0;

        solution1 = ((-1 * b) + sqrt(discriminant)) / (2 * a);
        solution2 = ((-1 * b) - sqrt(discriminant)) / (2 * a);

        if (solution1 == solution2) {
            solutions[0] = 1;
            solutions[1] = solution1;
        } else {
            solutions[0] = 2;
            solutions[1] = solution1;
            solutions[2] = solution2;
        }

    } else { //Discriminant is less than 0
        solutions[0] = 0;
    }

} //End solver();