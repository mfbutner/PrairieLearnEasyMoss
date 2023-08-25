#include <stdio.h>
#include <math.h>

/*
 * Write a program that calculates the quadratic formula
 * Tells the user how many solutions there are and what they are
 */

// a b and c are all variables in the quadratic formula

int quadCalc(double a, double b, double c);

int main(){
    // Main function that gets the inputs from the user and passes them into the 
    // Quad calc function as parameters
    double a, b, c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    quadCalc(a, b, c);

    return 0;
}

 int quadCalc(double a, double b, double c){
    //calculate discriminant, then use if statement to determine the amount of real results
    //display the results
    double discriminant = (pow(b, 2)) - (4 * (a * c));

    if(discriminant < 0){
        printf("There are no real solutions\n");
    }
    else if(discriminant == 0){
        double result = ( -b / (2 * a));
        printf("There is one real solution: %.2lf\n", result);
    }else{
        double result1 = ((-b + sqrt(discriminant)) / (2 * a));
        double result2 = ((-b - sqrt(discriminant)) / (2 * a));
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", result1);
        printf("Solution 2: %.2lf\n", result2);
    }
    
    return 0;
}