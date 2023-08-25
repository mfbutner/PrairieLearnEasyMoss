#include<stdio.h>
#include<math.h>

// This program is made to input three varibales and calculate the quadratic equation


// This function is what calculates how many solutions there are to the quadratic equation based on the inputs
double quadratic_equation_calculation(double a, double b, double c){
    
    double discriminant = (pow(b, 2)) - (4*a*c);

    if (discriminant < 0){
        printf("There are no real solutions");
    }
            
    if (discriminant == 0){
        double solution = (b * -1) / (2 * a);
        printf("There is one real solution: %.2lf", solution);
    }

    if (discriminant > 0){
        double quad_equation_pos = ((b * -1) + sqrt(((pow(b, 2)) - 4 * a * c))) / (2 * a);
        double quad_equation_neg = ((b * -1) - sqrt(((pow(b, 2)) - 4 * a * c))) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", quad_equation_pos);
        printf("Solution 2: %.2lf", quad_equation_neg);
    }   
    return 0;
}
int main(){
    double input_a;
    double input_b;
    double input_c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a:");
    scanf("%lf", &input_a);
    printf("Please enter b:");
    scanf("%lf", &input_b);
    printf("Please enter c:");
    scanf("%lf", &input_c);
    
    quadratic_equation_calculation(input_a, input_b, input_c);
}