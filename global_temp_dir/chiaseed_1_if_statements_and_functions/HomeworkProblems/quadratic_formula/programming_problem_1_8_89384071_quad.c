#include <stdio.h> 
#include <math.h>

/* 
Calculate the roots of a quadratic using the quadratic formula given values a, b, and c 
*/

void CalcRoots(double a, double b, double c);

/**
 * Checks if there is one, two, or no real roots of quadratic by value of discriminant being positive, negative, or a complex value
 * @param a : the user input of the value 'a' from quadratic
 * @param b : the user input of the value 'b' from quadratic
 * @param c : the user input of the value 'c' from quadratic 
 */

void CalcRoots(double a, double b, double c){  
    double discriminant;
    discriminant = pow(b, 2) - (4 * a * c);

    double denoValue;
    denoValue = 2 * a;

    double firstRoot;
    double secondRoot;

    if (discriminant < 0){
        printf("There are no real solutions\n");
    }
    else if (discriminant > 0){
        firstRoot = (-b + sqrt(discriminant)) / denoValue;
        secondRoot = (-b - sqrt(discriminant)) / denoValue;
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", firstRoot);
        printf("Solution 2: %.2lf\n", secondRoot);
    }
    else {
        double Oneroot = -b / denoValue;
        printf("There is one real solution: %.2lf\n", Oneroot);
    }
}

int main(){
    double a;
    double b;
    double c; 
    
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf("%lf", &a);
    
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    printf("Please enter c: ");
    scanf("%lf", &c);
    
    CalcRoots(a, b, c);
    
    return 0;
}