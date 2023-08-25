#include <stdio.h>
#include <math.h>
// calculates the roots of a quadratic equation using the quadratic formula

double abc(double a, double b, double c) {
  return sqrt(pow(b,2) - (4 * a * c));
// this function just calculates inside the square root of the quadratic formula
}

int main(void) {
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  double a, b, c;
  
  printf("Please enter a: ");
  scanf("%lf", &a);

  printf("Please enter b: ");
  scanf("%lf", &b);

  printf("Please enter c: ");
  scanf("%lf", &c);

  if(pow(b,2) - (4 * a * c) >= 0) {
    double squareRoot = abc(a,b,c);
    double sol1 = ((-b) + squareRoot) / (2 * a);
    double sol2 = ((-b) - squareRoot) / (2 * a);
    if(sol1 == sol2) {
      printf("There is one real solution: %.2lf", sol1);
    }
    else {
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n", sol1);
      printf("Solution 2: %.2lf\n", sol2);
    }
    }
  else {
    printf("There are no real solutions");
  }  
  
  return 0;
}