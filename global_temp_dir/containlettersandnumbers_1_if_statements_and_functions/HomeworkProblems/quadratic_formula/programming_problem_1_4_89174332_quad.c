#include <stdio.h>
#include <math.h>

/*
  This program calculates the roots
  of a quadratic equation
*/

void QuadraticEquation(double a, double b, double c);
int NumSolutions(double a, double b, double c);

int main() {
  double coefficientA, coefficientB, constantC;


  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf(" %lf", &coefficientA);

  printf("Please enter b: ");
  scanf(" %lf", &coefficientB);

  printf("Please enter c: ");
  scanf(" %lf", &constantC);

  QuadraticEquation(coefficientA, coefficientB, constantC);

  return 0;
}

void QuadraticEquation(double a, double b, double c) {
  /*
    Calculates the soultions to a quadratic equation using the form ax^2 + bx + c and outputs them
    @a: The a coefficient in the quadratic equation
    @b: The b coefficient in the quadratic equation
    @c: The c constant in the quadratic equation
  */

  double solution1, solution2;

  switch (NumSolutions(a, b, c)) {
    case 0:
      printf("There are no real solutions\n");
      break;
    case 1:
      solution1 = -b / (2 * a);
      printf("There is one real solution: %.2lf\n", solution1);
      break;
    case 2:
      solution1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
      solution2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n", solution1);
      printf("Solution 2: %.2lf\n", solution2);
      break;
  }

}

int NumSolutions(double a, double b, double c) {
  /*
    Determines how many solutions are in a quadratic equation
    @a: The a coefficient in the quadratic equation
    @b: The b coefficient in the quadratic equation
    @c: The c constant in the quadratic equation
    @returns: 0 if there are no solutions, 1 if there is one solution, 2 if there are two solutions
  */

 // Checks the result of the squareroot's interior to see how many solutions will be yielded
  double equationRootContents = pow(b, 2) - 4 * a * c;
  if (equationRootContents < 0) {
    return 0;
  } else if (equationRootContents == 0) {
    return 1;
  } else {
    return 2;
  }

}