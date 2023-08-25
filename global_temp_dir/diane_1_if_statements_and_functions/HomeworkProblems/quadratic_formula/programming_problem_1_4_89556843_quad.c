#include <stdio.h>
#include <math.h>

/*Given the quadratic formula solve for the discriminant with values from user input.
Determine the number of solutions (0, 1, or 2) from the discriminant's value. 
Then solve for the x-values.*/

double solveDiscriminant(double a, double b, double c){
    /*Solve for the discriminant with user input values (a, b, c).
    Arguments in parameters (a, b, and c) are coefficients entered from user input.*/
    double disc;
    
    disc = (pow(b, 2) - 4 * a * c);
    return disc;
}

int main(void){
    /*Recieve user input and determine number of x values depending 
    on discriminant value (positive, negative, or zero). Then solve for x-values.
    */
    double a;
    double b;
    double c;
    double x1;
    double x2; 
    double x3;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);

    if (solveDiscriminant(a, b, c)>0){
        x1 = ((-b + sqrt(solveDiscriminant(a, b, c))))/ (2 * a);
        x2 = ((-b - sqrt(solveDiscriminant(a, b, c))))/ (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", x1);
        printf("Solution 2: %.2lf\n", x2);
    }
    else if (solveDiscriminant(a, b, c)==0){
        x3 = ((-b + sqrt(solveDiscriminant(a, b, c))))/ (2 * a);
        printf("There is one real solution: %.2lf", x3);
    }
    else {
        printf("There are no real solutions");
    }
}