//Rameen Khan quad.c
//Use the quadratic formula to find the solution for x from ax^2 + bx + c 

#include <stdio.h>
#include <math.h>

double useQuad2(double a, double b, double c); //Function for second solution 
double useQuad1(double a, double b, double c); //Function for first solution
double useQuad(double a, double b); //Function for only solution


int main(void) {
    double a, b, c; //Given values in ax^2 + bx + c
    double d; //Determinant
    double sol1 = 0, sol2 = 0, sol = 0; //First and second solutions, Only solution

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf",&a);

    printf("Please enter b: ");
    scanf("%lf",&b);

    printf("Please enter c: ");
    scanf("%lf",&c);

    d = pow(b,2) - (4 * a * c);

    if (d < 0) {
        printf("There are no real solutions");
    }
    else if (d == 0) {
        sol = useQuad(a, b);
        printf("There is one real solution: %.2lf", sol);
    }
    else if (d > 0) {
        sol1 = useQuad1(a, b, c);
        sol2 = useQuad2(a, b, c);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", sol1);
        printf("Solution 2: %.2lf", sol2);
    }

    return 0;

}

double useQuad1(double a, double b, double c) {
    return (-b + sqrt(((pow(b, 2)) - (4 * a * c)))) / (2 * a);
}

double useQuad2(double a, double b, double c) {
    return (-b - sqrt(((pow(b, 2)) - (4 * a * c)))) / (2 * a);
}

double useQuad(double a, double b) {
    return -b / (2 * a);
} 