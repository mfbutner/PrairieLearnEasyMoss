#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double findNumerator(double b, double radical)
{
  /*
   * Finds the value of a numerator for the solution.
   * @b: user value for coefficient b
   * @discriminant: value stored from findDiscriminant function.
   * @returns: -b + radical
   */
  return (b * -1) + radical;
}

double findDiscriminant(double a, double b, double c)
{
  /*
   * Finds the value of the discriminant.
   * @a: user value for coefficient a
   * @b: user value for coefficient b
   * @c: user value for coefficient c
   * @returns: b^2 - 4ac
   */
  return (b * b) - (4 * a * c);
}

int main(){

/* This program takes user input for values a, b, and c in the polynomial
 * ax^2 + bx + c and returns the values of the real roots.
 */

/* Variables to store coefficients, discriminant, number of solutions,
 * two numerators, one denominator, radical portion of numerator.
 */
 double a, b, c, discriminant, numerator1, numerator2, denominator, radical;
 int numSolutions;

// Ask user for coefficient values, store in variables
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

  printf("Please enter a: ");
  scanf(" %lf", &a);

  printf("Please enter b: ");
  scanf(" %lf", &b);

  printf("Please enter c: ");
  scanf(" %lf", &c);

/* Find the number of real solutions. If discriminant is positive, there
 * are two real solutions. If discriminant is zero, there is one real
 * solution. If discriminant is negative, there are no real solutions.
 */

  discriminant = findDiscriminant(a, b, c);

  if(discriminant > 0)
  {
    numSolutions = 2;
  }
  else if(discriminant == 0)
  {
    numSolutions = 1;
  }
  else
  {
    numSolutions = 0;
    printf("There are no real solutions\n");
    exit(0);
  }

// Find the radical portion of the numerator(s).
  radical = sqrt(discriminant);

// Find the numerator(s).
  numerator1 = findNumerator(b, radical);

  if(numSolutions == 2)
  {
    numerator2 = findNumerator(b, radical * -1);
  }

// Find the denominator.
  denominator = a * 2;

// Divides numerator(s) by denominator and prints solution(s).
  if(numSolutions == 2)
  {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", numerator1 / denominator);
    printf("Solution 2: %.2lf\n", numerator2 / denominator);
  }
  else
  {
    printf("There is one real solution: %.2lf\n", numerator1 / denominator);
  }

  return 0;

}
