#include <stdio.h>
#include <math.h>
//our program will take user input and calculate the quadratic formula in pieces using two functions to calulcate b+sqrt anf b-sqrt
//this function calculates the quadratic formula in pieces with adding b to the square root
double quadratic_equation_positive(double a,double b,double c) 
{
    double b_on_itsown = -b;
    double square_root = sqrt(b * b - 4 * a * c);
    double denominator = 2 * a;

    double quad = (b_on_itsown+square_root)/denominator;
    return quad;
  

}

//this function calculates the quadratic formula in pieces by subtracting b to the square root
double quadratic_equation_negative(double a,double b,double c) 
{
    double b_on_itsown = -b;
    double square_root = sqrt(b * b - 4 * a * c);
    double denominator = 2 * a;
    double quad = (b_on_itsown-square_root)/denominator;
    return quad;
}

int main() {

double a = 1;
double b = 2;
double c = 3;

//ask user for input
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

printf("Please enter a:");
scanf("%lf",&a);

printf("Please enter b:");
scanf("%lf",&b);

printf("Please enter c:");
scanf("%lf",&c);

double d = sqrt((b * b) - (4 * a * c));

//setting both quadratic solutions for negative and positive as variables
double positive = quadratic_equation_positive(a,b,c);
double negative = quadratic_equation_negative(a, b, c);


//if d is zero there is only one solution
if (d == 0) {
    double quad = quadratic_equation_positive(a,b,c);
    printf("There is one real solution: %.2lf", quad);
}
//if d is more than 0 there is two solutions
else if (d > 0)
{
    printf("There are 2 real solutions\n Solution 1: %.2lf\n Solution 2: %.2lf", positive, negative);

}
else{
    printf("There are no real solutions");
}


    return 0;
}