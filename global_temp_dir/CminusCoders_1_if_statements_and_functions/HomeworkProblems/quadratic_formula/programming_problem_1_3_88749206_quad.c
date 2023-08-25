#include <stdio.h>
#include <math.h>

//Maxim Saschin
/*
Program overview: This program allows the user to input three numbers which are stored as variables "a", "b", and "c" that will be 
used to find x in the guadratic equation. The program will then use these three numbers inputed by the user to calculate the roots (x) 
by using the quadratic formula. It will then output and print 0, 1, or 2 real solutions. 
*/

/*
This function named "QuadFormulaCalc" uses the user inputed numbers to calculate all possible solutions to the quadratic formula. 
It first starts by getting the calculation inside the square root of the quadratic formula. 
If the inside of the square root is a number greater than 0, it computes the rest of the quadratic forumla. It then prints two real 
solutions. 
If the inside of the square root is equal to 0, we can compute the rest of the quadratic forumla with the square root portion removed 
from the equation. This will result in a single solution and we can then print that solution.
If the inside of the square root is not greater than or equal to 0, thuis means the solution is not real. The function then prints: 
"There are no real solutions". 
*/
double QuadFormulaCalc(double num1, double num2, double num3) {
    double insideSquareRoot;
    double solution1;
    double solution2;

    insideSquareRoot = (num2 * num2) - (4 * (num1 * num3));

    if (insideSquareRoot > 0) {
        solution1 = (-num2 + sqrt(insideSquareRoot)) / (2 * num1);
        solution2 = (-num2 - sqrt(insideSquareRoot)) / (2 * num1);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }
    else if (insideSquareRoot == 0) {
        solution1 = -num2 / (2 * num1);
        printf("There is one real solution: %.2lf\n", solution1);
    }
    else {
        printf("There are no real solutions\n");
    }
    return 0;
}

/* 
The "main" function in this program is used to get the three user inputs and then translate those inputs to the "QuadFromulaCalc" 
function. 
The function creates three variables for the user inputs. It then asks the user to input three numbers, "a", "b", and then "c". 
It then calls to the function "QuadFormulaCalc" using the three user inputs. 
*/

int main(void) {
    double userNum1;
    double userNum2;
    double userNum3;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &userNum1);
    printf("Please enter b: ");
    scanf("%lf", &userNum2);
    printf("Please enter c: ");
    scanf("%lf", &userNum3);

    QuadFormulaCalc(userNum1, userNum2, userNum3);

    return 0;
}