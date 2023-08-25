#include <stdio.h>
#include <math.h>

int findNumRoots();

void findAndPrintRoots();

//asks the user for double values of a, b, and c and stores the values
//returns 0 if everything functions properly
int main()
{
	double a;
	double b;
	double c;
	int numRoots = -1;

	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);

	printf("Please enter b: ");
	scanf("%lf", &b);

	printf("Please enter c: ");
	scanf("%lf", &c);

	numRoots = findNumRoots(a, b, c);
	findAndPrintRoots(numRoots, a, b, c);
	return 0;
}

//determines the number of real roots of the quadratic based on the sign of the inner expression b^2 - 4ac
//the parameters are all user entered values for a, b, and c, stored in main
//returns the number of real roots
int findNumRoots(double a, double b, double c)
{
	double val = b * b - (4 * a * c);

	if (val < 0)
	{
		return 0;
	}
	else if (val == 0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

//calculates the roots, if any, based on the number of real roots of the quadratic found in findNumRoots
//numRoots is the return value findNumRoots and represents how many real roots the quadratic has
//a, b, and c are user entered values stored in main
void findAndPrintRoots(int numRoots, double a, double b, double c)
{
	if (numRoots == 0)
	{
		printf("There are no real solutions\n");
	}
	else if (numRoots == 1)
	{
		double sol = -b / (2 * a);
		printf("There is one real solution: %.2lf\n", sol);
	}
	else
	{
		double base = -b / (2 * a);
		double diff = sqrt(b * b - (4 * a * c)) / (2 * a);

		double sol1 = base + diff;
		double sol2 = base - diff;

		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n", sol1);
		printf("Solution 2: %.2lf\n", sol2);
	}
}
