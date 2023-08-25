#include <stdio.h>
#include <math.h>

int main(){

    //declare varibles
    double a, b, c; //input
    double x1, x2; //roots
    double d; //variable to determine if roots exist

    //print the statements
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf("%lf", &a);
    
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    printf("Please enter c: ");
    scanf("%lf", &c);

    //formulas for two roots
    x1 = (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
    x2 = (-b - sqrt(pow(b,2)-4*a*c))/(2*a);

    //determine if there is any root in the function
    d = pow(b,2)-4*a*c;

    //no root for d<0
    if (d < 0) {

        printf("There are no real solutions\n");

    //two roots for d>0
    } else if (d > 0) {

        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", x1);
        printf("Solution 2: %.2f\n", x2);

    //one root for d=0
    } else {

        printf("There is one real solution: %.2f\n", x1);

    }
    
    return 0;

}
