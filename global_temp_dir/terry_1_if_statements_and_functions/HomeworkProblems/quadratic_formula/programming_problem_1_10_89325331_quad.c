#include <stdio.h>
#include <math.h>

// the program will take in A,B,C from the user and return all the real solutions to the user
double sqrt_discriminant(double a, double b, double c);
void quadratic(double a, double b, double c);

int main() {
    //this is the main function that will take in input and pass it to the quadratic function, which will return the solutions if there are any
    double a;
    double b;
    double c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    quadratic(a,b,c);

    return 0;

}

double sqrt_discriminant(double a, double b, double c) {
    //returns the square root of the discriminant
    double sqrt_discriminant;

    double inside_discriminant = b*b - 4 * a *  c;
    if (inside_discriminant >= 0) {
        sqrt_discriminant = sqrt(inside_discriminant);
        return sqrt_discriminant;
    } 
    else {
        //any negative number that we can detect in the other function
        return -1;
    }
}

void quadratic(double a, double b, double c) {
    //this function prints out the expected responses after calculating the solutions to the quadratic formula
    double discriminant = sqrt_discriminant(a,b,c);
    double solution1;
    double solution2;
    if (discriminant == 0 ) {
        solution1 = -b/(a * 2);
        printf("There is one real solution: %.2lf", solution1);
    }

    else if ( discriminant > 0) {
        solution1 = (-b + discriminant)/(a * 2);
        solution2 = (-b - discriminant)/(a * 2);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }
    else {
        printf("There are no real solutions");
    }
}


