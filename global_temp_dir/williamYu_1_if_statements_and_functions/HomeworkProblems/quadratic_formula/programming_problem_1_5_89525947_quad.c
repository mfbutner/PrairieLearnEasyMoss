#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
This program calculates the quadratic equation given the three corresponding
variables a, b, and c from ax^2 + bx + c.  It also tells you how many real
solutions there are from the inputted values.
*/

double calcDiscriminant (double aVariable, double bVariable, double cVariable){
  double discriminant;

  discriminant = (pow(bVariable, 2)) - (4 * aVariable * cVariable);

  return discriminant;
}
/*
The funtion above calculates the discriminant (b^2 - 4ac) of the quadratic equation.
The parameters are the users inputs for the a, b, and c variables as they are necessary
to calculate the discriminant.
The function returns the discriminant.
*/

double calcSolution1 (double aVariable, double bVariable, double cVariable){
  double solution1;

  solution1 = ((-bVariable) + pow(calcDiscriminant(aVariable, bVariable, cVariable), (.5)))/(2 * aVariable);

  return solution1;
}

/*
The function above calculates one part of the quadratic equation.  In the equation, you add
or subtract the square root of the discriminant and this function completes the adding
part.
The parameters are the users inputs for the a, b, and c variables as they are necessary
to calculate the equation.
The function returns one solution (the solution that adds) of the equation.
*/

double calcSolution2 (double aVariable, double bVariable, double cVariable){
  double solution2;

  solution2 = ((-bVariable) - pow(calcDiscriminant (aVariable, bVariable, cVariable), .5))/(2 * aVariable);

return solution2;
}

/*
The function above calculates one part of the quadratic equation.  In the equation, you add
or subtract the square root of the discriminant and this function completes the subtracting
part.
The parameters are the users inputs for the a, b, and c variables as they are necessary
to calculate the equation.
The function returns one solution (the solution that subtracts) of the equation.
*/

int main(){

  double aVariable, bVariable, cVariable;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

  printf("Please enter a: ");
  scanf(" %lf", &aVariable);
  printf("\nPlease enter b: ");
  scanf(" %lf", &bVariable);
  printf("\nPlease enter c: ");
  scanf(" %lf", &cVariable);

if (calcDiscriminant (aVariable, bVariable, cVariable) > 0){
  printf("\nThere are 2 real solutions\n");
  printf("\nSolution 1: %.2lf\n", calcSolution1(aVariable, bVariable, cVariable));
  printf("\nSolution 2: %.2lf\n", calcSolution2(aVariable, bVariable, cVariable));
}
else if (calcDiscriminant (aVariable, bVariable, cVariable) == 0) {
  printf("\nThere is one real solution: %.2lf\n", calcSolution1(aVariable, bVariable, cVariable));
}
else {
  printf("\nThere are no real solutions\n");
}

return 0;
}
