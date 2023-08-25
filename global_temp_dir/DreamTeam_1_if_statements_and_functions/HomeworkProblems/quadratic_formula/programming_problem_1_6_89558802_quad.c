/*This program will calculate the number of roots/solutions given the values a, b, and c for a quadratic function.
 */
#include <stdio.h>
#include <math.h>
double calculate_discriminant(double value_a, double value_b, double value_c){
    //This function will calculate the discriminant value.
    /*
    @ value_a: the variable a in the quadratic formula
    @ value_b: the variable b in the quadratic formula
    @ value_c: the variable c in the quadratic formula
    @returns: the discriminant value
     */
    double discriminant_value;
    return discriminant_value = (value_b) * (value_b) - 4 * (value_a) * (value_c);
}

int main() {
    //This is the main program where we ask the user for the a,b,c values for the formula as well as calculate in cases
    //of only one solution. Once we have all that info and calculate the discriminant, we can check how many solutions
    //the equation has and calculate them.
        //Parameters: None
        //Return: 0; Nothing
    double input_a, input_b, input_c, only_one_solution, positive_root, negative_root;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &input_a);
    printf("Please enter b: ");
    scanf("%lf", &input_b);
    printf("Please enter c: ");
    scanf("%lf", &input_c);

    only_one_solution = (-1 * input_b) / (2 * input_a);
    double discriminant = calculate_discriminant(input_a, input_b, input_c);

    if (discriminant < 0){
        printf("There are no real solutions");
    }else if (discriminant == 0){
        printf("There is one real solution: %.2lf", only_one_solution);
    }else{
        positive_root = ((-input_b) + (sqrt(discriminant))) / (2 * input_a);
        negative_root = ((-input_b) - (sqrt(discriminant))) / (2 * input_a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", positive_root);
        printf("Solution 2: %.2lf", negative_root);
    }
    return 0;
}



