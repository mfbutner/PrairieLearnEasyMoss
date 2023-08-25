#include <stdio.h>
#include <math.h>

//Program that find the roots for a quadratic equation given inputs a, b, and c


/* This function determines how many solutions are possible for the quadratic equation.
Parameters a, b, and c are received from the user input to determine the value of (b^2 - 4ac).
Returns 0 for no solutions, 1 for one solution, and 2 for two solutions*/
double numberOfSolutions(double a, double b, double c){
   double term2 = (pow(b,2)) - (4 * a * c);
   if (term2 < 0){
      return 0;
}
    else if (term2 == 0){
      return 1;
}
    else if (term2 > 0){
    return 2;
   }
   else return 0;
}

/*This function evaluates the quadratic equation for each of the possible number of solutions.
Parameters a, b, and c are received from user input to evaluate the quadratic equation.
Prints out the number of solutions along with the value of the root(s) and returns 0*/
double evaluateQuadraticEquation(double a, double b, double c){
   if (numberOfSolutions(a, b, c) == 0){
      printf("There are no real solutions\n");
   }
   if (numberOfSolutions(a, b, c) == 1){
      double singleRoot = (-b / (2 * a));
      printf("There is one real solution: %.2lf\n", singleRoot);
}
   if (numberOfSolutions(a, b, c) == 2){
      double root1 = (-b + sqrt((pow(b,2) - (4 * a * c)))) / (2 * a);
      double root2 = (-b - sqrt((pow(b,2) - (4 * a * c)))) / (2 * a);
      printf("There are 2 real solutions \n");
      printf("Solution 1: %.2lf\n", root1);
      printf("Solution 2: %.2lf\n", root2);
}
return 0;

}


/*This function gets the input from the user and calls the other functions
The values of a, b, and c are determined to be used by other functions
Returns 0 */

int main(){
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
double a, b, c;
printf("Please enter a: ");
scanf(" %lf", &a);
printf("Please enter b: ");
scanf(" %lf", &b);
printf("Please enter c: ");
scanf(" %lf", &c);
evaluateQuadraticEquation(a, b, c);
return 0;
}