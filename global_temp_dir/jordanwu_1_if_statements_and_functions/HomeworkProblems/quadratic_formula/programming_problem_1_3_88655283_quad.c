#include <stdio.h>
#include <math.h>

double collect_a() {
// this function collects user input for a
 // initilaizing variable
double a;
printf("Given a quadratic equation of the form  a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf("%lf", &a);
    return a;
}

double collect_b() {
    // this fuctions collects user inoput for b
double b; // intilazing variable
printf("Please enter b: ");
scanf("%lf", &b);
    return b;
}
double collect_c() {
    // this function collectes user input for c
double c; // initlazing varaible
printf("Please enter c: "); 
scanf("%lf", &c);
    return c;
}


int main () {
// initazing variables
double discriminant; 
double root_one;
double root_two;
double root;
double a, b, c;

// call fucntions to get our user input
a = collect_a();
b = collect_b();
c = collect_c();

// solve for the discriminant 
// solving for the discriminant will help us determine how many roots there are
    discriminant = (b * b) - (4 * a * c);

   // this calculates two real roots
    if (discriminant > 0) {
        root_one = ((-b + sqrt(discriminant)) / (2 * a)); // calculates 1st root by adding
        root_two = ((-b - sqrt(discriminant))/ (2 * a)); // calculates 2nd root by subtracting
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root_one);
        printf("Solution 2: %.2lf", root_two);
    }
    // calculates the one real root
    else if (discriminant == 0) {
        root = (-b / (2 * a)); // calcs the one real root (the roots are the same)
        printf("There is one real solution: %.2lf", root); 
    }
    // there are no real roots / solutions
    else {
        printf("There are no real solutions");
    }
    return 0;
}
