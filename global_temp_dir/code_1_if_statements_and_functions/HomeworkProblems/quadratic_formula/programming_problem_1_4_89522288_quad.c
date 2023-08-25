#include <stdio.h>
#include <math.h>

//declares functions 
double compare_variables(double a, double b, double c);
double add_zero(double a, double b);
double add_root(double a, double b, double c);
double subtract_root(double a, double b, double c);

/*solves for the value inside of the square root to see if number is positive or negative
 *parameter a, b, c are inputs someone enters 
 */
double compare_variables(double a, double b, double c){
    double x = pow(b, 2) - (4 * a * c);
    return x;
}

/*solves for the quadratic formula if the number inside the sqaure root is zero
 *parameter a and c are inputs someone enters 
 *returns a double, and there is only one solution 
 */
double add_zero(double a, double b){
    double y = (-b) / (2 * a);
    return y;
}

/*solves for one of the two solutions in quadratic formula by adding the square root of a number
 *parameter a, b, c are inputs someone enters 
 */
double add_root(double a, double b, double c){
    double solution1 = ((-b) + sqrt(((pow(b, 2)) - (4 * a * c)))) / (2 * a);
    return solution1;
}

/*solves for one of the two solutions in quadratic formula by subtracting the square root of a number
 *parameter a, b, c are inputs someone enters 
 */
double subtract_root(double a, double b, double c){
    double solution2 = ((-b) - sqrt(((pow(b, 2)) - (4 * a * c)))) / (2 * a);
    return solution2;
}

/*scans the numbers input, calls the other functions to solve quadractic formula 
 *prints the + solution first by comparing the values of the 2 solutions 
 */
int main(){
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    double num_a;
    printf("Please enter a: ");
    scanf("%lf", &num_a);

    double num_b;
    printf("Please enter b: ");
    scanf("%lf", &num_b);

    double num_c;
    printf("Please enter c: ");
    scanf("%lf", &num_c);  

    if (compare_variables(num_a, num_b, num_c) < 0){
        printf("There are no real solutions\n");
    }

    if (compare_variables(num_a, num_b, num_c) == 0){
        printf("There is one real solution: %.2f\n", add_zero(num_a, num_b));
    }

    if (compare_variables(num_a, num_b, num_c) > 0){
        printf("There are 2 real solutions\n");
        if (add_root(num_a, num_b, num_c) < 0){
            if (add_root(num_a, num_b, num_c) > subtract_root(num_a, num_b, num_c)){
                printf("Solution 1: %.2f\n", add_root(num_a, num_b, num_c));
                printf("Solution 2: %.2f\n", subtract_root(num_a, num_b, num_c));
            }
            else{
                printf("Solution 1: %.2f\n", subtract_root(num_a, num_b, num_c));
                printf("Solution 2: %.2f\n", add_root(num_a, num_b, num_c));
            }
        } 

        if (add_root(num_a, num_b, num_c) > 0){
            if (add_root(num_a, num_b, num_c) > subtract_root(num_a, num_b, num_c)){
                printf("Solution 1: %.2f\n", subtract_root(num_a, num_b, num_c));
                printf("Solution 2: %.2f\n", add_root(num_a, num_b, num_c));
            }
            else{
                printf("Solution 1: %.2f\n", add_root(num_a, num_b, num_c));
                printf("Solution 2: %.2f\n", subtract_root(num_a, num_b, num_c));
            }
        }
    }

    return 0;  
}