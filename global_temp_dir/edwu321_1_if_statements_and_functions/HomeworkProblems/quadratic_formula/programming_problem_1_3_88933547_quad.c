// Edwin Wu
// ECS 36A
// HW 3.1
// This program calculates the roots and the amount of roots of x by  using the quadratic equation and asking users to define each variable in the equation.
#include <stdio.h>
#include <math.h>


/*
 * Calculates only the real roots given values a, b, and c while excluding imaginary roots
 * Parameters are that the calculated x has to be greater than or equal to 0 to be a real root number.
 * Returns the number of real roots (0, 1, or 2)
 * return 0; if no error and >0 if any errors
 */
int rootCalculater(double a, double b, double c) {
  double discriminant;
  discriminant = b*b - (4*a*c);

  // check if discriminant is positive, negative, or 0
  if (discriminant > 0) {
    // two real roots
    double firstRoot = (-b + sqrt(discriminant)) / (2 * a);
    double secondRoot = (-b - sqrt(discriminant)) / (2 * a);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", firstRoot);
    printf("Solution 2: %.2lf\n", secondRoot);
    return 0;
  } 
    else if (discriminant == 0) {
    // one real root
    double root = -b / (2 * a);
    printf("There is one real solution: %.2lf\n", root);
    return 0;
  } 
    else {
    // no real roots because not solving for imaginary/complex roots.
    printf("There are no real solutions\n");
    return 0;
  }
}

int main(void) {
  double a, b, c;

  
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);
  
  
  rootCalculater(a, b, c);
  

  return 0;
}