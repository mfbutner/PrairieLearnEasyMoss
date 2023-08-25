// Program that computes the real roots of a quadratic eqaution
#include <stdio.h>
#include <math.h> // needed for pow and sqrt functions




double quadCalculateMinus(double quadA, double quadB, double quadC) { //  Function that computes b^2 - sqrt(b^2 + 4ac) / 2a
  double calcRoot = (-quadB - sqrt(pow(quadB, 2) - (4 * quadA * quadC))) / (2 * quadA); // actual calculation
  return calcRoot; // returns a root of the function or -nan (maybe infinity on occasion? unsure)
}


double quadCalculatePlus(double quadA, double quadB, double quadC) { // Function that computes b^2 + sqrt(b^2 + 4ac) / 2a
  double calcRoot = (-quadB + sqrt(pow(quadB, 2) - (4 * quadA * quadC))) / (2 * quadA); // actual calculation
  return calcRoot; // returns a root of the function or -nan (maybe infinity on occasion? unsure)
}

int main(void) { // main function asks for user input, calls other functions to compute roots, determines if the roots are real or not, then finally prints!

  double quadA, quadB, quadC; // Initialize the variables that correspond to A, B, and C in the quadratic formula
  double minusRoot, plusRoot; // Initialize the variables that will store the computed roots

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); // following lines get user input
  printf("Please enter a: ");
  scanf("%lf", &quadA);
  printf("Please enter b: ");
  scanf("%lf", &quadB);
  printf("Please enter c: ");
  scanf("%lf", &quadC);

  minusRoot = quadCalculateMinus(quadA, quadB, quadC); // call function to compute first root
  plusRoot = quadCalculatePlus(quadA, quadB, quadC); // cal function to compute second root

  if (!(isnormal(minusRoot) && isnormal(plusRoot))) { // if both functions return non double values this condition is executed (no real solutions)
    printf("There are no real solutions\n");
  }

  else if ((!(isnormal(minusRoot)) || minusRoot == plusRoot)) { // if the minusRoot function returns a non double value only the plusRoot function gets printed
    printf("There is one real solution: %.2lf\n", plusRoot);
  }

  else if (!(isnormal(plusRoot))) { // if the plusRoot function returns a non double value only the minusRoot function gets printed
    printf("There is one real solution: %.2lf\n", minusRoot);
  }

  else { // if none of the above conditions are executed it means there are two real roots & both get printed
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", plusRoot);
    printf("Solution 2: %.2lf\n", minusRoot);
  }



}
