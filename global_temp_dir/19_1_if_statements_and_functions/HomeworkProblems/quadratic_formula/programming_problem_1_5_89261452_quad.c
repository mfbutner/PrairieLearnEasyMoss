// This program uses the quadratic formula to give either one, two or no solutions.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// this function was created to help determine what solution to use a needed this many times so just made it into a function.
double calcToDetermineWhichSolution(double a, double b, double c){ // the name is really long and inconvenient however i wasn't sure how to say b^2 - 4ac lol
  double special = 0; // again didn't know how to say b^2 + 4ac as a name for variable so i did this cause it is special.
  special = pow(b, 2) - (4*a*c);
  return special;
}

void noSolution(){ // done lol
  printf("There are no real solutions\n"); // just needed to print no solutions
}
// there is only one solutions. the a and b are given by the user.
void oneSolution(double a, double b){
  double solution;
  solution = -b/(2*a); // since the b^2 - 4ac equals 0 therefor just solve the rest of the formula.
  printf("There is one real solution: %.2lf\n", solution); // prints the solution
}
// the special is the b^2 + 4ac, the a,b,c are from the user. 
void twoSolution(double special,double a, double b, double c ){
  double oneSolution;
  double secondSolution;
  // will need two solutions
  oneSolution = (-b + sqrt(special))/(2*a); // first solution remember the square roots and calculate it
  secondSolution = (-b - sqrt(special))/(2*a); // second same as above but minus instead of add.

  printf("There are 2 real solutions \n");
  printf("Solution 1: %.2lf\nSolution 2: %.2lf\n", oneSolution,secondSolution ); // print the 2 solutions

}
// there are three different ways answers that are possible
// so this will decide which solution and then also call which function
// if less than 0 aka it's negative so the square root will cause an error so no solution
// if equal to 0 then there is only one solution because no need to add and minus
// other wise there are two solution
void whichSolution(double special,double a, double b, double c ){
  if(special < 0) {
    noSolution();
  } else if(special == 0){
    oneSolution(a,b);
  } else {
    twoSolution(special,a, b, c );
  }
}
int main(void) {
  double a;
  double b;
  double c;
  double special;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a );
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);
  special = calcToDetermineWhichSolution(a, b, c);
  whichSolution(special,a,b,c);
  //printf("%.2lf\n",special); // used for testing
}
