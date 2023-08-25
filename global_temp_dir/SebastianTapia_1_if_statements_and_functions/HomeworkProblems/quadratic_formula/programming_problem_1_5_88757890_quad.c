#include <stdio.h>
#include <math.h>

/*This program helps find the root values of x that make a quadratic
equation evaluate to 0 by asking user to input a, b, and c values to
plug in to the quadratic formula.*/

/*This function finds what the result will be from the calculations done inside the square
root part of the formula without square rooting yet. The paramaters are the a, b, and
c values that are inputted for the quadratic formula. The function returns the variable
insideResult, which is the calculation of squaring value b and subtracting the multiplication of 
4, b, and c from it.*/
double insideSquareRoot(double valueA, double valueB, double valueC) {
    double insideResult;         //holds calculations made that will then be square rooted
    insideResult = pow(valueB,2) - (4 * valueA * valueC);
    return insideResult;
}

int main() {
    double insideValue;
    double rootValue1;
    double rootValue2;
    double a;
    double b;
    double c;

    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    insideValue = insideSquareRoot(a,b,c);
    if (insideValue < 0) {
        printf("There are no real solutions\n");
    }
    else if (insideValue == 0) {
        rootValue1 = (b * -1) / (2 * a);
        printf("There is one real solution: %.2lf\n", rootValue1);
    } else {
        rootValue1 = ((b * -1) + sqrt(insideValue)) / (2 * a);
        rootValue2 = ((b * -1) - sqrt(insideValue)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", rootValue1);
        printf("Solution 2: %.2lf\n", rootValue2);
    }
    return 0;
}