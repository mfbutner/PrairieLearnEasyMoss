/*
This program intends to solve the quadratic functions that entered by the user
*/
#include <stdio.h>
#include <math.h>

//This function calculates the discriminant of a quadratic equation
//a, b, c are the three variables entered by the user
double checkQuad(double a, double b, double c){
  double temp; //a temperory variable in calculating the discriminant
  temp = pow(b, 2) - (4 * a * c);
  return temp;
}

int main(){
  double numA, numB, numC; // three variables that the user will enter
  double finalAnswer; //The solution of the quadratic equation
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &numA);
  printf("Please enter b: ");
  scanf("%lf", &numB);
  printf("Please enter c: ");
  scanf("%lf", &numC);
  double dis = checkQuad(numA, numB, numC); // The discriminant of the equation
  if(dis > 0){
    printf("There are 2 real solutions");
    finalAnswer = (0 - numB + sqrt(checkQuad(numA, numB, numC))) / (2 * numA);
    printf("\nSolution 1: %0.2lf", finalAnswer);
    finalAnswer = (0 - numB - sqrt(checkQuad(numA, numB, numC))) / (2 * numA);
    printf("\nSolution 2: %0.2lf", finalAnswer);
  }
  else if(dis == 0.0){
    finalAnswer = (0 - numB + sqrt(checkQuad(numA, numB, numC))) / (2 * numA);
    printf("There is one real solution: %0.2lf", finalAnswer);
  }else{
    printf("There are no real solutions");
  }

}
