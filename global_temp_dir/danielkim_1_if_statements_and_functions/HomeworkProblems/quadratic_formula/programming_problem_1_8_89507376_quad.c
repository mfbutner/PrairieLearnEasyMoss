#include <stdio.h>
#include <math.h>
//This program accepts an equation in the form ax^2 + bx + c and calculates the solutions.

/*Determines the number of solutions and calculates and prints the solutions. Parameters are user inputs a, b, and c from an equation
in the form ax^2 + bx + c. Returns 0 but prints all the statements.*/
double Calc_Solutions(double a, double b, double c){
    double sol_1, sol_2;

    if(((pow(b,2))-(4 * a * c)) >= 0){
        sol_1 = (-b + sqrt(pow(b,2)-(4 * a * c)))/(2 * a);
        sol_2 = (-b - sqrt(pow(b,2)-(4 * a * c)))/(2 * a);
        if(sol_1 == sol_2){
            printf("There is one real solution: %.2f", sol_1);
        }else{
            printf("There are 2 real solutions\nSolution 1: %.2f\nSolution 2: %.2f", sol_1, sol_2);
        }
    }else{
        printf("There are no real solutions");
    }

    return 0;
}

/*Asks the user for the variables a, b, and c. Calls the function Calc_Solutions and gives it the parameters given by the user.
returns 0. No parameters taken.*/
int main(){
    double a, b, c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    Calc_Solutions(a, b, c);

    return 0;
}