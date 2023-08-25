//Get the solution fo a quadratic equation
#include<stdio.h>
#include<math.h> 

void solve_the_equation(double a,double b,double c){
	/*
		Function:Tp solve a quadratic equation.
		Input:the coefficients of the equation ax^2 + b x + c = 0.
			a is the coefficient of x^2
			b is the coefficient of x
			c is the constant
		Output:
			when b*b-4*a*c < 0 ----no solution
			when b*b-4*a*c = 0 ----one solution:(-b/(2*a))
			when b*b-4*a*c > 0 ----twon solutions:(-b+sqrt(delta))/(a*2) and -b-sqrt(delta))/(a*2) ) 
	*/
	double delta = b*b-4*a*c;
	if(delta<0){
		printf("There are no real solutions\n");
	}
	else if(delta==0){
		printf("There is one real solution: %.2lf\n",-b/(2*a));
	}
	else{
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n",(-b+sqrt(delta))/(a*2));
		printf("Solution 2: %.2lf\n",(-b-sqrt(delta))/(a*2));
	}
}

int main(){
	double equa_a,equa_b,equa_c;
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf",&equa_a);
	printf("Please enter b: ");
	scanf("%lf",&equa_b);
	printf("Please enter c: ");
	scanf("%lf",&equa_c);
	solve_the_equation(equa_a,equa_b,equa_c);
	return 0;
} 
