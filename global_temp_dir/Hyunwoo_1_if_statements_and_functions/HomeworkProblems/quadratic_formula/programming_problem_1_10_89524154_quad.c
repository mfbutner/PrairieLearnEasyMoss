#include <stdio.h>
#include <math.h>

int main() {

//ask for input
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
double a;
double b;
double c;
printf("Please enter a: ");
scanf("%lf", &a);
printf("Please enter b: ");
scanf("%lf", &b);
printf("Please enter c: ");
scanf("%lf", &c);

//number of solution exists
int numOfSol;

//find number of outputs
if (a == 0 || (b * b - 4 * a * c < 0)) {
//no solution
printf("There are no real solutions");
numOfSol = 0;
} else if (b * b - 4 * a * c > 0) {
//two solutions
printf("There are 2 real solutions");
numOfSol = 2;
} else {
//one solution
printf("There is one real solution: ");
numOfSol = 1;
}

//run quadratic formula
if (numOfSol == 1) {
double output = -b / (2 * a);
printf("%.2lf", output);
} else if (numOfSol == 2){
double output = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
printf("Solution 1: %.2lf", output);
output = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
printf("Solution 2: %.2lf", output);
}

}