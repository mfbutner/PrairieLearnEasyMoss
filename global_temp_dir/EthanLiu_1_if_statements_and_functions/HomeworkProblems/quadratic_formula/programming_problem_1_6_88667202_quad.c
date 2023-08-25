	#include <stdio.h>
    #include <math.h>
      //This program find how many how many solutions a porabala has if possible calculates the solution/s
   void quadraticCalculator(double a, double b, double c);
    void quadraticCalculator(double a, double b, double c){
        //This function finds how many solutions a porabala has and calculates the solutions
        //the parameter a is for the first term in the porabola ax^2
        //the paratmeter b is for the second term in the porabola bx
        //The parameter c is for the third term in the porabola c
        //the function does not return anything
       double solutionOne ;
       double solutionTwo ;
        if(pow(b,2)-4*a*c<0){
            printf("There are no real solutions");

        }
        else if(pow(b,2)-(4*a*c)==0){
            solutionOne = -b/(2*a);
            

            printf("There is one real solution: %.2lf",solutionOne);

        }
        else if(pow(b,2)-4*a*c>0){
        solutionOne = (-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        solutionTwo = (-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n",solutionOne);
        printf("Solution 2: %.2lf\n",solutionTwo);
        }
    }

	int main() {
        
        double a =-300,b =-300,  c =-300;
      //asks user for the input
        printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
		printf("Please enter a:");
        scanf(" %lf",&a);
        printf("Please enter b:");
        scanf(" %lf",&b);
        printf("Please enter c:");
        scanf(" %lf",&c);
        quadraticCalculator(a,b,c);
   
    
		return 0;
    }