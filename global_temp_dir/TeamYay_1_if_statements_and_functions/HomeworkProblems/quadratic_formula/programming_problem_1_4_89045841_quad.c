// This program takes in variables to solve the quadratic equation
// Defined the variables, then had the user input the numbers they wanted to input into the equation
// Broke down the quadratic equation and assigned each possible answer a variable
// Checked to see if the outputs from the equations would give out a number
// Printed the results to the screen

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void output(double add_quad_equation, double sub_quad_equation, bool is_valid_add_quad, bool is_valid_sub_quad);

// This function asks for the inputs for the variables, and then creates the equation for the output. It then checks to make sure the equations are returning numbers and then calls the function output.
// This function has no parameters
// This function returns 0 on success

int main(){
    double a_variable;
    double b_variable;
    double c_variable;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf", &a_variable);

    printf("Please enter b: ");
    scanf("%lf", &b_variable);

    printf("Please enter c: ");
    scanf("%lf", &c_variable);

    double power = pow(b_variable, 2);
    double square_root = sqrt(power - (4 * a_variable * c_variable));
    double add_quad_equation = (-b_variable + square_root)/(2 * a_variable);
    double sub_quad_equation = (-b_variable - square_root)/(2 * a_variable);

    bool is_valid_add_quad = !isnan(add_quad_equation);
    bool is_valid_sub_quad = !isnan(sub_quad_equation);

    output(add_quad_equation, sub_quad_equation, is_valid_add_quad, is_valid_sub_quad);

    return 0;
}

// This function prints out the different possible outputs for the equation.
// add_quad_equation is the quadratic equation that adds the square root in the quadratic equation
// sub_quad_equation is the quadratic equation that subtracts the square root in the quadratic equation
// is_valid_add_quad is the boolean check to make sure that the add_quad_equation is a real number
// is_valid_sub_quad is the boolean check to make sure that the sub_quad_equation is a real number
// This function returns nothing

void output(double add_quad_equation, double sub_quad_equation, bool is_valid_add_quad, bool is_valid_sub_quad) {
    if ((is_valid_add_quad && is_valid_sub_quad) && (add_quad_equation != sub_quad_equation)){
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", add_quad_equation);
        printf("Solution 2: %.2lf\n", sub_quad_equation);

        exit(0);
    }
    else if (is_valid_add_quad || is_valid_sub_quad) {
        if (is_valid_add_quad) {
            printf("There is one real solution: %.2lf\n", add_quad_equation);
        } else {
            printf("There is one real solution: %.2lf\n", sub_quad_equation);
        }
        exit(0);
    }
    else {
        printf("There are no real solutions\n");
    }
}
