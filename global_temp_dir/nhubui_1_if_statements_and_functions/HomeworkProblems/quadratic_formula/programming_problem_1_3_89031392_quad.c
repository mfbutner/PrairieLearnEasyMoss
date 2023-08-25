#include <stdio.h>
#include <math.h>

void calculate(double a, double b, double c){
//create variable x1 and x2 which are the roots of the quadratic equation
    double x1, x2;
//calculate the discriminant    
    double d = pow(b,2) - 4*a*c; //calculate the discriminant
    if (d <0){
//if the discriminant is smaller than 0, announce that there is no real solution
        printf("There are no real solutions"); 

    } else if (d == 0){
//if the discriminant is 0, then there is only 1 real solution 
        x1 =  (-b + sqrt(pow(b, 2) -4*a*c))/(2*a);
//announce the result in 2 decimals place
        printf("There is one real solution: %.2lf", x1);

    } else{
//if the discriminant is larger than 0, then there are 2 real solutions. 
        x1 = (-b + sqrt(pow(b, 2) -4*a*c))/(2*a);
        x2 = (-b - sqrt(pow(b, 2) -4*a*c))/(2*a);
//announce the result
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", x1);
        printf("Solution 2: %.2lf", x2);
    }
    
}
int main() {
//declare the double type variable a, b, c to plug into the quadratic formula
    double a, b, c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a); //a is the number that precedes x^2
    printf("Please enter b: ");
    scanf(" %lf", &b); //b is the number that precedes x
    printf("Please enter c: ");
    scanf(" %lf", &c); //c is the last number in the equation
    calculate(a, b, c); //calculate the root of the problem set up with teh user's inputs
    return 0; //0 means success

}