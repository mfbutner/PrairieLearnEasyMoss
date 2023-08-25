#include <stdio.h>
#include <math.h>

// This is a program to compute the real root(s) in quadratic equation
// we need to consider different numbers of root(s) and 
// output the value(s) and the number of roots

// use a function to define the discriminant
double Calcdiscriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}
int main(){
    double a,b,c;
    double discriminant;
    double x1,x2;

    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&a);
    printf("Please enter b: ");
    scanf("%lf",&b);
    printf("Please enter c: ");
    scanf("%lf",&c);
    // get coefficent of quadratic equation from users
 
    // if discriminant >0, 2 roots
    // if discriminant =0, 1 root
    // if discriminant <0, no root

    //use the function stated ahead
    discriminant = Calcdiscriminant(a,b,c);

    if (discriminant > 0){
        //find 2 roots
        x1 = (-b+sqrt(discriminant))/(2*a);
        x2 = (-b-sqrt(discriminant))/(2*a);

        printf("There are 2 real solutions");
        printf("Solution 1: %.2f",x1);
        printf("Solution 2: %.2f",x2);
    }
    else if (discriminant ==0){
        // find 1 root
        x1 = (-b)/(2*a);
        printf("There is one real solution: %.2f",x1);
    }

    else {
        // there are no roots so we don't need to print value
        printf("There are no real solutions");
    }

    return 0;
}
