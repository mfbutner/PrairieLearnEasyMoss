/* this program asks the user to input values of a,b and c for the quadratic equation in the form ax^2 + bc + c. 
It calculates discriminant to determine how many roots the equation has, and solves the equation to calculate those roots(if any) */

#include <stdio.h>
#include <math.h>

double CalcDiscriminant(double a_value, double b_value, double c_value) {
    /* this function calculates the discriminant using values of a, b and c 
    @param a_value value of user inputted a 
    @param b_value value of user inputted b
    @param c_value value of user inputted c
    @return the discriminant 
    */
    double discriminant = pow(b_value,2) - (4 * a_value * c_value);
    return discriminant;
}


int main(void) {
    /* this function asks the user for input values of a, b and c, and subsequently outputs the value and number of roots */
    double a_value;
    double b_value;
    double c_value;
    double root_one;
    double root_two;
    double discriminant;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a_value);

    printf("Please enter b: ");
    scanf("%lf", &b_value);

    printf("Please enter c: ");
    scanf("%lf", &c_value);

    discriminant = CalcDiscriminant(a_value, b_value, c_value);
    
    if (discriminant > 0) {
        root_one = (- b_value + sqrt((pow(b_value,2) - (4 * a_value * c_value)))) / (2 * a_value);
        root_two = (- b_value - sqrt((pow(b_value,2) - (4 * a_value * c_value)))) / (2 * a_value);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root_one);
        printf("Solution 2: %.2lf", root_two);
    }
    else if (discriminant < 0) {
        printf("There are no real solutions");
    }
    else if (discriminant == 0) {
        root_one = (-b_value + sqrt((pow(b_value,2) - (4 * a_value * c_value)))) / (2 * a_value);
        printf("There is one real solution: %.2lf", root_one);
    }

    return 0;
    }