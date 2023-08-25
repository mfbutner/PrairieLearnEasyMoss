/*
Calculates the real roots of a quadratic equation in the form ax^2 _ bx _ c.

Program is given three values a, b, and c corresponding with values in the equation.
It then determines whether equation has one, two, or no roots and prints solutions.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool IsSquareRootNeg(double A, double B, double C){
    /*
    Checks if number if number in the square root of the quadratic formula is negative.
    If negative, equation has no real solutions.
    double A: first coefficient of the quadratic formula
    double B: second coefficient of the quadratic formula
    double C: third coefficient of the quadratic formula
    return bool: Returns True if number in square root of quadratic equation is negative and False if number is positive.
    */
    double squareRootCheck;
    
    squareRootCheck = pow(B, 2) - 4 * A * C;

    if (squareRootCheck < 0){
        return true;
    }else{
        return false;
    }
}


double SolveQuadraticFormula1(double inputA, double inputB, double inputC){
    //Calculate the first solution of the quadratic formula.
    //double inputA = first coefficient of the quadratic formula
    //double inputB = second coefficient of the quadratic formula
    //double inputC = third coefficient of the quadratic formula
    //return double: the solution of the quadratic formula with + before the square root
    double solution1;
    
    solution1 = ((inputB * -1) + sqrt(pow(inputB,2) - 4*inputA*inputC)) / (2*inputA);  

    return solution1;
}


double SolveQuadraticFormula2(double inputA, double inputB, double inputC){
    //Calculate the second solution of the quadratic formula.
    //double inputA = first number of the quadratic formula
    //double inputB = second number of the quadratic formula
    //double inputC = third number of the quadratic formula
    //return double: the solution of the quadratic formula with - before the square root
    double solution2;
    
    solution2 = ((inputB * -1) - sqrt(pow(inputB,2) - 4*inputA*inputC)) / (2*inputA);  

    return solution2;
}


void PrintRealSolutions(double solution1, double solution2){
    //Test if the two answers of the quadratic formula are equal
    //solution1 = the solution of the quadratic formula with + before the square root
    //solution2 = the solution of the quadratic formula with - before the square root
    //print both solutions if they are not equal, give back only one if they are equal
    //return: none
    if (solution1 == solution2){
        printf("There is one real solution: %.2lf\n", solution1);
    }else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }
}

int main() {
    // Main function. Collects user input and passes a, b, c variables onto functions to solve the quadratic equations and print every solution (if there exist any).
    // return int: returns 0 if program successfully runs
    //double inputA = first coefficient of the quadratic formula
    //double inputB = second coefficient of the quadratic formula
    //double inputC = third coefficient of the quadratic formula
    double inputA, inputB, inputC;
    //solution1 = the solution of the quadratic formula with + before the square root
    //solution2 = the solution of the quadratic formula with - before the square root
    double solution1, solution2;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf("%lf", &inputA);

    printf("Please enter b: ");
    scanf("%lf", &inputB);
    
    printf("Please enter c: ");
    scanf("%lf", &inputC);

    if (IsSquareRootNeg(inputA, inputB, inputC)){
        printf("There are no real solutions\n");
    }else{
        solution1 = SolveQuadraticFormula1(inputA, inputB, inputC);
        solution2 = SolveQuadraticFormula2(inputA, inputB, inputC);
        PrintRealSolutions(solution1, solution2);
    }
    
    return 0;

}