// How to solve a  quadratic equation
#include <stdio.h> // Reference function
#include <string.h> // Reference function
#include <math.h> // Reference function

// Judge the value of 4ab to know what our value is
void quadraticEquation(double a, double b, double c) { //define 3 number
// define the quadratic equation
    double tmp = (b * b) - (4 * a * c);  // it menas b^2 - 4ab
// There are three kinds of answers

// The first case is when the tmp value we defined is less than zero
    if(tmp < 0) {
        printf("There are no real solutions\n"); // print answers
// The second case is when the tmp value we defined is equal to zero
    } else if (tmp == 0){
        double ret = -b / (2 * a); // Use the complete quadratic equation
        printf("There is one real solution: %.2lf\n", ret); // print answers
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
