#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//Pranav Rawat


//Create a program that solves the quadratic eqation

//does [-b -(radicand)]/2a
double QuadMinus(double a, double b, double c){
    return (-1*b -1*sqrt(pow(b,2)-4*a*c))/(2*a);
}
//does [-b +(radicand)]/2a
double QuadPlus(double a, double b, double c){
    return (-1*b +sqrt(pow(b,2)-4*a*c))/(2*a);

}
//Checks if the radicand is positive
bool SolutionsExist(double a, double b, double c){

        if ((pow(b,2)-4*a*c)>=0){
            return true;
        }
        else{
            return false;
        }
}

int main(){
//Initialize a b and c for the quadratic equation
    double a;
    double b;
    double c;
//initializes variables to hold the solutions
    double solution1;
    double solution2;
//Ask for the inputs
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);


    //Check is there are real solutions
    if(SolutionsExist(a,b,c)){
        //Solve the quadratic equation knowing that a real solution exists
        solution1 = QuadPlus(a,b,c);
        solution2 = QuadMinus(a,b,c);
        //If the solutions are the same, then there is only one solution
        if(fabs(solution1-solution2) <0.0000000000001){
            printf("There is one real solution: %.2lf", solution1);
        }
        //There are two solutions if both solutions are not the same
        else{
            printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf", solution1, solution2);
        }

    }
    //There are no real solutions if the radicand is negative
    else{
        printf("There are no real solutions");
    }
    return 0;

}