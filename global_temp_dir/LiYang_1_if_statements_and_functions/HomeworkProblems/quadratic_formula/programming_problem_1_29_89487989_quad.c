#include <stdio.h>
#include <math.h>


double calculating(double A, double B, double C){
    
    double discriminant = 0;//Declare double variable to store the discriminant.

    return discriminant = B * B - 4 * A * C; // Calculate number of discriminant.

    }



int main(void){
    double a, b, c;// Declare double variables to store the number of a b and c.

    double output1 = 0;// Declare double variable to store the + solution. 
    double output2 = 0;// Declare double variable to store the - solution. 
    double output = 0;// Declare double variable to store the solution when discriminant equals to 0. 

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");// Tell the user what the equation is.
    printf("Please enter a : ");// Prompt user to enter the number of a.
    scanf("%lf", &a);// Store user input in a.
    printf("\n");// Switch line.
    printf("Please enter b : ");// Prompt user to enter the number of b.
    scanf("%lf", &b);// Store user input in b.
    printf("\n");// Switch line.
    printf("Please enter c : ");// Prompt user to enter the number of c.
    scanf("%lf", &c);// Store user input in c.
    printf("\n");// Switch line.
    
	    
    double Discriminant = calculating(a, b, c);//Assign variables a, b and c to function calculating and running.

    if (Discriminant < 0){
    printf("There are no real solutions\n");// Print the outpout of function when discriminant < 0.

    } 
    else if (Discriminant == 0){
    output = -b / (2 * a);// Calculate number of output.
    printf("There is one real solution: %.2f\n", output);// Print the outpout of function when discriminant = 0.

    }
    else {
    output1 = (-b + sqrt(Discriminant)) / (2 * a); // Calculate number of output1.
    output2 = (-b - sqrt(Discriminant)) / (2 * a); // Calculate number of output2.
    
    printf("There are 2 real solutions\n"); // Print the outpout1&2 of function when discriminant > 0.
    printf("Solution 1 : %.2f\n", output1); // Print the outpout1 of function.
	printf("Solution 2 : %.2f\n", output2); // Print the outpout2 of function.

    }
}