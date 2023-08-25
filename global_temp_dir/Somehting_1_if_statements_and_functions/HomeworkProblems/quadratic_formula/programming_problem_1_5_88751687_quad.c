#include <stdio.h>
#include <math.h>

/*
This program takes in the user input and calculates the quadratic formula with the user input.
*/

double solve_positive_numerator(double a, double b, double c) {
  /*
  This function solves the numerator of the positive quadratic formula.
  @numerator is assign with the positive numerator of the quadratic formula.
  @return the final value of the positive numerator of the quadratic forumla after the calculations.
  */

  double numerator = -b + sqrt(pow(b, 2) - (4 * a * c));
  return numerator;
}

double solve_negative_numerator(double a, double b, double c) {
  /*
  This function solves the numerator of the negative quadratic formula.
  @numerator is assign with the negative numerator of the quadratic formula.
  @return the final value of the negative numerator of the quadratic forumla after the calculations.
  */

  double numerator = -b - sqrt(pow(b, 2) - (4 * a * c));
  return numerator;
}

double solve_denominator(double a) {
  /*
  This function solves the numerator of the quadratic formula.
  @denominator is assign with the integer 2 multiplied by the value of a.
  @return the final value of 2 * a.
  */

  double denominator = 2 * a;
  return denominator;
}

double solve_positive_quadratic_formula(double a, double b, double c) {
  /*
  This function solves the positive quadratic formula.
  @numerator is assign with the numerator portion of the quadratic formula.
  @denominator is assign with the denominator portion of the quadratic formula.
  @positive_quadratic is assign with the numerator being divided by the denominator.
  @return the final value of the numerator divided by the denominator.
  */

  double numerator = solve_positive_numerator(a, b, c);
  double denominator = solve_denominator(a);
  double positive_quadratic = numerator / denominator;

  return positive_quadratic;
}

double solve_negative_quadratic_formula(double a, double b, double c) {
  /*
  This function solves the negative quadratic formula.
  @numerator is assign with the numerator portion of the quadratic formula.
  @denominator is assign with the denominator portion of the quadratic formula.
  @negative_quadratic is assign with the numerator being divided by the denominator.
  @return the final value of the numerator divided by the denominator.
  */

  double numerator = solve_negative_numerator(a, b, c);
  double denominator = solve_denominator(a);
  double negative_quadratic = numerator / denominator;

  return negative_quadratic;
}

void display_num_of_real_solutions(double a, double b, double c) {
  /*
  This function prints out the number of solutions that are present in the quadratic forumla.
  @solution_to_positive_quadratic is assigned with the final value of the positive quadratic formula.
  @solution_to_negative_quadratic is assigned with the final value of the negative quadratic formula.
  */

  double solution_to_positive_quadratic = solve_positive_quadratic_formula(a, b, c);
  double solution_to_negative_quadratic = solve_negative_quadratic_formula(a, b, c);

  if (solution_to_negative_quadratic == solution_to_positive_quadratic) {
    printf("There is one real solution: %.2lf", solution_to_positive_quadratic);
  } else if ((isnan(solution_to_negative_quadratic)) && (isnan(solution_to_positive_quadratic))) {
    printf("There are no real solutions");
  } else if (solution_to_negative_quadratic != solution_to_positive_quadratic) {
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n", solution_to_positive_quadratic);
      printf("Solution 2: %.2lf", solution_to_negative_quadratic);
  }
}

int main() {
  /*
  This is the main function of the program.
  @a is assigned with the user input.
  @b is assigned with the user input.
  @c is assigned with the user input.
  */

  double a;
  double b;
  double c;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);

  display_num_of_real_solutions(a, b, c);

  return 0;
}
