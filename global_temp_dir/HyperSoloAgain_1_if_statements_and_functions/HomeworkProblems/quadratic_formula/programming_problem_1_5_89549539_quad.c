/*The user inputs the coefficients of the quadratic equation. These values are
used to determine whether or not solution(s) exist as the quadratic formula
would return an imaginary answer if the function never intercepts the x axis.
If the result yields a real number answer, the quadratic equation in full is
called twice, once for a positive square root value and once for a negative
square root value. If both results are the same, only one solution exist, but
different results implies that there are two solutions*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*The Solutions Available function is used to determine whether the component
inside of the square root is positive or zero. It is possible to receive a real
value under these conditions and thus the process can continue. However, if the
value inside of the square root is negative, we would have an imaginary answer.
Therefore, the program would immediately return that there are no real answers*/
bool SolutionsAvailable(double a, double b, double c) {
  /*The function takes the three coefficients of the quadratic equation
  in order to make the appropriate calculations*/
  double InsideSquareRoot;

  InsideSquareRoot = pow(b, 2) - 4*a*c;
  /*After determining if there will be a real answer from taking the squareroot,
  the function yields a true bool condition in order for the appropriate steps
  to be taken to find the solutions. If the answer will be imaginary, a false
  boolean condition is applied to signal to the main function to skip direct to
  the display results command that no real solutions exist*/
  if (InsideSquareRoot >= 0) {
    return true;
  }
  else {
    return false;
  }
}

/*The Quadratic Equation does the math required to calculate the solution(s) for
the coefficient, generating a positive and negative value for the square root*/
double QuadraticEquation(double a, double b, double c, bool PlusOrMinus) {
  /*The function takes the three coefficients of the quadratic equation
  in order to make the appropriate calculations. Additionally, a boolean
  condition parameter is used to indicate whether the square root term should
  yield a positive result or a negative one. */
  double answer;

  if (PlusOrMinus) {
    answer = ( -b + sqrt(pow(b, 2) - 4*a*c) )/(2*a);
  }
  else {
    answer = ( -b - sqrt(pow(b, 2) - 4*a*c) )/(2*a);
  }
  //The calculations based on the quadratic equation is returned
  return answer;
}

/*Main function reads user inputs, calculates term under square root to decide
whether or not solution(s) exist, then calculates the quadratic equation in full
to determine whether one or two solutions exist*/
int main(void) {
  double aCoeff;
  double bCoeff;
  double cCoeff;
  double Solution1;
  double Solution2;
  bool NumSolution;
  //Requests for user input
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &aCoeff);
  printf("Please enter b: ");
  scanf("%lf", &bCoeff);
  printf("Please enter c: ");
  scanf("%lf", &cCoeff);
  //Determines how many solutions are in the quadratic equation
  NumSolution = SolutionsAvailable(aCoeff, bCoeff, cCoeff);
  //If square root does not return an imaginary value, find solution(s)
  if (NumSolution) {
    Solution1 = QuadraticEquation(aCoeff, bCoeff, cCoeff, true);
    Solution2 = QuadraticEquation(aCoeff, bCoeff, cCoeff, false);
    //If plus or minus sign does not matter, there's only one solution
    if (Solution1 == Solution2) {
      printf("There is one real solution: %.2lf", Solution1);
    }
    else {
      printf("There are 2 real solutions");
      printf("\nSolution 1: %.2lf", Solution1);
      printf("\nSolution 2: %.2lf", Solution2);
    }
  }
  else {
    printf("There are no real solutions");
  }

  return 0;
}
