# include <stdio.h>
# include <math.h>

/*
    Asks the user for the values of a, b, and c in a
    standard quadratic formula and prints the number of
    solutions and the value of those solutions.
*/

// Create a void function that prints the first solution of a quadratic function (If there is one)
void firstSolution(double a, double b, double c) {
  double root1;
  double discriminant = (pow(b, 2.0) - (4.0)*(a)*(c));

  root1 = (-b + sqrt(discriminant)) / ((2)*(a));
  printf("%.2lf\n", root1);
}

// Create a second void function that prints the second solution of a quadratic function (If there are two)
void secondSolution(double a, double b, double c) {
  double root2;
  double discriminant = (pow(b, 2.0) - (4.0)*(a)*(c));

  root2 = (-b - sqrt(discriminant)) / ((2)*(a));
  printf("%.2lf\n", root2);
}

// Create a void function that prints all the real solutions of a quadratic function
void quadraticFormula(double a, double b, double c) {
  double discriminant = (pow(b, 2.0) - (4.0)*(a)*(c));

  if (discriminant > 0) {
    printf("There are 2 real solutions\n");
    printf("Solution 1: ");
    firstSolution(a, b, c);
    printf("Solution 2: ");
    secondSolution(a, b, c);
  }
  else if (discriminant == 0) {
    printf("There is one real solution: ");
    firstSolution(a, b, c);
  }
  else {
    printf("There are no real solutions");
  }
}

// Main Function
int main(void) {
  double a, b, c;

// Take input in the standard quadratic form from the user
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);

// Call the function that computes all the calculations and prints it
  quadraticFormula(a, b, c);

  return 0;
}
