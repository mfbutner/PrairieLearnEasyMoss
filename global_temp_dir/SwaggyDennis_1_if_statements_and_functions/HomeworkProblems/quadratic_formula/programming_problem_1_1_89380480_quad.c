#include <stdio.h>
#include <math.h>

// beginning of main function
int main()
{
	// Declaring Variables
	double a, b, c;
	double root1, root2;
	double determinant;
	// Setting up printf() and scanf() to read user's input
	printf("Given a quadratic equation of the form a*x^2+b*x+c\n");
	printf("Please enter a: ");
	scanf("%lf",&a);
	printf("Please enter b: ");
	scanf("%lf",&b);
	printf("Please enter c: ");
	scanf("%lf",&c);
	// calculating the determinant
	determinant = b * b - 4 * a * c;

	// setting a boundary for when roots are unequal AND real
	if (determinant > 0)
	{
		// Calculating both root1 and root2
		printf("There are 2 real solutions\n");
		root1 = (-b+sqrt(determinant)) / (2*a);
		root2 = (-b-sqrt(determinant)) / (2*a);
		// Output to show the roots to the solution
		printf("%s %.2f\n","Solution 1:", root1);
		printf("%s %.2f\n","Solution 2:", root2);
	}
	// setting a boundary for when roots are equal AND real
	else if (determinant == 0)
	{	// Output when one REAL solution is present
		printf("There is one real solution: ");
		root1 = root2 = -b / (2*a);
		printf("%.2lf\n", root1);
	}
	// setting what to print if a an imaginary number is encountered in the root (complex root)
	else
	{
		printf("There are no real solutions\n");
	}
}
	 // program ends here

