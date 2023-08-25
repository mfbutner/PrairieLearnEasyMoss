/*Purpose
This program calculate the roots of a quadaratic equation are values of that cause the equation to evaluate to 0.*/
#include <stdio.h>  //include the input and output
                    //#include is the commend to get input and output
#include <math.h>  // This header is for math function such                   as sqrt or pow

int main(void)
{
//1. Get number of roots of quadratic equation
    double a;
    double b;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    
//2. Set the quadratic formula
    double Number_in_sqrt = pow(b,2)-4*a*c;
    double Plus_x_value = (-b+ sqrt(Number_in_sqrt))/(2*a);
    double Minus_x_value = (-b- sqrt(Number_in_sqrt))/(2*a);
    
//3. Consider possibility to get number of solution
        //What condition make just one real number solution: After you calculate +-, the results of plus_x_value and minus_x_value are same real number then there are one real number solution
    if(Plus_x_value == Minus_x_value){
            //If there is one real number solution, then just say one real number solution and tell what it is
        printf("There is one real solution: ");
        printf("%.2lf\n", Plus_x_value);
    }

    
    
        //What conditions make two real number solutions: After you calculate +-, the results of plus_x_value and minus_x_value are different real number, and Calculation number in sqrt is not negative number, then there are two real number solution
    else if(Plus_x_value != Minus_x_value && Number_in_sqrt > 0){
            //If there is two real number solution, then just say two real number solution and tell what are they
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", Plus_x_value);
        printf("Solution 2: %.2lf\n", Minus_x_value);
    }

    
    
        //What conditions make no real number solutions: If the number in sqrt is negative number, then there are no real solution
    else if(Number_in_sqrt < 0){
            //If there is no real number solution, then just say there is no solution.
        printf("There are no real solutions\n");
    }
    return 0;
}
