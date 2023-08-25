#include <stdio.h>
#include <math.h>

// This program is to find real solutions of a quadratic equation

int main(void){
    double a, b, c;//setup 3 constant numbers for equation
    double x1, x2; //setup 2 roots for  equation
    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n");
    
    // ask the number of a, b, c
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    // calculate delta to see how many solutions the equation have
    double delta = b*b - 4*a*c;
    
    // distinguish delta into three situations and calculate the real roots
    if (delta > 0){
        x1 = (-1*b + sqrt(delta))/(2*a); 
        x2 = (-1*b - sqrt(delta))/(2*a);//this parameter is the solve of quadratic equation
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", x1);
        printf("Solution 2: %.2lf\n", x2);//2 decimal points
    }else if (delta == 0){
        x1 = x2 = (-1*b)/(2*a);//this parameter is the solve of quadratic equation when delta equal to zero
        printf("There is one real solution: %.2lf", x1);//2 decimal points
    }else if (delta < 0){
        printf("There are no real solutions");// there is no solution when delta is less than zero
    }

    return 0;
}