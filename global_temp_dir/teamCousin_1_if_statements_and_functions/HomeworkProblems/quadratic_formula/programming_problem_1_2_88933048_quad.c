#include <stdio.h>
#include <math.h>

// user inputs values for the quadratic equation, then we use that information to calculate the solutions using the quadratic formula. it can have 0, 1, or 2 solutions. we used a function to calculate this.


// The function quadraticFormula uses the inputted values of a, b, and c from the main function that are sent as a copy to this function to solve for the discriminant, and determine if the solution will have zero, one, or two solutions. Depending on which one the discriminant results to, it will use the equations below to determine and print the solution(s). it will return 0.
double quadraticFormula(double a, double b, double c) {
	double discriminant;
	double posX;
	double negX;

	discriminant = (b*b)-(4*a*c);
	if (discriminant < 0) {
		printf("There are no real solutions\n");
	}
	else if (discriminant == 0) { 
		posX = ((b*-1)-(sqrt(discriminant)))/(2*a);
		printf("There is one real solution: %.2lf\n", posX);
	
	}
	else {
		posX = ((b*-1)+(sqrt(discriminant)))/(2*a);
		negX = ((b*-1)-(sqrt(discriminant)))/(2*a);
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n",posX);
		printf("Solution 2: %.2lf\n",negX);
	}
	
	return 0;
	 
}


int main() {

	double a, b, c;

	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);
	
	quadraticFormula(a,b,c);
	

return 0;
}

