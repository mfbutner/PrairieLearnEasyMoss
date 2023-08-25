//this programs asks the user to input a, b, and c of a quadratic equation of the form ax^2+bx+c and calculates its roots
#include <stdio.h>
#include <math.h>


double calc_discriminant(double a, double b, double c);
int main(void);

//first function to calculate the discriminant which will determine how many solutions there are to the equation
double calc_discriminant(double a, double b, double c) {
        return b*b -4*a*c;
}
//second function that will calculate the solution(s) of the equation based on the value of the discriminant
int main(void) {

        printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
        double a, b, c;
        printf("Please enter a: ");
        scanf("%lf", &a);
        printf("Please enter b: ");
        scanf("%lf", &b);
        printf("Please enter c: ");
        scanf("%lf", &c);

        double discriminant = calc_discriminant(a, b, c);
        
        if(discriminant < 0) {
                printf("There are no real solutions\n");
        } else if(discriminant > 0) {
                double first_soln = (-b + sqrt(discriminant))/(2*a); 
                double second_soln = (-b - sqrt(discriminant))/(2*a);
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2f\n", first_soln);
                printf("Solution 2: %.2f\n", second_soln);
        } else {
                double soln = -b/(2*a);
                printf("There is one real solution: %.2f\n", soln);
        }
        
        return 0;
}