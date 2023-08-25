#include <stdio.h>
#include <math.h>

/*
quad.c
Nathan Rohnow
Program finds the roots from the equation ax^2+bx+case
*/
double getDiscriminant(double a, double b, double c);
double quadFormulaPositive(double a, double b, double c);
double quadFormulaNegative(double a, double b, double c);

double quadFormulaPositive(double a, double b, double c) {
  double numerator = (-1 * b) + sqrt(pow(b, 2) - ( 4 * a * c));
  double denominator = (2 * a);
  return (numerator / denominator);
}
double quadFormulaNegative(double a, double b, double c) {
  double numerator = (-1 * b) - sqrt(pow(b, 2) - ( 4 * a * c));
  double denominator = (2 * a);
  return (numerator / denominator);
}
double getDiscriminant(double a, double b, double c) {
  return (pow(b, 2) - (4 * a * c));
}


int main() {
  double a;
  double b;
  double c;
  double discriminant;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf(" %lf", &a);
  printf("Please enter b: ");
  scanf(" %lf", &b);
  printf("Please enter c: ");
  scanf(" %lf", &c);

  discriminant = getDiscriminant(a, b, c);
  if (discriminant > 0) {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2f\n", quadFormulaPositive(a, b, c));
    printf("Solution 2: %.2f\n", quadFormulaNegative(a, b, c));
  }
  else if (discriminant == 0) {
    printf("There is one real solution: %.2f", quadFormulaPositive(a, b, c));
  }
  else if (discriminant < 0) {
    printf("There are no real solutions");
  }
  return 0;
}
