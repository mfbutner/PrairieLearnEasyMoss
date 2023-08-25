//Asks user for inputs for quadratic equation and displays the solutions

#include <stdio.h>
#include <math.h>

/* determines number of roots based on coeffients of a quadratic equation
* a, b, and c are user inputs from the coefficients of a quadratic equation
* returns 0, 1, or 2 based on number of roots using the discriminant
*/
double numRoots(double a, double b, double c){

    double discriminant = (b * b) - (4 * a * c); //if discriminant == 0, 1 solution, if <0, no solutions

    if (discriminant < 0) {
        return 0;
    }
    else if (discriminant == 0) {
        return 1;
    }
    else if(discriminant > 0) {
        return 2;
    }
    return 0;
} 


int main(void){

    double a, b, c, Root1, Root2, numberRoots;

    //asks user for values
    printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");

    printf("Please enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);

    numberRoots = numRoots(a, b, c);

    //print solutions
    if (numberRoots == 0) {
        printf("There are no real solutions\n");
    }

    else if (numberRoots == 1){
        Root1 = -b / (2 * a);
        printf("There is one real solution: %.2lf\n", Root1);
    }

    else if (numberRoots == 2){

        printf("There are 2 real solutions\n");
        Root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
        printf("Solution 1: %.2lf\n", Root1);
        Root2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a); 
        printf("Solution 2: %.2lf\n", Root2);
    }
    return 0;
};