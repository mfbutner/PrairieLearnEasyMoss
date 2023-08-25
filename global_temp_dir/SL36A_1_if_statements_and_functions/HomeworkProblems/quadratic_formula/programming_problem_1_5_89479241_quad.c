/* Sonia Lin ECS 36A - quad.c
Calculates possible solutions to the quadratic equation based on user input
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// Calculates discriminant
double discrim(double a, double b, double c) {
  double discrim;
  discrim = pow(b, 2) - (4 * a * c);
  return discrim;
}
// Asks for user input and calculates possible solutions
int main() {
  double a;
  double b;
  double c;
  double solution0;
  double solution1;
  double solution2;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\nPlease enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);

  if (discrim(a,b,c) > 0){
    solution1 = (-b + sqrt(discrim(a,b,c))) / (2.0 * a);
    solution2 = (-b - sqrt(discrim(a,b,c))) / (2.0 * a);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\nSolution 2: %.2lf\n", solution1, solution2);
  }
  else if (discrim(a,b,c) == 0){
    solution0 = -b / (2.0 * a);
    printf("There is one real solution: %.2lf\n", solution0);
  }
  else {
    printf("There are no real solutions\n");
  }
}
