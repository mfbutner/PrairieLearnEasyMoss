#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//Intakes values for the variables in the quadratic equation and outputs the number of real solutions

//solution check evalutes the value of the final number under the squareroot symbol to see whether the result will be undefined or has one or two solutions
double solutionCheck (double variableA, double  variableB, double variableC);
//main presents the format and intakes the values for the equation, plugs the values in two the + and - equations and prints the result
//main returns 0
int main () {
double variableA, variableB, variableC, solutionPlus, solutionMinus;


printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

printf("Please enter a: ");
//holds the value for variable A
scanf("%lf",&variableA);

printf("Please enter b: ");
//holds the value for variable B
scanf("%lf",&variableB);

printf("Please enter c: ");
//holds the value for variable C
scanf("%lf",&variableC);
//holds the value for the equation with the Plus sign
solutionPlus = (-variableB + sqrt(pow(variableB,2)-4*(variableA*variableC)))/(2*variableA);

solutionMinus = (-variableB - sqrt(pow(variableB,2)-4*(variableA*variableC)))/(2*variableA);
//numSolutions acts as a holder for the result of our solutionCheck function
int numSolutions = solutionCheck (variableA, variableB, variableC);
if (numSolutions == 2) {
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf",solutionPlus,solutionMinus);
}
else if (numSolutions == 1) {
    printf("There is one real solution: %.2lf",solutionPlus);
}
else if (numSolutions) {
    printf("There is one real solution: %.2lf",solutionMinus);
}
else {
    printf("There are no real solutions");
}
    return 0;
}
// solutionCheck returns 1 for one solution, 0 for no solutions, and 2 for two real solutions
double solutionCheck (double variableA, double  variableB, double variableC) {
//notDefined acts as a counter to determine how many real solutions there are 
    double notDefined = (variableB * variableB) - (4 * variableA * variableC);
    if (notDefined == 0) {
        return 1;
    }
    else if (notDefined < 0) {
        return 0;
    }
    else {
        return 2;
    }
}

