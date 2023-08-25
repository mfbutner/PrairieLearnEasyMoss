#include <stdio.h>
#include <math.h>

void calculateSolution(double a, double b, double c)  {
    double x1, x2;  /* while x1, x2 stand for the solution of quadratic equation */
    
    if ((pow(b, 2) - 4 * a * c) >= 0)  {
        x1 = (-b + sqrt(pow(b, 2.0) - 4.0 * a * c)) / (2.0 * a);
        x2 = (-b - sqrt(pow(b, 2.0) - 4.0 * a * c)) / (2.0 * a);

        if (x1 == x2)  {
            printf("There is one real solution: %.2lf\n", x1);
        }
        else if (x1 != x2)  {
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", x1);
            printf("Solution 2: %.2lf\n", x2);
        }
    }
    else  {
        printf("There are no real solutions\n");
    } 
}

int main(void)  {
    double a, b, c; /*a, b, c = parameters for quadratic equation */
 
    
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: \n");
    scanf(" %lf", &a);

    printf("Please enter b: \n");
    scanf(" %lf", &b);

    printf("Please enter c: \n");
    scanf(" %lf", &c);

    calculateSolution(a, b, c);

    return 0;
}
