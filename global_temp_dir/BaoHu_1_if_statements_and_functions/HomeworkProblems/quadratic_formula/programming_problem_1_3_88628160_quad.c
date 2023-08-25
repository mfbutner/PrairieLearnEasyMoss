#include <stdio.h>
#include <math.h>
/* this program collects 3 numbers which are the coefficients of a quadratic equation from the user.
 * then it calculates the solution(s) and shows user the solution(s).
*/

double formAdd (double a, double b, double c);
double formSub (double a, double b, double c);

int main() {
  // Complete the equation.
  double a = 7777;
  double b = 6666;
  double c = 5555;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("\nPlease enter a: ");
  scanf("%lf", &a);
  printf("\nPlease enter b: ");
  scanf("%lf", &b);
  printf("\nPlease enter c: ");
  scanf("%lf", &c);


  // ##Calculation
  // Determine how many solutions we have.
  double deterNum = pow(b, 2) - 4 * a * c;

  // Perform the formula.
  if (deterNum < 0){
    printf("\nThere are no real solutions");
    return 0;
  }else if (deterNum == 0){
    printf("\nThere is one real solution: %0.2f", formAdd(a, b, c));
    return 0;
  }else {
    printf("\nThere are 2 real solutions\n");
    printf("\nSolution 1: %0.2f\n", formAdd(a, b, c));
    printf("\nSolution 2: %0.2f\n", formSub(a, b, c));
  }

  return 0;
}

double formAdd (double a, double b, double c){
  /* This functions contains the quadratic formula.
    It collects the coefficients and gives the first (adding) result if applicable */
  double solution = (-b + pow(pow(b, 2) - 4 * a * c, 0.5))/ (2 * a);
  return solution;
}

double formSub (double a, double b, double c){
  /* This functions contains the quadratic formula.
    It collects the coefficients and gives the second (subtracting) result if applicable */
  double solution = (-b - pow(pow(b, 2) - 4 * a * c, 0.5))/ (2 * a);
  return solution;
}

