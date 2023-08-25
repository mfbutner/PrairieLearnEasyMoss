
/* Quadratic formula solver */
/* Kenny Tang and Wutaru Ishihara */
/* Takes 3 inputs for constants in a quadratic equations and determines the solutions */


#include <math.h>
#include <stdio.h>


double findDiscriminant(double origA,double origB,double origC) {     // This determines the discriminant then returns the outcome
   return (origB*origB)-(4*origC*origA);
}




int main(void) {        // Gets user inputs and compute solutions
   double userA;
   double userB;
   double userC;
   double quadSolution;
   printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");
  
   printf("Please enter a: ");
   scanf("%lf", &userA);
  
   printf("Please enter b: ");
   scanf("%lf", &userB);


   printf("Please enter c: ");
   scanf("%lf", &userC);
  
   quadSolution = findDiscriminant(userA, userB, userC);
       if (quadSolution > 0) {      // Checks if discriminant is > 0 then solves equation
       double firstX = ( -userB + sqrt(userB * userB - (4 * userC * userA)) ) / (userA * 2);
       double secondX = ( -userB - sqrt(userB * userB - (4 * userC * userA)) ) / (userA * 2);
       printf("There are 2 real solutions \n");
       printf("Solution 1: %.2lf\n", firstX);
       printf("Solution 2: %.2lf\n", secondX);
   } 
  
   else if (quadSolution == 0) {        // Checks if discriminant is = 0 then solves equation
       double firstX = (-userB / (userA * 2));
       printf("There is one real solution: %.2lf", firstX);
   }


   else if (quadSolution < 0) {     // Checks if discriminant is < 0 then determines if there is a solution
       printf("There are no real solutions");
   }
  
   return 0;
  
}
