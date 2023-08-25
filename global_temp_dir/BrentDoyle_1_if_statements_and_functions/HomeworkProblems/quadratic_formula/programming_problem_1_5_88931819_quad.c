#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
This program asks the user for a, b, and c 
from a quadratic equation in form ax^2 + bx + c
and then displays the real roots of x if there are any.
*/

/*
This function checks if the given inputs a, b, and c have a real solution(s) from a quadratic formula
by making sure what is inside the square root function is not negative.
Each parameter check_a, check_b, and check_c represents the a, b, and c in the quadratic formula ax^2 + bx + c.
This function returns true if the given a, b, and c have a real solution(s), and false otherwise.
*/
bool have_real_solution (const double check_a, const double check_b, const double check_c);

/*
This function plugs the inputs a, b, and c into the plus version of the quadratic formula to get a solution, 
which first solves the top part of the equation, then the bottom part of the equation, 
then divides the top part by the bottom part, to get the final solution.
Each parameter plus_a, plus_b, and plus_c represents the a, b, and c in the quadratic formula ax^2 + bx + c.
This function returns the solution to the plus version of the quadratic formula.
*/
double quadratic_equation_plus (const double plus_a, const double plus_b, const double plus_c);

/*
This function plugs the inputs a, b, and c into the minus version of the quadratic formula to get a solution, 
which first solves the top part of the equation, then the bottom part of the equation, 
then divides the top part by the bottom part, to get the final solution.
Each parameter minus_a, minus_b, and minus_c represents the a, b, and c in the quadratic formula.
This function returns the solution to the minus version of the quadratic formula.
*/
double quadratic_equation_minus (const double minus_a, const double minus_b, const double minus_c);

int main() {

    double a;
    double b;
    double c;
    double solution_plus;
    double solution_minus;
    int real_solution_count = 0;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);

    printf("Please enter b: ");
    scanf(" %lf", &b);

    printf("Please enter c: ");
    scanf(" %lf", &c);

    if (have_real_solution(a, b, c) == true) {
        if (quadratic_equation_plus(a, b, c) == quadratic_equation_minus(a, b, c)) {
            solution_plus = quadratic_equation_plus(a, b, c);
            real_solution_count = 1;
        }
        else {
            solution_plus = quadratic_equation_plus(a, b, c);
            solution_minus = quadratic_equation_minus(a, b, c);
            real_solution_count = 2;
        }
    }
    else {
        real_solution_count = 0;
    }

    switch(real_solution_count) {
        case 0: {
            printf("There are no real solutions\n");
            break;
        }
        case 1: {
            printf("There is one real solution: %.2lf\n", solution_plus);
            break;
        }
        case 2: {
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", solution_plus);
            printf("Solution 2: %.2lf\n", solution_minus);
            break;
        }
    }

    return 0;
}

bool have_real_solution (const double check_a, const double check_b, const double check_c) {
    if ((pow(check_b, 2) - 4 * check_a * check_c) < 0) {
        return false;
    }
    else {
        return true;
     }
}

double quadratic_equation_plus (const double plus_a, const double plus_b, const double plus_c) {
    double temp_val_top = -plus_b + (sqrt (pow(plus_b, 2) - 4 * plus_a * plus_c));
    double temp_val_bottom = 2 * plus_a;
    double solution = temp_val_top / temp_val_bottom;
    return solution;
}

double quadratic_equation_minus (const double minus_a, const double minus_b, const double minus_c) {
    double temp_val_top = -minus_b - (sqrt (pow(minus_b, 2) - 4 * minus_a * minus_c));
    double temp_val_bottom = 2 * minus_a;
    double solution = temp_val_top /  temp_val_bottom;
    return solution;
}