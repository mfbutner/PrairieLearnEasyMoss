#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//imported libraries

//program takes in the a b and c coefficients for a quadratic and solves it


//gets the a coefficient
double inputA() {
  double a;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a:\n");
  scanf("%lf", &a);
  return a;
}

//gets the b coefficient
double inputB() {
  double b;
  printf("Please enter b:\n");
  scanf("%lf", &b);
  return b;
}

//gets the c coefficient
double inputC() {
  double c;
  printf("Please enter c:\n");
  scanf("%lf", &c);
  return c;
}


//checks if discriminant is positive
bool ifValidDiscriminant(double coefficientA, double coefficientB , double coefficientC) {
  if ((pow(coefficientB,2) - 4 * coefficientA * coefficientC) >= 0) {
    return true;
  } else {
    return false;
  }
}

//solves quadratic formula and outputs if solutions if any
void quadraticFormulaSolver(double a, double b, double c) {
  double answer1;
  double answer2;
  if (ifValidDiscriminant(a,b,c) == false) {
    printf("There are no real solutions");
  } else {
    answer1 = (0 - b + sqrt(pow(b, 2) - 4 * a * c))/(2 * a);
    answer2 = (0 - b - sqrt(pow(b, 2) - 4 * a * c))/(2 * a);
    if (answer1 == answer2) {
      printf("There is one real solution: %.2lf", answer1);
    } else {
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n", answer1);
      printf("Solution 2: %.2lf\n", answer2);
    }
  }
}
//runs functions to get inputs and stores them for the quadratic formula function
int main(){
  double coefficientA = inputA();
  double coefficientB = inputB();
  double coefficientC = inputC();
  quadraticFormulaSolver(coefficientA, coefficientB, coefficientC);
  return 0;
}
