/*
this program find the roots of quadratic functions given the a, b, c values given the
quadratic equation a*x^2 + b * x + c
*/
#include <stdio.h>
#include <math.h>

double calcEquationInsideSquareRoot(double a, double b, double c);
double calcAdditionRoot(double a, double b, double c);
double calcSubtractionRoot(double a, double b, double c);
void printResults(double addRoot, double subRoot);

int main(void) {
    double a = 0.0, b = 0.0, c = 0.0, addRoot = 0.0, subRoot = 0.0;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);
    if (calcEquationInsideSquareRoot(a, b, c) < 0) {
        printf("There are no real solutions\n");
    }
    else {
        addRoot = calcAdditionRoot(a, b, c);
        subRoot = calcSubtractionRoot(a, b, c);
        printResults(addRoot, subRoot);
    }
    return 0;
}

double calcEquationInsideSquareRoot(double a, double b, double c) {
    /*
    calculates the equation inside the square root of the 
    quadratic formula (-b (+ or -) sqrt(b^2 - (4 * a * c))) / (2 * a)
    @a: the coefficient a in the quadratic equation ax^2 + bx + c
    @b: the coefficient b in the quadratic equation ax^2 + bx + c
    @c: the coefficient c in the quadratic equation ax^2 + bx + c
    @returns: the value of the expression inside the square root
    */
    return pow(b, 2) - (4 * a * c);
}

double calcAdditionRoot(double a, double b, double c) {
    /*
    calculates the root using the quadratic formula (-b (+ or -) sqrt(b^2 - (4 * a * c))) / (2 * a) 
    using the parameters a, b, c and using the + operator for the (+/-)
    @a: the coefficient a in the quadratic equation ax^2 + bx + c
    @b: the coefficient b in the quadratic equation ax^2 + bx + c
    @c: the coefficient c in the quadratic equation ax^2 + bx + c
    @returns: the root of the quadratic equation using the + operator in the quadratic formula
    */
    return (-b + sqrt(calcEquationInsideSquareRoot(a, b, c))) / (2 * a);
}

double calcSubtractionRoot(double a, double b, double c) {
    /*
    calculates the root using the quadratic formula (-b (+ or -) sqrt(b^2 - (4 * a * c))) / (2 * a) 
    using the parameters a, b, c and using the - operator for the (+/-)
    @a: the coefficient a in the quadratic equation ax^2 + bx + c
    @b: the coefficient b in the quadratic equation ax^2 + bx + c
    @c: the coefficient c in the quadratic equation ax^2 + bx + c
    @returns: the root of the quadratic equation using the - operator in the quadratic formula
    */
    return (-b - sqrt(calcEquationInsideSquareRoot(a, b, c))) / (2 * a);
}

void printResults(double addRoot, double subRoot) {
    /*
    prints the results on the screen for when there does exist a root for the equation
    @addRoot: the root of the equation obtained by using the + operator in the (+/-) portion of thequadratic formula
    @subRoot: the root of the equation obtained by using the - operator in the (+/-) portion of the quadratic formula
    @returns: void (returns nothing)
    */
    if (addRoot == subRoot) {
        printf("There is one real solution: %.2lf\n", addRoot);
        return;
    }
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", addRoot, subRoot);
    return;
}
