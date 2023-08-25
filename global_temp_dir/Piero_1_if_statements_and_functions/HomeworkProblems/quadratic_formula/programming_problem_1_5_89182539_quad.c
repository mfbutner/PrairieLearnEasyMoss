
// The program determines the solutions 

#include <stdio.h>
#include <math.h>

double a, b, c;
double discriminantVal;
double solutionOne, solutionTwo;
double discriminantValue;


double Discriminant(double a, double b, double c){
	a = a * c;
        discriminantVal = (double) pow(b, 2) - (4 * a);
        return discriminantVal;
}

double  GeneralFormula1(double a, double b, double discriminantValue){
        solutionOne = ((-b) + sqrt(discriminantValue)) / (2 * a);
  
        return solutionOne;

}


double  GeneralFormula2(double a, double b, double discriminantValue){
       
        solutionTwo = ((-b) - sqrt(discriminantValue)) / (2 * a);
        
        return solutionTwo;

}
int main(){

        printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

        printf("Please enter a: ");
        scanf("%lf",&a);
        
        printf("Please enter b: ");
        scanf("%lf",&b);

        printf("Please enter c: ");
        scanf("%lf",&c);

        discriminantValue = Discriminant(a, b, c);

        if(discriminantValue > 0){
                solutionOne = GeneralFormula1(a, b, discriminantValue);
                solutionTwo = GeneralFormula2(a, b, discriminantValue);
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", solutionOne);
                printf("Solution 2: %.2lf", solutionTwo);
        }

        if(discriminantValue == 0){
                solutionOne = GeneralFormula1(a, b, discriminantValue);
                printf("There is one real solution: %.2lf", solutionOne);
        }

        if(discriminantValue < 0){
                printf("There are no real solutions");
        }

        return 0;
}
