#include <stdio.h>
#include <math.h>

// This function receive the parameters a, b, c, and a pointer to
// x1 and x2 which will be the solutions. The function uses the quadratic 
// formula and calculates the roots and updates the variable at x1 and x2.
// returns the number of real roots: 0, 1, or 2

int calculateRoots(double a, double b, double c, double *x1, double *x2){
    double discriminant = pow(b,2) - 4*a*c;
    if (discriminant < 0){
        return 0;
    }
    else if (discriminant == 0){
        *x1 = -b /(2*a);
        return 1;
    } else {
        *x1 = (-b + sqrt(discriminant))/(2*a);
        *x2 = (-b - sqrt(discriminant))/(2*a);
        return 2;
    }
}

int main(){
    double a,b,c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&a);
    printf("Please enter b: ");
    scanf("%lf",&b);
    printf("Please enter c: ");
    scanf("%lf",&c);
    double x1,x2;
    int result =  calculateRoots(a, b, c, &x1, &x2);
    if (result == 0){
        printf("There are no real solutions");
    } else if (result == 1){
        printf("There is one real solution: %.2lf",x1);
    } else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", x1);
        printf("Solution 2: %.2lf\n", x2);
    }
}