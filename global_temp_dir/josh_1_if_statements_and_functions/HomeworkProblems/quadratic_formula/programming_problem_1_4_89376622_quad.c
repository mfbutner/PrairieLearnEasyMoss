#include <stdio.h>
#include <math.h>
//This program asks the user for a,b,c values of the quadratic equation.
//Then, it solves for the real solutions. It determines how many real solutions exists and returns the solutions.

//This function uses the determinant to find how many real solutions exist.
//Then, using the quadratic equation the function prints the solutions.
//The parameters are a,b,c from the quadratic equation obtained form the user in the main function. 
void solution(double a, double b, double c){
    double discriminant;
    double x1;
    double x2;

    discriminant = b*b-4*a*c;
    if (discriminant > 0){
        printf("There are 2 real solutions\n");
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Solution 1: %.2lf\nSolution 2: %.2lf", x1, x2);
    }
    else if (discriminant == 0){
        x1 = -b / (2*a);
        printf("There is one real solution: %.2lf", x1);
    }
    else if (discriminant < 0){
        printf("There are no real solutions");
    }

}

//This main function asks users for the values of a, b, c from the quadratic equation.
//Then, it calls the solution function to obtain the number of solutions and the solutions.
int main(){
    double a, b, c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    solution(a, b, c);

}