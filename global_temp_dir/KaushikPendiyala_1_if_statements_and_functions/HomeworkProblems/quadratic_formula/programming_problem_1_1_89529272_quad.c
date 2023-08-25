#include <stdio.h>
#include<math.h>
/*
This program takes in 3 values from the user in a quadratic equation and then applies the quadratc
formula to the numbers to determine all the real roots and then outputs them back to the user.
*/
int main();
int inputUser();
int numberOfSolutions(double a, double b, double c);
int noSolutions();
int oneSolution(double a, double b, double c);
int twoSolutions(double a, double b, double c);

int main(){
    /*
    This is the main function of the program and it is where everything begins. It calls the InputUser
    function to start off the program. There are no parameters for this function
    */
    inputUser();
    return 0;
}

int inputUser(){
    /*
    The inputUser function takes in the user-inputted values of a, and and c from the user and stores
    them in variables. Finally it calls the numberOfSolutions function. There are no parameters
    for this function
    */
    double a;
    double b;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&a);
    printf("Please enter b: ");
    scanf("%lf",&b);
    printf("Please enter c: ");
    scanf("%lf",&c);
    numberOfSolutions(a,b,c);
    return 0;
}

int numberOfSolutions(double a, double b, double c){
    /*
    The numberOfSolutions function uses part of the quadratic formula to determine how many solutions
    the problem should have and then runs the appropriate function using if statements. There are
    three double parameters in this function, a, b, and c. These three doubles are the three numbers
    the user inputted for their values in the inputUser() function.
    */
    if (pow(b,2)< 4*a*c){
        noSolutions();
    }
    else if (pow(b,2)== 4*a*c){
        oneSolution(a, b, c);
    }
    else{
        twoSolutions(a, b, c);
    }
    return 0;
}

int noSolutions(){
    /*
    If the program determines there to be no real solutions, this function will tell the user that
    there are no real solutions. There are no parameters for this function.
    */
    printf("There are no real solutions");
    return 0;
}

int oneSolution(double a, double b, double c){
    /*
    If the program determines that there is one solution, this function determines that one solution
    by applying the quadratic formula and printing out the solution. There are three double parameters
    in this function, a, b, and c. These three doubles are the three numbers the user inputted for their
    values in the inputUser() function
    */
    double numerator = (-b + pow(pow(b,2) - 4*a*c, 0.5));
    double denominator = 2 * a;
    double answer = numerator / denominator;
    printf("There is one real solution: %.2lf", answer);
    return 0;
}

int twoSolutions(double a, double b, double c){
    /*
    If the program determines there to be two solutions, this function detemines both solutions by 
    calculating the positive and negative versions of the formula and the printing out both of the
    solutions to the user. There are three double parameters in this function, a, b, and c. These 
    three doubles are the three numbers the user inputted for their values in the inputUser() function
    */
    double numerator_positive = (-b + pow(pow(b,2) - 4*a*c, 0.5));
    double numerator_negative = (-b - pow(pow(b,2) - 4*a*c, 0.5));
    double denominator = 2 * a;
    double answer1 = numerator_positive / denominator;
    double answer2 = numerator_negative / denominator;
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", answer1);
    printf("Solution 2: %.2lf", answer2);
    return 0;
}
