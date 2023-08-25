#include <stdio.h>
#include <math.h>

void quadratic_formula(double a_input, double b_input, double c_input) {
 double one_x = (-b_input + sqrt(pow(b_input,2) - (4*a_input*c_input))) / (2*a_input);
 double two_x = (-b_input - sqrt(pow(b_input,2) - (4*a_input*c_input))) / (2*a_input);
 
 if ((pow(b_input,2) - (4*a_input*c_input)) > 0){
    printf("There are 2 real solutions");
    printf("Solution 1: %.2f", one_x);
    printf("Solution 2: %.2f", two_x);
 }
 if ((pow(b_input,2) - (4*a_input*c_input)) == 0){
     printf("There is one real solution: %.2f", one_x);
 }
 
 if ((pow(b_input,2) - (4*a_input*c_input)) < 0){
     printf("There are no real solutions");
 }
}

int main(){
 double a_input;
 double b_input;
 double c_input;

 printf("Given a quadratic equation of the form a*x^2 + b*x + c");

 printf("Please enter a: ");
 scanf("%lf", &a_input);

 printf("Please enter b: ");
 scanf("%lf", &b_input);

 printf("Please enter c: ");
 scanf("%lf", &c_input);

 quadratic_formula(a_input, b_input, c_input);

    return 0;
}