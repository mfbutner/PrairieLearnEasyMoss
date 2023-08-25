#include <stdio.h>
#include <math.h>

// Program tells user the solution to their quadractic equation and tells them how many real solutions there are
int main(){
  double a;
  double b;
  double c;
  double first_solution;
  double second_solution;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);

  // condition to see if there is only one solution and outputs the one solution
  if (b * b == 4*a*c){
    first_solution = ((-b + sqrt(b*b - 4*a*c))/(2 * a));
    printf("There is one real solution: %.2lf", first_solution);
  }
  // condition to see if there are no real solutions
  else if (b*b - 4*a*c < 0){
    printf("There are no real solutions");
  }
  // condition to see if there are two real solutions and outputs the two real solutions
  else if (b*b - 4*a*c > 0){
    first_solution = ((-b + sqrt(b*b - 4*a*c))/(2 * a));
    second_solution = ((-b - sqrt(b*b - 4*a*c))/(2 * a));
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", first_solution);
    printf("Solution 2: %.2lf\n", second_solution);
  }

}
