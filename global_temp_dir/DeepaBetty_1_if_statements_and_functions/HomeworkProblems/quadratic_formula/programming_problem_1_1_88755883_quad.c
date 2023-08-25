// This program takes user input of three numbers, puts them into the variables a, b, and c, and then calculates the quadratic formula from this.
#include <stdio.h>
#include <math.h>



// Calculates discriminant
double discriminantCalculator(double a, double b, double c) {
    double discriminant;

    discriminant = (b*b - 4*a*c); // calculation under square root
    return discriminant;

}

// Calculates the quadratic formula when it is addition.
double quadraticFormulaAddition(double a, double b, double c) {
  double squareRoot = sqrt(b*b - 4*a*c);
  double solution = ((b*-1) + squareRoot)/(2*a);

  return solution;
}
// Calculates the quadratic formula for when it is subtraction
double quadraticFormulaSubtraction(double a, double b, double c) {
  double squareRoot = sqrt(b*b - 4*a*c);
  double solution = ((b*-1) - squareRoot)/(2*a);

  return solution;
}

// Asks user for their input.
int main(void) {
    double userA;  // User defined a
    double userB; // User defined b
    double userC; // User defined c

   printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");

   // Prompt user for a, b, and c
    printf("Please enter a: ");
    scanf("%lf", &userA);

    printf("Please enter b: ");
    scanf("%lf", &userB);

    printf("Please enter c: ");
    scanf("%lf", &userC);


// if statements that say how many real solutions & print solutions if any

   if (discriminantCalculator(userA, userB, userC) < 0) {
    printf("There are no real solutions");
  }

  else if (discriminantCalculator(userA, userB, userC) == 0) {
    printf("There is one real solution: %.2lf", quadraticFormulaAddition(userA, userB, userC));
  }

  else if (discriminantCalculator(userA, userB, userC) > 0) {
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", quadraticFormulaAddition(userA, userB, userC));
    printf("Solution 2: %.2lf", quadraticFormulaSubtraction(userA, userB, userC));

  }

   return 0;
}
