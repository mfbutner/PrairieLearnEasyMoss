/*This is a C program to find the real solutions of a quadratic equation of the form a*x^2 + b * x + c
 find if real solutions exist and the value of the same
 Module: Homework 3 - ECS 36A
 Date : 02/02/2023
 Author: sk */

# include <stdio.h>
#include <math.h>

// declare teh function quad_eqn_solution () which is used to calculate the d  (discriminant)
double quad_eqn_solution (double a, double b, double c);

int main () {

double a;
double b;
double c;
double d;
double real_solution1;
double real_solution2;

printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

printf ("Please enter a:");
scanf ("%lf", &a);

printf ("Please enter b:");
scanf ("%lf", &b);
printf ("Please enter c:");
scanf ("%lf", &c);

/* Assign the restun value of d (discriminant of the quadractic equation)from the quad_eqn_solution () 
and check for three conditions to see if real roots exists or not */

d = quad_eqn_solution (a, b, c);

if (d < 0 )
{
    printf("There are no real solutions");
}
else if (d == 0) {
real_solution1 = -b/(2*a);
printf ("There is one real solution: %.2f", real_solution1);
    }
else {
    real_solution1 = -b + sqrt (d);
   
    real_solution1 = real_solution1/(2*a);
    
   real_solution2 = (- b - sqrt (d));
   
      real_solution2 = real_solution2/(2*a);

 printf("There are 2 real solutions");     
 printf("Solution 1: %.2f\n", real_solution1);
 printf("Solution 2: %.2f\n", real_solution2);
}

}

/* Function quad_eqn_solution () takes the arguements a, b and c of type double. This function calulates the value 
of d (discriminant of quadratic equation) and returns it to main function to check the three conditions to see if real solutions exists or not*/

 double quad_eqn_solution (double a, double b, double c) {

    double d;
    d = (b*b - 4*a*c);
    return d;

}