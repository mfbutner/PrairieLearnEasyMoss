#include <stdio.h> 
#include <math.h>
// Anna Ghiuzeli ECS 36A 
// This program takes the user inputs for the a, b, and c values of the quadratic equation in the form a*x^2 + b*x + c then plugs those values into the quadratic formula
// to solve for the real root(s) and depending on the a,b, and c values, it will output to the screen how many real solutions (one or two real solutions) or if any there are as well as the real roots of x if there are any. 


//This function takes the user given values of a,b, and c which have been passed to it by the main function and are also its parameters which are specificed as double types 
//then it plugs in these values into the quadratic formula to calculate the first and second roots. 
//Afterwards, it checks if the two roots are both real solutions to the equation , if only one of the roots is a real solution, or if none of the roots are real solutions using a if statement and two else if statements. 
// This function doesn't return anything because it is a void type function. 
void quadratic_formula(double a, double b, double c) {
double negative_b, first_root, second_root, equation_part;
int power; 
negative_b = b * -1; 
    power = 2;
    equation_part = (pow(b,power) - (4 * a) * c);
    first_root = negative_b + sqrt(equation_part); 
    first_root = first_root / (2 * a); 
    second_root = negative_b - sqrt(equation_part); 
    second_root = second_root / (2 * a); 
    if((pow(b, power) - (4 * a) * c) > 0) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", first_root);
        printf("Solution 2: %.2lf\n", second_root);
    } else if ((pow(b, power) - (4 * a) * c) == 0) {
        printf("There is one real solution: %.2lf\n", second_root);
    } else if ((pow(b, power) - (4 * a) * c) < 0) {
         printf("There are no real solutions\n");
    } else {
        ;
    }

}


//This is the main function and it prints the prompt for the user to enter the a,b, and c values then it stores those values into the a, b, and c variables. This function doesn't have any parameters.
// Then it calls the quadratic formula function with the arguments a,b, and c which are the variables that contain the user given values and finally this function returns the integer 0. 
int main() { 
    double a, b, c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); 
    printf("Please enter a: "); 
    scanf(" %lf", &a); 
    printf("Please enter b: "); 
    scanf(" %lf", &b); 
    printf("Please enter c: "); 
    scanf(" %lf", &c); 
    quadratic_formula(a,b,c);
    return 0; 
}