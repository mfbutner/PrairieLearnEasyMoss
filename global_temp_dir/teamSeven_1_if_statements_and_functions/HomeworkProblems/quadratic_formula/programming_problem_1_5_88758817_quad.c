#include <stdio.h>
#include <math.h>

//this program calculates using the quadratic formula

double plusQuadratic(double a, double b, double c){

    double discriminant;
    double squareRoot;
    double numerator;
    double denominator;
    double finalResult;

    //calculates inside the square root
    discriminant = (b * b) - (4*a*c);

    //squareroot result
    squareRoot = sqrt(discriminant);

    //-b + squareRoot
    numerator = (-1 * b) + squareRoot;

    //divide by denominator
    denominator = 2 * a;
    finalResult = numerator / denominator;

    return finalResult;
}

double subtractQuadratic(double a, double b, double c){

    double discriminant;
    double squareRoot;
    double numerator;
    double denominator;
    double finalResult;

    //calculates inside the square root
    discriminant = (b * b) - (4*a*c);

    //squareroot result
    squareRoot = sqrt(discriminant);

    //-b - squareRoot
    numerator = (-1 * b) - squareRoot;

    //divide by denominator
    denominator = 2 * a;
    finalResult = numerator / denominator;

    return finalResult;
}

int main(){

    double userA;
    double userB;
    double userC;
    double discriminant;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    //gets a
    printf("Please enter a: ");
    scanf("%lf", &userA);

    //gets b
    printf("Please enter b: ");
    scanf("%lf", &userB);

    //gets c
    printf("Please enter c: ");
    scanf("%lf", &userC);

    discriminant = (userB * userB) - (4 * userA * userC);

    if(discriminant == 0){
    printf("There is one real solution: %.2lf", plusQuadratic(userA, userB, userC));
    }

    else if(discriminant > 0){
    printf("There are 2 real solutions \n");
    printf("Solution 1: %.2lf\n", plusQuadratic(userA, userB, userC));
    printf("Solution 2: %.2lf\n", subtractQuadratic(userA, userB, userC));
    }

    else if(discriminant < 0){
    printf("There are no real solutions");
    }

    return 0;

}