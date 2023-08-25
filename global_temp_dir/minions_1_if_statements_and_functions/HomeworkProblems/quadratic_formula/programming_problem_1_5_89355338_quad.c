#include <stdio.h>
#include <math.h>

/*
 This program will take the input from the user that corresponds to
 the coeffficients of the terms in a standard quadratic equation, 
 calculating how many and what the solutions are (if they exist)
*/

/*
Calculates the discriminant's value to predetermine if there are one, two, or no solutions
@param a : the coefficient of the x^2 term
@param b: the coefficient of the x term
@param c: the constant value
@return: a double that is an element of the real numbers
*/
double discriminantValue(double a, double b, double c) {
    return (pow(b, 2) - (4 * (a) * (c)));
}

/*
Calculates the first variation of the quadratic formula taking the sum of the numerator 
@param a : the coefficient of the x^2 term
@param b: the coefficient of the x term
@param c: the constant value
@return: one solution of the quadratic function (resulting from adding the sqrt)
*/
double quadFormula1(double a, double b, double c) {
    double solution1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    return solution1;
}

/*
Calculates the second variation of the quadratic formula taking the difference of the numerator
@param a : the coefficient of the x^2 term
@param b: the coefficient of the x term
@param c: the constant value
@return: one solution of the quadratic function (resulting from subtractinging the sqrt)
*/
double quadFormula2(double a, double b, double c) {
    double solution2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    return solution2;
}

/*
This function asks the user for their input of the quadratic, where depending 
on the discriminant it calculates the solution(s) of the equation (if they exist)
@return: solution(s) of the equation (if they exist)
*/
int main() {

    double a;
    double b;
    double c; 

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf(" %lf", &a);

    printf("Please enter b: ");
    scanf(" %lf", &b);

    printf("Please enter c: ");
    scanf(" %lf", &c);

    if (discriminantValue(a, b, c) > 0) {
        printf("There are 2 real solutions\n");
        double solution1 = quadFormula1(a,b,c);
        double solution2 = quadFormula2(a,b,c); 
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }

    else if (discriminantValue(a, b, c) == 0) {
        double solution1 = quadFormula1(a, b, c);
        printf("There is one real solution: %.2lf\n", solution1);
    }

    else if (discriminantValue(a, b, c) < 0) {
        printf("There are no real solutions\n");
    }
    return 0;
}