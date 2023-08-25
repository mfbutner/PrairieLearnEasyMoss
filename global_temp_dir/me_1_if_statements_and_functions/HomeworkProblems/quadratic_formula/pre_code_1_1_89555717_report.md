# My Algorithm (steps to solve the problem)
#include <stdio.h>
#include <math.h>
double calculation(double a, double b, double c);

int main(void) {

	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

	double a;
    double b;
    double c;

	printf("Please enter a : ");
	scanf("%lf", &a);
	printf("Please enter b : ");
	scanf("%lf", &b);
	printf("Please enter c : ");
	scanf("%lf", &c);

	double root = calculation(a, b, c);
	
	if(root < 0) {
		printf("There are no real solutions\n");

	} else if(root > 0) {
		double froot = (-b + sqrt(root))/(2*a); 
		double sroot = (-b - sqrt(root))/(2*a);
		printf("There are 2 real solutions\n");
		printf("Solution 1 : %.2f\n", froot);
		printf("Solution 2 : %.2f\n", sroot);

	} else {
		double root = -b/(2*a);
		printf("There is one real solution : %.2f\n", root);

	}
	
	return 0;
}


double calculation(double a, double b, double c) {
	return b*b -4*a*c;
}