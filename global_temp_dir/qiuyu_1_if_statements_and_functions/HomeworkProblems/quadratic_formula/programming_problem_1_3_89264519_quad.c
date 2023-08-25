#include <stdio.h>
#include <math.h>
/*
This program helps to find what are the real solutions in a quadratic equation
with given numbers.
*/

double calculateSolutionNumbers(double a, double b, double c);

int main(){
double a; //input of quadratic equation
double b; //input of quadratic equation
double c; //input of quadratic equation
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf("%lf",&a);

printf("Please enter b: ");
scanf("%lf",&b);

printf("Please enter c: ");
scanf("%lf",&c);

double discriminant = calculateSolutionNumbers(a, b, c);


if (discriminant == 0){
  double solution = (-b)/(2*a);
  printf("There is one real solution: %.2f\n",solution);
}

else if (discriminant > 0){
  double solution1 = (-b + sqrt(discriminant))/(2*a);
  double solution2 = (-b - sqrt(discriminant))/(2*a);
  printf ("There are 2 real solutions\n");
  printf("Solution 1: %.2f\n", solution1);
  printf("Solution 2: %.2f\n", solution2);
}

else{
printf("There are no real solutions\n");
}


  return 0;
//return integer 0 so the program can run
}
//This function helps to find how many real solutions are in a quadratic equation
double calculateSolutionNumbers(double a, double b, double c){

return (b*b) -(4*a*c);
// this function return discriminant, which helps us to determine number of solutions in a quadratic equation
}
