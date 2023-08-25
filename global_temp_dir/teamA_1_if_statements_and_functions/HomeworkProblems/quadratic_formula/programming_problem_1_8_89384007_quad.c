/* Program asks the user for a, b, and c and
 then displays the real roots of x if there are any.*/
#include <stdio.h>
#include <math.h> 

int main()
    {
        //declaring Variables 
        double a,b,c;
        double discriminant = 0.0; 
        double firstRoot, secondRoot; 

        //showing user the formula of a quadratic formula 
        printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

        //making user input for a,b,c
        printf("Please enter a: ");
        scanf("%lf", &a);
        printf("Please enter b: ");
        scanf("%lf", &b);
        printf("Please enter c: ");
        scanf("%lf", &c);

        //calculating the discriminant
        discriminant = (b*b) - (4*a*c);

        /* statement checks to see if there is any real solutions. 
        if there isn't it will print 'no real solutions'. 
        if discriminant equals 0 it will calculate the singular root and print that solution; 
        else it will calculate both roots and print out both solution. */ 
        if(discriminant < 0) {
            printf("There are no real solutions\n");
        } else if(discriminant == 0) { 
            double root = (-b/(2*a)); 
            printf("There is one real solution: %0.2f", root); 
        } else{
            firstRoot = ((-1*b) + sqrt(discriminant))/(2*a);
            secondRoot = ((-1*b) - sqrt(discriminant))/(2*a);
            printf("There are 2 real solutions\n");
            printf("Solution 1: %0.2f\n", firstRoot);
            printf("Solution 2: %0.2f\n", secondRoot);
        }

        return 0;

        }


