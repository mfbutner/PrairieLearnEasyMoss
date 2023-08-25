//This program solves a quadratic formula using user inputs

#include <stdio.h>
#include <math.h>

double solveFullEquation(double a, double b, double c, double d, int repeatNum){
//This function solves the rest of the quadratic equation
	if (d != 0){
		d = sqrt(d);
	}
	if (repeatNum == 2){
		d *= -1;
	}
	double finalAnswer = (-b + d) / (2 * a);
	return finalAnswer;
}

double numInsideSqrt(double a, double b, double c){
//This function gets the number that decides how many real solutions there are
	double number1 = b * b;
	double number2 = 4 * a * c;
	double numberFinal = number1 - number2;
	return numberFinal;
}

int main() {
//This is the main function of the program
	double numberA;
	double numberB;
	double numberC;
	printf("Given a quadratic equation of the form a*x^2 + b * x + c ");
	printf("Please enter a: ");
	scanf("%lf", &numberA);
	printf("Please enter b: ");
	scanf("%lf", &numberB);
	printf("Please enter c: ");
	scanf("%lf", &numberC);
	double numberD = numInsideSqrt(numberA, numberB, numberC);
	int repeatNum = 1;
	if (numberD < 0){
		printf("There are no real solutions");
	}
	else if (numberD == 0){
		double solution = solveFullEquation(numberA, numberB, numberC, numberD, repeatNum);
		printf("There is one real solution: %.2lf", solution);
	}
	else{
		double solution1 = solveFullEquation(numberA, numberB, numberC, numberD, repeatNum);
		repeatNum = 2;
		double solution2 = solveFullEquation(numberA, numberB, numberC, numberD, repeatNum);
		printf("There are 2 real solutions\nSolution 1: %.2lf \nSolution 2: %.2lf", solution1, solution2);
	}
	return 0;
}
