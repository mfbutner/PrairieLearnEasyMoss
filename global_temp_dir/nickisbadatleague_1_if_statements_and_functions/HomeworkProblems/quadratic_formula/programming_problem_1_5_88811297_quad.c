//Solves the quadratic formula

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Finds the first solution
double plus(double a,double b, double determinant){ //a is a from the user, b is b from the user, determinant is the determinant from main
    double sol = -b + sqrt(determinant);
    sol = sol/(2*a);
    return sol; //returns first solution
}

//Finds the second solution
double minus(double a,double b, double determinant){//a is a from the user, b is b from the user, determinant is the determinant from main
    double sol = -b - sqrt(determinant);
    sol = sol/(2*a);
    return sol; //returns second solution
}

int main(void) { //collects all the necessary information from the user
    double a;
    double b;
    double c;
    double solution1;
    double solution2;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    double determinant = pow(b,2) - 4*a*c;
    solution1 = plus(a,b,determinant);
    solution2 = minus(a,b,determinant);
    if (determinant < 0) { 
        printf("There are no real solutions");
    } 
    else if (determinant == 0){
        printf("There is one real solution: %.2f", solution1);
    }
    else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf", solution2);
    }
    return 0;
}
