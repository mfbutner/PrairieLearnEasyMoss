// This code is used for find the real values of x in quadratic equation (ax^2 + bx + c) by using the roots of quadratic equation
#include <stdio.h>
#include <string.h>
#include <math.h>

double findvaluex(double a,double b,double c){ //This function is used for determine the real values of x
	// the parameters for this function mean the values that get from the user
	double real1;
	real1 = pow(b,2)-4*a*c;
	return real1; //This function return a key value to determine the real values of x
}

int main(void){
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	printf("Please enter b: ");
	printf("Please enter c: ");
	double A;
	double B;
	double C;
	scanf("%lf",&A);
	scanf("%lf",&B);
	scanf("%lf",&C);
	double x1;
	double x2;
	x1 = (-B+sqrt(pow(B,2)-4*A*C))/(2*A);
	x2 = (-B-sqrt(pow(B,2)-4*A*C))/(2*A);
	if (findvaluex(A,B,C) > 0){
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n",x1);
		printf("Solution 2: %.2lf\n",x2);
	}
	else if (findvaluex(A,B,C) == 0){
		printf("There is one real solution: %.2lf\n",x1);
	}
	else{
		printf("There are no real solutions");
	}
	return 0;
}