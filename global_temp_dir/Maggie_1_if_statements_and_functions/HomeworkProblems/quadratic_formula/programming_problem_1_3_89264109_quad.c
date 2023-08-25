/* This program solves for the quadratic formula:
x = (-b +/- sqrt(b^2 -4ac)) / (2a)
by asking the user to enter values of a, b, and c then tells the solution(s), if any.

CHANGES: I had to input an imaginary number checker that I did not mention in the
first part.
*/

#include <stdio.h>
#include <math.h>

/* Calculates the quadratic formula with the positive sign given the
values a, b, c from main.
@ param a, b, c: these are the a, b, c values in the formula that the user enters.
@ return: returns 0 if there is an imaginary number, otherwise returns x. */
double valInQuadPos(double a, double b, double c) {
  double imaginaryCheckPos, xPos;
  imaginaryCheckPos = (pow(b,2) - 4*a*c);
  if (imaginaryCheckPos >= 0) {
    xPos = (-b + sqrt(pow(b,2) - 4*a*c)) / (2*a);
    return xPos;
  }
  else {
    return 0;
  }
}

/* Calculates the quadratic formula with the negative sign given the
values a, b, c from main.
@ param a, b, c: these are the a, b, c values in the formula that the user enters.
@ return: returns 0 if there is an imaginary number, otherwise returns x. */
double valInQuadNeg(double a, double b, double c) {
  double imaginaryCheckNeg, xNeg;
  imaginaryCheckNeg = (pow(b,2) - 4*a*c);
  if (imaginaryCheckNeg >= 0) {
    xNeg = (-b - sqrt(pow(b,2) - 4*a*c)) / (2*a);
    return xNeg;
  }
  else {
    return 0;
  }
}

/* Tells the user the quadratic formula then asks for values a, b, c from the
formula and runs functions that solves for the formula and returns solutions */
int main() {
  double a, b, c;
  double solutionPos, solutionNeg;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf(" %lf", &a);
  printf("Please enter b: ");
  scanf(" %lf", &b);
  printf("Please enter c: ");
  scanf(" %lf", &c);

  solutionPos = valInQuadPos(a, b, c);
  solutionNeg = valInQuadNeg(a, b, c);

  if (solutionPos && solutionNeg) {
    if (solutionPos == solutionNeg) {
      printf("There is one real solution: %.2lf", solutionPos);
    }
    else {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", solutionPos);
    printf("Solution 2: %.2lf", solutionNeg);
    }
  }

  if (solutionPos && solutionNeg==0) {
    printf("There is one real solution: %.2lf", solutionPos);
  }

  if (solutionNeg && solutionPos==0) {
    printf("There is one real solution: %.2lf", solutionNeg);
  }

  if (solutionNeg==0 && solutionPos==0) {
    printf("There are no real solutions");
  }
}
