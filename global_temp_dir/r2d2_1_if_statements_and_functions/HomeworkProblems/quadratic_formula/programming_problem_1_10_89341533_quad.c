#include <stdio.h>
#include <math.h>
//This program is tasked to solving the quadratic formula (-b ± sqrt((b*b) - 4*a*c)) / (2*a). In order to solve this, we take a, b, and c as an input and insert them into the quadratic formula, returning the output.

//This first function finds the first answer of the quadratic formula, with -b + sqrt...
//The first fuction takes in 3 double values, which were the a, b, and c values that we took in as inputs in the main function. It has a parameter 'answerOne', which is a double value that returns the value from the quadratic formula with -b + sqrt...
double quadraticFormulaOne(double a, double b, double c) {
  double answerOne = (-b + sqrt((b*b) - 4*a*c)) / (2*a);
  //printf("%lf", answerOne);
  return answerOne;
}

//This second function finds the second answer of the quadratic formula, with -b - sqrt...
//The second fuction takes in 3 double values, which were the a, b, and c values that we took in as inputs in the main function. It has a parameter 'answerTwo', which is a double value that returns the value from the quadratic formula with -b - sqrt...
double quadraticFormulaTwo(double a, double b, double c) {
  double answerTwo = (-b - sqrt((b*b) - 4*a*c)) / (2*a);
  //printf("%lf", answerTwo);
  return answerTwo;
}

//This is our main function. It has double parameters a, b, and c, which takes in user inputs through scan functions. It then calls upon the quadraticFormulaOne and quadraticFormulaTwo functions, in order to get the two possible answers, which are stored in double parameters answer1 and answer2. If answer1 = answer2 then one real solution is printed. If there is no possible answer than that is stated as well.
int main(void) {
  double a;
  double b;
  double c;
  double answer1;
  double answer2;

  //These are the lines where the input is taken in.
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);

  printf("Please enter b: ");
  scanf("%lf", &b);

  printf("Please enter c: ");
  scanf("%lf", &c);

  answer1 = quadraticFormulaOne(a, b, c);
  answer2 = quadraticFormulaTwo(a, b, c);
  
  if (isnan(answer1) == 1 ) {
    printf("There are no real solutions");  
  }
  else if (answer1 == answer2) {
    printf("There is one real solution: %.2lf", answer1);
  }
  else if (answer1 != answer2) {
    if (answer1>0 && answer2>0 ) {
      if (answer1>answer2) {
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", answer2, answer1);
      }
      else {
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", answer1, answer2);
      }
    }
    else if (answer1 > answer2) {
      printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", answer1, answer2);
    }
    else if (answer2 > answer1) {
      printf("There are 2 solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", answer2, answer1);
    }
  }
  return 0;
}