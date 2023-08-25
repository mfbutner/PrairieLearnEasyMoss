#include <stdio.h>
#include <math.h>

/*This program will calculate the roots of a polynomial when asking the user for the coefficients of the terms*/ 

/*This calculation function will be solely to calculate the roots with all the math functions*/
void calculation (double a , double b ,double c) {
  double root1;
  double root2;
  root1 = (-1 * b);
 // printf("%lf",x1);
  root1 = root1 + sqrt((b * b) - (4 * a * c));
  root1 = root1 / (2 * a);
  //printf("%lf",x1);
  root2 = (-1 * b);
 // printf("%lf",x1);
  root2 = root2 - sqrt((b * b) - (4 * a * c));
  root2 = root2 / (2 * a);
  
  //x2 = (-1 * b - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
  if (root1 == root2) {
    printf("There is one real solution: %.2lf", root1);
  }
  else {
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf",root1, root2);
  }
  
  //printf("%lf",x2);

  //return (x1);
} 

/*This is the main function which prompts the user for the values of the coefficients of the polynomial and then it determines the discrminant of the polynomial to determine the number of solutions there are. It then takes values a, b and c to calculation function*/
int main(void) {

  double a;
  double b;
  double c;
  double discrim;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c); 

  discrim = ((b*b) - (4 * a * c));
  
  if (discrim >= 0) {
    calculation(a, b, c);
  }
  else {
    printf("There are no real solutions");
  
  //printf("%lf", x1);
  
}
  return 0;
  }




