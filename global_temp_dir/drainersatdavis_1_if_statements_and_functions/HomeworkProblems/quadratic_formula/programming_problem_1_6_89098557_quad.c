/*
HW 3.1 Quadratic Formula by E Chan

This program takes in user input for values of a, b, and c for a quadratic
equation of ax^2 + bx + c. Then, the program determines the number of real roots
by calculating the equation's discriminant. If there is at least one real root,
the program will calculate the root(s) and output them.
*/

#include <stdio.h>
#include <math.h>

// function for calculating discriminant (b^2 - 4ac)
// a = a value in quadratic equation ax^2 + bx + c
// b - b value in quadratic equation ax^2 + bx + c
// c = c value in quadratic equation ax^2 + bx + c
// returns calculated discriminant of quadratic equation
double calculate_discriminant(double a, double b, double c) {
  double result;
  result = pow(b, 2);
  result -= (4 * a * c);
  return result;
}
// function for quadratic formula when adding square root of discriminant
// a = a value in quadratic equation ax^2 + bx + c
// b - b value in quadratic equation ax^2 + bx + c
// discrim = discriminant calculated from calculate_discriminant
// returns calculated real root when adding square root of discriminant
double calculate_plus_root(double a, double b, double discrim) {
  double plus_root = -b;
  plus_root += pow(discrim, 0.5);
  plus_root /= (2 * a);
  return plus_root;
}
// function for quadratic formula when subtracting square root of discriminant
// a = a value in quadratic equation ax^2 + bx + c
// b - b value in quadratic equation ax^2 + bx + c
// discrim = discriminant calculated from calculate_discriminant
// returns calculated real root when subtracting square root of discriminant
double calculate_minus_root(double a, double b, double discrim) {
  double minus_root = -b;
  minus_root -= pow(discrim, 0.5);
  minus_root /= (2 * a);
  return minus_root;
}

int main() {
  // variables
  double a_value;
  double b_value;
  double c_value;
  double discriminant;
  double plus_root;
  double minus_root;

  // get user input for quadratic equation
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a_value);
  printf("Please enter b: ");
  scanf("%lf", &b_value);
  printf("Please enter c: ");
  scanf("%lf", &c_value);

  // determine number of real roots by calculating discriminant
  discriminant = calculate_discriminant(a_value, b_value, c_value);

  // if discriminant is negative, print out that there are no real roots
  if (discriminant < 0) {
    printf("There are no real solutions\n");
  }
  // calculate real root(s) if there are any
  // discriminant equals zero => one root
  else if (fabs(discriminant - 0.0) < 0.000000000000001) {
    plus_root = calculate_plus_root(a_value, b_value, discriminant);
    printf("There is one real solution: %.2lf\n", plus_root);
  }
  // discriminant is positive => two roots
  else if(discriminant > 0) {
    plus_root = calculate_plus_root(a_value, b_value, discriminant);
    minus_root = calculate_minus_root(a_value, b_value, discriminant);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", plus_root);
    printf("Solution 2: %.2lf\n", minus_root);
  }


  return 0;
}
