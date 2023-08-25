#include <stdio.h>
/* 
This program asks the user to input their a, b, and c variables for an equation in quadratic equation form. Then,
it calculates whether there are 0, 1, or 2 real solutions, and their respective solutions to the given quadratic 
equation using the quadratic formula. 
Author: Camryn Shu
Due Date: 2/6/2023
*/
#include <math.h>
double computeDiscriminant(double variableA, double variableB, double variableC);
double discriminant; 
/*
This function definition, calculateDiscriminent, uses the parameteres variableA, variableB, and variableC
to specify the inputs. "variableA" is the "a" value in the quadratic equation. "variableB" is the "b" value in the 
quadratic equation. "variableC" is the "c" value in the quadratic equation. */

int main(void) /*
This function is the primary function that executes the starting point of the code.
In the main function it calls another function named "calculateDiscriminant" */
{
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	double variableA, variableB, variableC;

	printf("Please enter a : ");
	scanf("%lf", &variableA);
	printf("Please enter b : ");
	scanf("%lf", &variableB);
	printf("Please enter c : ");
	scanf("%lf", &variableC);

	double discriminant = computeDiscriminant(variableA, variableB, variableC);
	
	if (discriminant > 0) {
        double plusRoot = (-variableB + sqrt(discriminant))/(2*variableA); 
		double minusRoot = (-variableB - sqrt(discriminant))/(2*variableA);
		printf("There are 2 real solutions\n");
		printf("Solution 1 : %.2f\n", plusRoot);
		printf("Solution 2 : %.2f\n", minusRoot);
	} else if (discriminant == 0) {
		double zeroRoot = (-variableB)/(2*variableA);
		printf("There is one real solution : %.2f\n", zeroRoot);
	} else {
        printf("There are no real solutions\n");
	}
	return 0;
}
double computeDiscriminant(double variableA, double variableB, double variableC) {
	return (variableB*variableB)-(4*variableA*variableC);
}