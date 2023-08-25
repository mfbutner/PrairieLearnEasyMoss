/* student: Qiduan Liao
 * code:  HW3  quad.c
 * function: Read coeffs input
 * 		calcualte roots
 * 		display results*/

#include <stdio.h>
#include <math.h>

/*	Define a function to calcualte roots
 * 	Function will return roots into root_array 
 * 	passed as argument*/


void calc_roots(double a, double b, double c, double* root_array){
	
	double res1, res2; // Define variables to hold root calc results
	res1 = (-b + sqrt(b*b - 4*a*c))/(2.0*a); // Calculate first root
	res2 = (-b - sqrt(b*b - 4*a*c))/(2.0*a); // Calculate second root

	root_array[0] = res1 ;  // Return first root to array first loc
	root_array[1] = res2 ;  // Return second root to array second loc
}


int main(void){
	double result_array[2] = {0,0};  // Define a double array holding root results
	double a, b, c; // Define variables to hold inputs
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);

	calc_roots(a, b, c, result_array); // Call the function to calculate roots
	

	if(isnan(result_array[0])){
		printf("There are no real solutions\n");
			
	}	
	else{
		if (result_array[0]==result_array[1]){
			printf("There is one real solution: %.2lf\n", result_array[0]);		
		}
		else{
			printf("There are 2 real solutions\n");
			printf("Solution 1: %.2lf\n", result_array[0]);
			printf("Solution 2: %.2lf\n", result_array[1]);
		}
	
	
	}
	

}
