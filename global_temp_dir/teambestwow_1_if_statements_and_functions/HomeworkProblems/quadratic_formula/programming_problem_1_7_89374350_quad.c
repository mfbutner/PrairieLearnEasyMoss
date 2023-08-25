#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double inputs_user();
int output(double answer_positive, double answer_negative);
int main() {
    double a, b, c, answer_positive, answer_negative, sqaure_root_var;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    sqaure_root_var = (b * b) - 4 * a * c;
    if (sqaure_root_var == 0) sqaure_root_var = 0;
    answer_positive = (-1 * b + sqrt(sqaure_root_var))/(2 * (a));
    answer_negative = (-1 * b - sqrt(sqaure_root_var))/(2 * (a));
    output(answer_positive, answer_negative);
return 0;
}

int output(double answer_positive, double answer_negative){
    if (isnan(answer_positive) == true && isnan(answer_negative) == true){
        printf("There are no real solutions");
    }else if (answer_negative == answer_positive){
        printf("There is one real solution: %0.2lf", answer_negative);
    }else if (isnan(answer_positive) == true){
        printf("There is one real solution: %0.2lf", answer_negative);
    }else if (isnan(answer_negative) == true){
        printf("There is one real solution: %0.2lf", answer_positive);
    }else if (answer_positive > answer_negative){
        printf("There are 2 real solutions\nSolution 1: %0.2lf\nSolution 2: %0.2lf", answer_positive, answer_negative);
    }else if (answer_positive < answer_negative){
        printf("There are 2 real solutions\nSolution 1: %0.2lf\nSolution 2: %0.2lf", answer_positive, answer_negative);
    }
    return 0;
}