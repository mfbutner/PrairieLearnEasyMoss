#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
Given the coefficients of the first term, second term, and the value of the third term of a
quadratic formula, this program will compute the real solutions to it if there are any.
*/

bool check_if_there_are_real_solutions(double a, double b, double c);
bool check_if_inside_sqrt_is_neg(double a, double b, double c);
double get_positive_solution_of_quad_formula(double a, double b, double c);
double get_negative_solution_of_quad_formula(double a, double b, double c);

int main()
{
  /*
  this is the main function
  it will print out the real solutions of the given quadratic equation if there are any
  @return: 0
  */
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

  double a;
  double b;
  double c;

  printf("Please enter a: ");
  scanf(" %lf", &a);

  printf("Please enter b: ");
  scanf(" %lf", &b);

  printf("Please enter c: ");
  scanf(" %lf", &c);

  bool there_are_real_solutions;
  there_are_real_solutions = check_if_there_are_real_solutions(a, b, c);

  if (there_are_real_solutions){
    double ans1;
    double ans2;
    ans1 = get_positive_solution_of_quad_formula(a, b, c);
    ans2 = get_negative_solution_of_quad_formula(a, b, c);
    if (ans1 == ans2){
      printf("There is one real solution: %.2lf", ans1);
    }
    else if (ans1 != ans2){
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n", ans1);
      printf("Solution 2: %.2lf", ans2);
    }
  }else{
    printf("There are no real solutions");
  }

  return 0;
}

bool check_if_there_are_real_solutions(double a, double b, double c){
  /*
  this function checks if there are real solutions to the given quadratic equation
  @param a: the coefficient of the first term of the quadratic equation
  @param b: the coefficient of the second term of the quadratic equation
  @param c: the value of the third term
  @return: a bool that checks if there are real solutions or not
  */
  bool inside_of_srqt_is_neg;
  inside_of_srqt_is_neg = check_if_inside_sqrt_is_neg(a, b, c);
  return !inside_of_srqt_is_neg;
}

bool check_if_inside_sqrt_is_neg(double a, double b, double c){
  /*
  checks to see if the inside of the sqrt part of the quadratic formula is negative or not
  @param a: the coefficient of the first term of the quadratic equation
  @param b: the coefficient of the second term of the quadratic equation
  @param c: the value of the third term
  @return: a bool that checks if the inside of the sqrt part of the quadratic formula is negative or not
  */
  double result_of_inside_of_sqrt;
  result_of_inside_of_sqrt = (b * b) - (4 * a * c);
  return result_of_inside_of_sqrt < 0;
}

double get_positive_solution_of_quad_formula(double a, double b, double c){
  /*
  gets the positive solution of the quadratic equation:
  (-b + sqrt(b^2 - 4ac)) / (2a)
  @param a: the coefficient of the first term of the quadratic equation
  @param b: the coefficient of the second term of the quadratic equation
  @param c: the value of the third term
  @return: the positive solution of the quadratic equation
  */
  double ans1;
  ans1 = ((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
  return ans1;
}

double get_negative_solution_of_quad_formula(double a, double b, double c){
  /*
  gets the negative solution of the quadratic equation:
  (-b - sqrt(b^2 - 4ac)) / (2a)
  @param a: the coefficient of the first term of the quadratic equation
  @param b: the coefficient of the second term of the quadratic equation
  @param c: the value of the third term
  @return: the negative solution of the quadratic equation
  */
  double ans2;
  ans2 = ((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));
  return ans2;
}