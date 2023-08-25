#include <stdio.h>
#include <math.h>

double a;
double b;
double c;

int main() {
  printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);
  
  double squareB = pow(b, 2);
  if(4*a*c > squareB){
    printf("There are no real solutions");
    return 0;
    }
  double x1 = (-b + sqrt((squareB - 4*a*c))) / (2*a);
  double x2 = (-b - sqrt((squareB - 4*a*c))) / (2*a);
  if ((x1 != x2) && (x1 != 0) && (x2 != 0)){
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", x1);
    printf("Solution 2: %.2lf\n", x2);
    }
  else if ((x1 > 0) || (x1 < 0)) {
    printf("There is one real solution: %.2lf", x1);
  }
  else if (x2) {
      printf("There is one real solution: %.2lf", x2);
    }
  else{
    printf("There are no real solutions");
  }
  return 0;
}
  