#include <stdio.h>
#include <math.h>
// This program will find the roots of the quadratic formula based on inputed values


// This is the function that will find the roots of the quadratic formula
// The parameters are the same as the double values made in main
/* num a, b, and c will present the numbers the user inputed for the quadratic
  formula. They will be used for an equation based on the value of the discriminate */
void find_roots(double num_a, double num_b, double num_c) {
  double discrim;
  double root_1;
  double root_2;

  // This code will find the discriminate of the quadratic formula based on input values
  //This will help determine the value of the roots
  discrim = (num_b * num_b) - (4.0 * num_a * num_c);

  /* This will print out one real solution to the quadratic formula if the
  discriminate is equal to 0 */
  if (discrim == 0) {
    root_1 = (-1.0 * num_b) / (2.0 * num_a); // equation to find 1 real root
    printf("There is one real solution: %.2lf", root_1);
  }
  else if (discrim > 0) { // Print out two real solutions if discriminate = 0
    // equations to find two real solutions
    // There are two because of the plus or minus part of the quadratic formula
    root_1 = ((num_b * -1.0) + sqrt((num_b * num_b) - (4.0 * num_a * num_c))) / (2.0 * num_a);
    root_2 = ((num_b * -1.0) - sqrt((num_b * num_b) - (4.0 * num_a * num_c))) / (2.0 * num_a);

    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", root_1);
    printf("Solution 2: %.2lf", root_2);
  }
  else { //This will iterate if the discriminate is less than or equal to 0
    printf("There are no real solutions");
  }
}


int main() {
  double num_a;
  double num_b;
  double num_c;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: \n");
  scanf("%lf", &num_a);

  printf("Please enter b: \n");
  scanf("%lf", &num_b);

  printf("Please enter c: \n");
  scanf("%lf", &num_c);

  find_roots(num_a, num_b, num_c); //Function call to find roots

  return 0;
}
