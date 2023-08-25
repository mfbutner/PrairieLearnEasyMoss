#include <stdio.h>
#include <math.h>



// (Function DECLARATION)
double quadratic_equation(double a, double b, double c);


int main(void) {
  double a;
  double b;
  double c;

  // Prompt for giving the format of quadratic equation
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");


 // Prompt user for deciding the formula
  printf("Please enter a: ");
  scanf(" %lf", &a);
  printf("Please enter b: ");
  scanf(" %lf", &b);
  printf("Please enter c: ");
  scanf(" %lf", &c);

  quadratic_equation(a, b, c);

   return 0;
}


// (Function DEFINITION)
double quadratic_equation(double a, double b, double c){
  double discriminant; /*
                        There are three possible output for solving quadratic equation.
                        two real solutions; if discriminant > 0
                        one real solution, if discriminant == 0
                        and two non-real solutions. if iscriminant < 0
                        all of them depends on the value of b^2 - 4ac which is called discriminant.
                        */

  double x1;
  double x2;
  double x;
  discriminant = pow(b,2) - 4 * a * c;



  if (discriminant > 0){
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", x1);
    printf("Solution 2: %.2lf\n", x2);
  }

  else if (discriminant == 0){
    x = -b / (2 * a);
    printf("There is one real solution: %.2lf\n", x);

  }

  // we do not accpet non-real solutions which is discriminant < 0
  else{
    printf("There are no real solutions\n");
  }
  return 0;

}
