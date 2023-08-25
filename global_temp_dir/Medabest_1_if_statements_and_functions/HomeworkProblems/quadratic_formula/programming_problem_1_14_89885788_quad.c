#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//program that gets values from the user for the quadratic formula, then computes them

void calc_formula(double a, double b, double c){
//calculates the formula with values a,b, and c being passed from main as its parameters
//doesn't return anything, only prints the amount of solutions
    double inRoot, x1, x2;
    inRoot = pow(b,2) - (4 * a * c);
    if(inRoot < 0){
      printf("There are no real solutions");
      exit(0);
    }else{
      x1 = (-b + sqrt(inRoot)) / (2 * a);
      x2 = (-b - sqrt(inRoot)) / (2 * a);
    }if(x1 != x2){
      printf("There are 2 real solutions");
      printf("Solution 1: %.2lf", x1);
      printf("Solution 2: %.2lf", x2);
    }else if(x1 == x2){
      printf("There is one real solution: %.2lf", x1);
    }
  }



int main(){
//gets values for a, b, c in the quadratic formula, and sends them off to get calculated
double a;
double b;
double c;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);
  calc_formula(a, b, c);
  return 0;
}
