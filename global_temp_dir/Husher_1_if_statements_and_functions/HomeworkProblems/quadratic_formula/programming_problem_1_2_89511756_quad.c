#include <stdio.h>
#include <math.h>
/*
This program will allow users to be able to compute the quadratic formula using 
a quadratic equation of there choice
*/

/* 
This function will determine the amount of real solutions 
that the quadratic formula will compute using what is under
the square root allowing later in the program to compute the correct
amount of real solutions
*/
double NumOfSolutions(double a, double b, double c){ //the doubles a, b, and c represent a,b, and c in the quadratic equation the user wants to compute
    double num_under_sqroot = (b*b)-(4*(a*c));
    return num_under_sqroot; // this result will also be used in the quadratic formula calculation if it's greater than zero
}

int main(){
    double a;//coefficient a
    double b;//coefficient b
    double c;//coefficient c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    double sqroot_num = NumOfSolutions(a,b,c);

    /*
    This if-else branch will allow the program to determine the solutions it
    needs to calculate and print out depending on the result from the previous function
    NumofSolutions
    */

    if (sqroot_num < 0){
        printf("There are no real solutions\n");
    }
    else if (sqroot_num == 0){ //Calculates only one solution since the sqaure root of zero is zero and it doesnt matter if you add or subtract it
        double one_solution_ans = (-b) / (2*a); 
        printf("There is one real solution: %.2lf\n", one_solution_ans);
    }
    else {
        double two_solution_ans_one = (-b + (sqrt(sqroot_num)))/(2*a);
        double two_solution_ans_two = (-b - (sqrt(sqroot_num)))/(2*a) ;
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", two_solution_ans_one);
        printf("Solution 2: %.2lf\n", two_solution_ans_two);
    }

    return 0;
}