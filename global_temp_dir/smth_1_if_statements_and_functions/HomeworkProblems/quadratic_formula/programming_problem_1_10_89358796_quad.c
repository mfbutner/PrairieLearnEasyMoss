/*To solve quadratic equation*/
#include <stdio.h>
#include <math.h>
int main(){
    double a;
    double b;
    double c;
    double result1;
    double result2;
    //initalize the variable we are going to use 
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    //ask the user to input the value of a, b and c in equation ax^2 +bx +c
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    // recieve the value of a, b, and c
    if ( pow(b,2)-4*a*c  > 0){
        result1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
        result2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", result1);
        printf("Solution 2: %.2lf\n", result2);
    }
    // ckeck if b^2-4ac is greater than 0, if so, then calculate the result solution1 and solution2 by use the formula, and show on the screen to the user
    else if (pow(b,2)-4*a*c == 0){
        result1= -b/(2*a);
        printf("There is one real solution: %.2lf\n", result1);
    }
    // ckeck if b^2-4ac is equal to 0, if so, calculate the result by simply calculate -b/(2a) and show it to the user
    else {
        printf("There are no real solutions\n");
    }
    //other than that b^2-4ac must less than 0, therefore show the user that there are not real solutions
    return 0;
}