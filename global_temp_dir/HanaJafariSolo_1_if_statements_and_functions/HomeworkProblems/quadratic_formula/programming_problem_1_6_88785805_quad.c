// this program will solve the quadratic formula (ideally)

#include <stdio.h>
#include <math.h>

int main(){

// intro message
printf("Given a quadratic equation of the form a*x^2 + b * x + c \n");

// user inputs value for a
double inputA = 88;
printf("Please enter a: \n");
scanf("%lf", &inputA);

// user inputs value for b
double inputB = 88;
printf("Please enter b: \n");
scanf("%lf", &inputB);

// user inputs value for c
double inputC = 88;
printf("Please enter c: \n");
scanf("%lf", &inputC);


// solving the quadratic formula

// let's deal with the -b part first
double negativeB = -88;
negativeB = inputB * -1;

// work out the bit under the square root: b^2 - 4ac
double root = 88;
root = (inputB * inputB) - (4 * inputA * inputC);

// actually do the square root
double rootResult = 88;
rootResult = sqrt(root);

// all over 2a
double denom = 88;
denom = 2 * inputA;

// how many solutions? aka the determinate 
// i completely forgot that this was a thing when I did the english explanation
// i can code but forgetting basic algebra is going to be my downfall in this class :) 
// lol i googled it and it's actually called "discriminant" i'm doing so good right now 

double solution1 = 88;
double solution2 = 88;

if(root > 0){
    solution1 = (negativeB + rootResult) / denom;
    solution2 = (negativeB - rootResult) / denom;
    printf("There are 2 real solutions \n");
    printf("Solution 1: %.2lf", solution1);
    printf("\n");
    printf("Solution 2: %.2lf", solution2);
    printf("\n");
}

if(root < 0){
    printf("There are no real solutions \n");
}

if(root == 0){
    solution1 = (negativeB + rootResult) / denom;
    printf("There is one real solution: ");
    printf("%.2lf", solution1);
    printf("\n");
}

    return 0;
}