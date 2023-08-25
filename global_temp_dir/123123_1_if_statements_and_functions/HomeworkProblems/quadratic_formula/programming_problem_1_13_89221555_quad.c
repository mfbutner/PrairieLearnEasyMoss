#include <stdio.h>
#include <math.h>
/*
In this program, by given a quadrtic equation, we can check whether it has real solutions, 
and calculate the solutions by given formula.
*/

double determinant(double a, double b, double c){
    double deter = b*b - 4*a*c; 
    // this is a function determinant to get solution using a , b , c
    // a,b,c are paremeter of determinant, they are values of quadratic function
    return deter;
    // this function return b*b - 4*a*c
}

int main(){
    double a;
    double b;
    double c;
    // ask the values of paremeter of quafratic equation
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n\n");

    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("\n");
    printf("\nPlease enter b: ");
    scanf("%lf", &b);
    printf("\n");
    printf("\nPlease enter c: ");
    scanf("%lf", &c);
    printf("\n");
    double det = determinant(a, b, c);
    // call the function determinant and return the value of b*b - 4*a*c
    if (det > 0){
        double positive_det_sol = (-b + pow(det, 0.5)) / (2*a);
        double negative_det_sol = (-b - pow(det, 0.5)) / (2*a);
        // ask the positive and negative solutions
        printf("\nThere are 2 real solutions\n");
        printf("\nSolution 1: %.2lf\n", positive_det_sol); 
        printf("\nSolution 2: %.2lf\n", negative_det_sol);
    }
    else if (det == 0){
        double det_sol = (-b) / (2*a);
        // ask the solution when det == 0
        printf("\nThere is one real solution: %.2lf\n", det_sol);
    }
    else {
        printf("\nThere are no real solutions\n");
    }
    return 0;
}


 


