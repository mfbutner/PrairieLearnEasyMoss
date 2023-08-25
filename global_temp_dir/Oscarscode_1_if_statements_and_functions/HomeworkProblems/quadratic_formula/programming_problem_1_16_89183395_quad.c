// program asks for 3 float values for the variables a,b, and c and finds the roots if any using the quadratic formula
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quadratic_formula(){
    /*
    This code asks for values for the variables a,b, and c and finds the discrimant to determine the number of roots. 
    Then it prints out the corresponding number of solutions. 
    */ 
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    double var_a;
    printf("Please enter a: ");
    scanf("%lf", &var_a);

    double var_b;
    printf("Please enter b: ");
    scanf("%lf", &var_b);

    double var_c;
    printf("Please enter c: ");
    scanf("%lf", &var_c);

    float number_of_roots = pow(var_b, 2) - (4 * var_a * var_c);
    if (number_of_roots > 0)
    {
        printf("There are 2 real solutions\n");
        double first_root = (-var_b + sqrt(pow(var_b, 2) - 4 * var_a * var_c)) / (2 * var_a);
        double second_root = (-var_b - sqrt(pow(var_b, 2) - 4 * var_a * var_c)) / (2 * var_a);
        if(first_root > 0)
        {
            printf("Solution 1: %.2lf \nSolution 2: %.2lf", first_root, second_root);
        }
        else if(second_root > 0){
            printf("Solution 1: %.2lf \nSolution 2: %.2lf", second_root, first_root);
        }
        else {
            printf("Solution 1: %.2lf \nSolution 2: %.2lf", first_root, second_root);
        }

    }
    else if (number_of_roots == 0)
    {
        printf("There is one real solution: ");
        double first_root = (-var_b + sqrt(pow(var_b, 2) - 4 * var_a * var_c)) / (2 * var_a);
        printf("%.2lf", first_root);
    }
    else {
        printf("There are no real solutions");
    }
}

int main() {
    quadratic_formula();
    return 0;
}