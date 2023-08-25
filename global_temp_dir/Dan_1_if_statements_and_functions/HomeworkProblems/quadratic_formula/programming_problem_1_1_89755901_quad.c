/*
* quad.c
* by Dan Firstenberg
* 2/6/2023
*/

// This program gets the roots of a function using the quadratic formula

#include <stdio.h>
#include <math.h>

void solve_quadratic();
double get_radicand(double a, double b, double c);

int main(void) {
solve_quadratic();
return 0;
}


// this function solves for the number / values of the roots
// it does not return any value
void solve_quadratic() {
    double a;
    double b;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    double radicand = get_radicand(a, b, c);
    if (radicand > 0) {
        double radical = sqrt(radicand);
        double solution_one_unformatted = (-b + radical) / (2 * a);
        double solution_two_unformatted = (-b - radical) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", solution_one_unformatted);
        printf("Solution 2: %.2f\n", solution_two_unformatted);
    } else if (radicand == 0) {
        double solution = (-b / (2 * a));
        printf("There is one real solution: %.2f\n", solution);
    } else {
        printf("There are no real solutions\n");
    }
}

// this solves for the radicand of the equation and the parameters are the a, b, and
// c values of the function and returns the radicand
double get_radicand(double a, double b, double c) {
return (b * b) - (4 * a * c);
}