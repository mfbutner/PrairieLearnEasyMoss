#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//program will ask user for values for the quadratic formual and solve it

/*

function will solve solve for whats under the radical
each parameter is the coeffiencet that the user enters in the form a,b,c
the function returns the square root of whats under the radical

*/
double under_radical(const double num1, const double num2, const double num3);
double answer;
double under_radical(double num1, double num2, double num3){
answer = (num2 * num2) - (4 * (num1 * num3));
if (answer < 0){
    return -1;
}
else{
    return sqrt(answer);
}

}




int main(){

//variables for the quadratic formula
double a,b,c;


printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf("%lf",&a);
printf("Please enter b: ");
scanf("%lf", &b);
printf("Please enter c: ");
scanf("%lf", &c);
double possibleSolution = under_radical(a,b,c);
double firstSolution = (-b + possibleSolution) / (2 * a);
double secondSolution = (-b - possibleSolution) / (2 * a);

if (possibleSolution < 0 ){
    printf("There are no real solutions");
}
else if (firstSolution == secondSolution){
    printf("There is one real solution: %.2lf", firstSolution);
}else{
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf",  firstSolution, secondSolution);
}

return 0;
}








