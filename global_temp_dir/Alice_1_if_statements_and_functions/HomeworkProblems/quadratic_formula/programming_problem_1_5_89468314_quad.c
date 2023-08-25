/* 
This program takes the user input for a, b, and c values then calculates the solutions/roots of the function using the quadratic formula
if possible. If the quadratic formula is not possible to apply to the quadratic function given by user input, then no solutions will be 
possible. If there are no real solutions, display that there are no real solutions. After calculating possible solutions, display the roots 
to the screen.
*/

#include <stdio.h>
#include <math.h>

//function declarations, so they can be called 
void quadratic_formula(double a, double b, double c);

//ask user for the input for a, b, c
//display the real roots of x
int main(){
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    printf("Given a quadratic equation of the form a*x^2 + b*x + c\n");
    printf("Please enter a: \n");
    scanf("%lf", &a);
    printf("Please enter b: \n");
    scanf("%lf", &b); 
    printf("Please enter c: \n");
    scanf("%lf", &c);

    quadratic_formula(a, b, c);
}

//check to see if the quadratic formula is able to be applied to the user input function
//checking 
void quadratic_formula(double a, double b, double c){
    //variables
    double val_under_root = 0.0;
    double pos_numerator = 0.0;
    double neg_numerator = 0.0;
    double denominator = 0.0;
    double root1 = 0.0;
    double root2 = 0.0;

    val_under_root = pow(b,2) - (4 * a * c);

    //check to see if the value to be square rooted is negative
    if (val_under_root < 0){
        printf("There are no real solutions");
    }else{
        //adding
        pos_numerator = -(b) + sqrt(val_under_root);
        //subtracting
        neg_numerator = -(b) - sqrt(val_under_root);
        denominator = 2.0 * a;
        root1 = pos_numerator / denominator;
        root2 = neg_numerator / denominator;
            if (root1 == root2){
                printf("There is one real solution: %.2lf", root1);
            }else{
                printf("There are 2 real solutions \n");
                printf("Solution 1: %.2lf\n", root1);
                printf("Solution 2: %.2lf\n", root2);
            }
    }
}
