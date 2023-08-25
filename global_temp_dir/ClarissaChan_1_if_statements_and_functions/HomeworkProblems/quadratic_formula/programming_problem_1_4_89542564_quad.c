#include <stdio.h>
#include <math.h>

/* a program that solves a quadratic equation given the values
of a, b, and c from the user*/

double calc_discriminant(double a, double b, double c);

int main(){ //gets user input of the values a, b, and c
    double a; // variable for a
    double b; // variable for b
    double c; // varaiable for c
    double root1; //variable for the positive root if there are 2 solutions
    double root2; //variable for negative root if there are 2 solutions
    double one_root; //variable for root with only one solution
    

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    double discriminant = calc_discriminant(a, b, c); // varaiable for the discriminant
    
    if(discriminant < 0){
        printf("There are no real solutions");
    } else if(discriminant > 0) {
        root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", root1);
        printf("Solution 2: %.2f\n", root2);
    } else {
        one_root = -b/(2*a);
        printf("There is one real solution: %.2f\n", one_root);
    }


    return 0; // returns user input and the solutions
}

double calc_discriminant(double a, double b, double c){ //this function calucluates the discriminant to find out how many solutions there are
    return b*b - 4*a*c; //returns discriminant
} 
