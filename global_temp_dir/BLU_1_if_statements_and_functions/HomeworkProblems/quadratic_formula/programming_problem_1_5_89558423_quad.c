#include <stdio.h>
#include <math.h>
/* uses values a, b, and c gathered from user input to calculate the roots of a corresponding quadratic equation using the quadratic formula, and then displays the number of roots along with the roots themselves to the screen*/
double getA(){
    /*gets a*/
    double a; 
    printf(" Please enter a:");
    scanf("%lf", &a);
    return a;
}

double getB(){
    /*gets b*/
    double b; 
    printf(" Please enter b:");
    scanf("%lf", &b);
    return b;
}

double getC(){
    /*gets c*/
    double c; 
    printf(" Please enter c:");
    scanf("%lf", &c);
    return c;
}

double calculateDiscriminant(double a, double b, double c){
    /*calculates the discrimant based on values a, b, and c*/
    double discriminant = (pow(b, 2)) - (4 * a * c);
    return discriminant;
}

double determineAmountOfRoots(double discriminant){
    /*determines how many roots exist*/
    int rootNumber;
    rootNumber = 0;
    if (discriminant > 0){
        rootNumber = 2;
    }else if (discriminant == 0){
        rootNumber = 1;
    }else if (discriminant < 0){
        rootNumber = 0; 
    }return rootNumber;
}

double calculatePlusVersionofQuadFormula(double a, double b, double discriminant){
    /*calculates one of the roots by using the plus version of the formula*/
    double plusRoot = (-b + sqrt(discriminant)) / (2 * a);
    return plusRoot;
}

double calculateMinusVersionofQuadFormula(double a, double b, double discriminant){
    /*calcualtes the other root by using the minus version of the formula*/
    double minusRoot = (-b - sqrt(discriminant)) / (2 * a);
    return minusRoot;
}

int main(){
    /*main umbrella function that displays the roots*/
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    double a = getA(); double b = getB(); double c = getC(); double discriminant = calculateDiscriminant(a, b, c); int rootNumber = determineAmountOfRoots(discriminant);
    double plusRoot = calculatePlusVersionofQuadFormula(a, b, discriminant); double minusRoot = calculateMinusVersionofQuadFormula(a, b, discriminant);
    switch (rootNumber){
        case 2:
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", plusRoot, minusRoot);
        break;
        case 1:
        printf("There is one real solution:%.2lf", plusRoot);
        break;
        case 0:
        printf("There are no real solutions");
        break;
    }
    return 0;
}