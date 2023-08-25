#include <stdio.h>
#include <math.h>
#include <ctype.h>
/*  HW #3.1: QUADRATIC FORMULA
    Anna Chan
    ECS 36A
    This program asks a user to enter the values of 
    a, b, and c, for the formula ax^2 + bx + c. It 
    then calculates the solution for the equation, 
    using the quadratic formula, and if there are no
    solutions, it lets the user know that there are
    no real solutions.
*/

//these two functions calculate the first and second solution. It 
//inputs the values a, b, and c it then creates a variable that 
//represents the value that goes inside the square root. the 
//function then calculates the solutions, using the quadratic
//formula, and returns each solution into solution 1 and 2.
double getSol1(double a1, double b1, double c1){
    double sol1;
    double insqrt;

    insqrt = (pow(b1,2.0))-((4 * a1) * c1); 
    if (insqrt >= 0){
        sol1 = ((-b1))+(sqrt(insqrt));
        sol1 = sol1 / (2 * a1);
    }
    else{
        sol1 = NAN;
    }
    return sol1;
}

double getSol2(double a2, double b2, double c2) {
    double sol2;
    double insqrt;

    insqrt = ((pow(b2,2.0))-((4 * a2) * c2)); 
    if (insqrt >= 0){    
        sol2 = ((-b2))-(sqrt(insqrt));
        sol2 = sol2 / (2 * a2);
    }
    else{
        sol2 = NAN;
    }
    return sol2;
}

// make inside sqr root, if inside sqr root is neg, then solution1 = false
int main(){
    double a;
    double b;
    double c;
    double solution1;
    double solution2;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    solution1 = getSol1(a,b,c);
    solution2 = getSol2(a,b,c);


    if ((isnan(solution1) && isnan(solution2))) {
        printf("There are no real solutions");
    }
    else if ((isnan(solution1)) || (isnan(solution2))) {
        if (isnan(solution1)){
            printf("There is one real solution: %.2lf\n", solution2);
        }
        else{
            printf("There is one real solution: %.2lf\n", solution1);
        }
    }
    else if(solution1 == solution2){
        printf("There is one real solution: %.2lf\n", solution1);
    }
    else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    } 

    return 0;
}