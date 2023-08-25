//gets the a, b, and c values of a quadratic equation and then uses the quadratic formula to find the solution or solutions if there are any

#include <stdio.h>
#include <math.h>

void calculate(double a, double b, double c);

int main(){ //gets the a, b, and c values of a quadratic equation and calls the calculate function with those values as parameters
    double a;
    double b;
    double c;
    
    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n");
    printf("Please enter a: ");
    scanf(" %lf ", &a);
    printf("Please enter b: ");
    scanf(" %lf ", &b);
    printf("Please enter c: ");
    scanf(" %lf ", &c);
    calculate(a, b, c);

return 0;

}

void calculate(double a, double b, double c){ //receives the a, b and c values of a quadratic equation and runs them through the quadratic formula. Checks to see if the answers exist, are the same or different.
    double solution1;
    double solution2;
    if ((b*b - 4*a*c) < 0){ //also prevents the code from running further if there is a domain error, which would prevent the program from running
        printf("There are no real solutions");
    }
    else if ((b*b - 4*a*c) >= 0){
        solution1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        solution2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (solution1 != solution2){
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", solution1);
            printf("Solution 2: %.2lf\n", solution2);
        }
        else if (solution1 == solution2){
            printf("There is one real solution: %.2lf\n", solution1);
        }
    }

}