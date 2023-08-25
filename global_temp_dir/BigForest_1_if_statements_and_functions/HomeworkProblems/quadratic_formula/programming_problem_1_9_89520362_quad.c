/*A quadratic equation is an equation in the form a*x^2+bx+c

The roots of a quadratic equation are values of x that cause the equation to evaluate to 0 and can be solved for using the quadratic equation: 
 
x=(-b +/- sqrt(b^2-4ac)/2a) 

Depending on the values of a, b, and c there may be 0, 1, or 2 real solutions.

Write a program called quad.c that asks the user for a, b, and c and then displays the real roots of x if there are any.*/

#include<stdio.h>
#include<math.h>

void Squareroot(double a,double b,double c){ 
    double result,root1,root2; 

    result = pow(b,2)-(4*a*c); // result if b^2-4ac

    if (result < 0){  //condition 1
        printf("There are no real solutions\n");
    }

    else if(result == 0){ //condition 2
        root1 = -b / (2*a);
        printf("There is one real solution: %.2lf\n", root1);
    }

    else{ //condition 3
        printf("There are 2 real solutions\n");
        root1 =  (-b + sqrt(result)) / (2*a); // x1 value
        printf("Solution 1: %.2lf\n", root1);

        root2 =  (-b - sqrt(result)) / (2*a); //x2 value
        printf("Solution 2: %.2lf\n", root2);     
    }
}

int main() //main function
{
    double va; // value of a
    double vb;// value of b
    double vc;// value of c

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &va);

    printf("Please enter b: ");
    scanf("%lf", &vb);

    printf("Please enter c: ");
    scanf("%lf", &vc);

    Squareroot(va,vb,vc); 

    return 0;
}
