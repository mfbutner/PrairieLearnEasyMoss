#include <stdio.h>
#include <math.h>

/*
This program will using the quadratic formula to solve for solutions of a
quadratic equation.
*/

double find_discriminant(double a_Num, double b_Num, double c_Num);
int find_num_solutions(double discriminant);

double find_discriminant(double a_Num, double b_Num, double c_Num) {
  /*
  Finds the discriminant based on the user's input
  @a: The value A entered by the user
  @b: The value B entered by the user
  @c: The value C entered by the user
  @returns: The value of the discriminant
  */
  double discriminant;
  discriminant = ((b_Num * b_Num) - 4 * a_Num * c_Num);
  return discriminant;
}

int find_num_solutions(double discriminant) {
  /*
  Finds the number of solutions
  @discriminant: the discriminant
  @returns: the number of solutions
  */
  int num_solutions;
  if (discriminant < 0) {
    num_solutions = 0;
  }
  else if (discriminant > 0) {
    num_solutions = 2;
  }
  else {
    num_solutions = 1;
  }
  return num_solutions;
}


int main() {
  /*
  main function where program is run
  @returns: nothing
  */
  double a_Num;
  double b_Num;
  double c_Num;
  double discriminant;
  double solution1;
  double solution2;
  int num_solutions;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: \n");
  scanf("%lf", &a_Num);
  printf("Please enter b: \n");
  scanf("%lf", &b_Num);
  printf("Please enter c: \n");
  scanf("%lf", &c_Num);

  discriminant = find_discriminant(a_Num, b_Num, c_Num);
  num_solutions = find_num_solutions(discriminant);
  solution1 = (-b_Num + sqrt(discriminant)) / (2 * a_Num);
  solution2 = (-b_Num - sqrt(discriminant)) / (2 * a_Num);

  if (num_solutions == 2) {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", solution1);
    printf("Solution 2: %.2lf\n", solution2);
  }
  else if (num_solutions == 1) {
    printf("There is one real solution: %.2lf\n", solution1);
  }
  else {
    printf("There are no real solutions\n");
  }

  return 0;
}
