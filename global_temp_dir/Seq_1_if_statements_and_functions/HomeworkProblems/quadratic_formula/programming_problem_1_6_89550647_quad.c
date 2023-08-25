/*
Calculates whether there are any real soltuions to a quadratic formula
and what those solutions are if there are any.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
This fuction determines whether there are any soltuions because if the
part inside the square root, the discriminate, is negative,
there are no real soltions. Its parameters are the respective a,b, and c
values of the quadratic equation format: a*x^2 + b * x + c.
*/
bool check_for_soltuions(double a, double b, double c) {
  bool anySolutions = pow(b, 2) >= (4 * a * c);
  return anySolutions;
}

/*
This function uses the quadratic formula to determine the solution(s). Its
parameters are the respective a, b, and c values of the quadratic equation
format: a*x^2 + b * x + c. It first evaluates wether the function has one or two
soltuions and then solves the problem accordingly. The if statement solves for
only one soltuion, because if the discriminate is equal to zero, there is only
one possible solution. The else statement solves for both solutions, because it
is the case where the discriminate is greater than zero and there are two
possible solutions. The check_for_solutions function prevents any case where
the discriminate is less than 0. The function is a void function
because I found it easier and more intuitive to output print statements when
dealing with the else outcome, then to return multiple values
to the main function.
*/
void solve_quadratic(double a, double b, double c) {
  double squareRootValue = sqrt(pow(b, 2) -(4 * a * c));
  double denominatorValue = 2 * a;

  if(squareRootValue == 0) {
    double quadraticSolution = -b / denominatorValue;
    printf("There is one real solution: %.2lf", quadraticSolution);
  }
  else {
    double numeratorValue1 = -b + squareRootValue;
    double quadraticSolution1 = numeratorValue1 / denominatorValue;

    double numeratorValue2 = -b - squareRootValue;
    double quadraticSolution2 = numeratorValue2 / denominatorValue;

    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", quadraticSolution1);
    printf("Solution 2: %.2lf\n", quadraticSolution2);
  }
}

/*
The main function asks the user for the respective inputs of a, b, and c of a
quadratic equation, and calls the function check_for_soltuions to see if there
are any soltuions. If there are any soltutions it calls on solve_quadratic to
find all real solutions. Otherwise, it outputs that there are not any soltuions.
*/
int main() {

  double numA;
  double numB;
  double numC;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf(" %lf", &numA);
  printf("Please enter b: ");
  scanf(" %lf", &numB);
  printf("Please enter c: ");
  scanf(" %lf", &numC);

  bool anySolutions = check_for_soltuions(numA, numB, numC);

  if(anySolutions == true) {
    solve_quadratic(numA, numB, numC);
  }
  else {
    printf("There are no real solutions");
  }
  return 0;
}
