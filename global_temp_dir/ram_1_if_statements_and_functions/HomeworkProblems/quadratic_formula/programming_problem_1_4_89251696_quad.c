#include <stdio.h>
#include <math.h>

double values(double a, double b, double c){
    double disc;
    disc = pow(b,2) - (4*a*c);
    
    return disc;
}


int main() {
    double user_A_value;
    double user_B_value;
    double user_C_value;
    
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    
    printf("Please enter a: ");
    scanf("%lf", &user_A_value);
    
    printf("Please enter b: ");
    scanf("%lf", &user_B_value);
    
    printf("Please enter c: ");
    scanf("%lf", &user_C_value);
    
    double solutions = values(user_A_value,user_B_value,user_C_value);
    
    double positive_solution = -(user_B_value + sqrt(solutions))/(2*user_A_value);
    double negative_solution = -(user_B_value - sqrt(solutions))/(2*user_A_value);
    
    
    if (solutions ==0){

        printf("There is one real solution: %.2lf", positive_solution);
    }
    else {
        if (solutions >0){
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", negative_solution);
            printf("Solution 2: %.2lf", positive_solution);
        }
    else {
       printf("There are no real solutions");
    }
    }
    
    

    return 0;
}