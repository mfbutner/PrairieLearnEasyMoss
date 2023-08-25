# My Algorithm (steps to solve the problem)
# Solve the function

// How to solve a  quadratic equation
#include <stdio.h> // Reference function
#include <string.h> // Reference function
#include <math.h> // Reference function

# Test 4ab
##1.Create an equation that can test several roots
##2.Test how many roots this formula has
##3.There are several answers to the corresponding situation
// Judge the value of 4ab to know what our value is
void quadraticEquation(double a, double b, double c) { //define 3 number
// define the quadratic equation
    double tmp = (b * b) - (4 * a * c);  // it menas b^2 - 4ab
// There are three kinds of answers
#If 4ab <0
##1.There are no real solution
// The first case is when the tmp value we defined is less than zero
    if(tmp < 0) {
        printf("There are no real solutions\n"); // print answers
#If 4ab =0
##1.There There is one real solution
##2.Print the answer
// The second case is when the tmp value we defined is equal to zero
    } else if (tmp == 0){
        double ret = -b / (2 * a); // Use the complete quadratic equation
        printf("There is one real solution: %.2lf\n", ret); // print answers
#If 4ab =0
##1.There are 2 real solutions
##2.Print 2 answers
// The third case is when the tmp value we defined is greater than zero
    } else {
    // Use the complete quadratic equation 
        double ret1 = (-b + sqrt(tmp)) / (2 * a);
        double ret2 = (-b - sqrt(tmp)) / (2 * a);
        printf("There are 2 real solutions\n"); // print answers
        printf("Solution 1: %.2lf\n", ret1); // print answers
        printf("Solution 2: %.2lf\n", ret2); // print answers
    }
}

#Use the function
##1.Enter three numeric values
##2.Use the test of 4ab to get answer
// Use main function in c programming
int main(void) {
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); // Ask a question

    double firstNum; // define the first number
    printf("Please enter a: "); // enter a number 
    scanf("%lf", &firstNum); // read the value

    double secondNum; // define the second number
    printf("Please enter b: "); // enter a number
    scanf("%lf", &secondNum); // read the value

    double thirdNum; // define the third number
    printf("Please enter c: "); // enter a number
    scanf("%lf", &thirdNum); // read the value
// use the quadratic Equation, we defined in the begging
    quadraticEquation(firstNum, secondNum, thirdNum);

    return 0;
}