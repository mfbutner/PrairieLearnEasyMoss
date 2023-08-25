#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calculate(double a, double b, double c, int sign);
int main(){
    //declarations of variables, need 2 for answers and 3 for each a, b, and c and inputs
    double a = 0;
	double b = 0;
	double c = 0;
	double answer = 0;
	double answer2 = 0;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);
    printf("Please enter b: ");
	scanf("%lf", &b);
    printf("Please enter c: ");
	scanf("%lf", &c);
//call to calculate() function and various prints depending on the answer
    answer = calculate(a, b, c, 1);
    answer2 = calculate(a, b, c, -1);
    if(answer == 0) printf("There are no real solutions\n");
    else if (fabs(answer - answer2) < .000001) printf("There is one real solution: %.2lf\n", answer);
    else printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2:%.2lf\n", answer, answer2);
}
//takes a, b, and c and checks for no solution before solving for the solution
double calculate(double a, double b, double c, int sign){
    if(pow(b,2) - 4 * a * c < 0){
        return 0;
    } 
    return (-b + sign * pow(pow(b,2) - 4 * a * c, .5)) / (2 * a);
}
