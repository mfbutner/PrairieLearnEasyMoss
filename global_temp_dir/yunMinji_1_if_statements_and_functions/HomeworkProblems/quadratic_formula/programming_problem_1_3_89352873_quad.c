#include <stdio.h>
#include <math.h>

// This program uses the user input values of the coefficient a, b, and c to calculate the roots of the quadratic equation 
// which uses the same coefficients 
// This program also tells the user how many roots to that quadratic equations exist and desplay all posible roots
// Two functions, main and quad

double quad(double a, double b, double c);

int main(void)
{
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    double a, b, c;                 // Initialize variables, a, b, and c stands for the coefficients in the quadratic equation

	printf("\nPlease enter a : "); 
	scanf("%lf", &a);               // Store value a

	printf("\nPlease enter b : ");
	scanf("%lf", &b);               // Store value b

	printf("\nPlease enter c : ");
	scanf("%lf", &c);               // Store value c

    double coeff = quad(a, b, c);   // coeff equals to the calculated value from line 52
	
	if(coeff < 0) 
    {
		printf("There are no real solutions\n");
	} 

    else if(coeff > 0)
    {
		double root1 = (-b + sqrt(coeff))/(2*a);    // line 35 and 36 are for calculating both roots
		double root2 = (-b - sqrt(coeff))/(2*a);

		printf("There are 2 real solutions\n");
		printf("Solution 1 : %.2f\n", root1);
		printf("Solution 2 : %.2f\n", root2);
	} 
    
    else    // coeff = 0
    {
		double root = -b/(2*a); //This is the only thing left from the quad formula because sqrt 0 = 0
		printf("There is one real solution : %.2f\n", root);
	}
	
	return 0;
}

double quad(double a, double b, double c)   // Second function, a, b, and c still stands for the coefficients in the quadratic equation
{
	return b*b -4*a*c;      // used in the if else statements above
}