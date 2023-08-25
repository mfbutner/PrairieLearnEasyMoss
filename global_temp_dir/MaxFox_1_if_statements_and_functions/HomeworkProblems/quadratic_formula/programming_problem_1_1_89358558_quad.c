/*
This program gets a quadratic equation from the user and then determines the number of real roots
(if there are any at all). Once it determines what the roots are, it gives them back to the user. 
*/

//include the standard input and output library
#include <stdio.h>
//include the boolean library
#include <stdbool.h>
//include the math library
#include <math.h>

//decalre all the functions so they can be written after the main function
double userInputForPart(char partLetter);
bool findIfHasRealRoots(double a, double b, double c); 
double findRoots(double a, double b, double c, bool wantToAdd); 

/*
@ What it does: the main function is the point of execution for the program and is where the system
runs the program

@ Parameters: the main function takes no parameters

@ Returns: the main function returns a value describing whether or not it was successful, with 0
indicating success; that is why we return the integer literal 0 at the bottom 
*/
int main(){

    //Declare variables which will hold a, b, and c respectively from the eqation ax^2 + bx + c
    double a, b, c; 

    //declare a variable that will tell if there are real roots
    bool hasRealRoots = false; 

    //declare two variables to hold the roots
    double firstRoot, secondRoot; 

    //declare a variable to tell if the two roots are the same
    bool twoRootsAreSame = false; 

    //Get input from the user in the standard form of a quadratic eqatuion, utilizing the
    //function for user input to reduce reptitive code 
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    a = userInputForPart('a');
    b = userInputForPart('b');
    c = userInputForPart('c');

    //Determine if the roots will be real by calling the function which determines this
    hasRealRoots = findIfHasRealRoots(a,b,c); 

    //If it has no real real roots, tell the user as much, and exit the program
    if(!hasRealRoots){

        printf("There are no real solutions");
        return 0; 
    }

    //call the function that finds the roots 
    firstRoot = findRoots(a,b,c,true);
    secondRoot = findRoots(a,b,c,false); 

    //find if the two roots are the same
    twoRootsAreSame = firstRoot == secondRoot; 

    //if the two roots are the same, only print one solution, and if they aren't, print two 
    if(twoRootsAreSame){
        printf("There is one real solution: %.2lf",firstRoot);
    }else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n",firstRoot);
        printf("Solution 2: %.2lf",secondRoot); 
    }

    //include the standard return for the main function
    return 0; 
}

/*
What it does: this function gets user input for the value indicated by the parameter

@ Parameter partLetter : the character for the part of the quadratic equation that the user needs
to input

@ Returns: the double value the user inputted 
*/

double userInputForPart(char partLetter){

    //create a varialbe to hold the user input 
    double userInputtedValue;

    //get the input from the user 
    printf("Please enter %c: ", partLetter);
    scanf("%lf",&userInputtedValue);

    //return the input 
    return userInputtedValue; 

}

/*
What it does: this function finds if a quadratic equation with the given a, b, and c parts
can produce any real solutions 

@ Parameter a : corresponds to the "a" part in ax^2 + bx + c
@ Paramter b : corresponds to the "b" part in ax^2 + bx + c
@ Parameter c : corresponds to the "c" part in ax^2 + bx + c

@ Returns: a boolean value of true or false is returned to indicate whether or not the quadratic equation
with the given parts has any real solutions 
*/

bool findIfHasRealRoots(double a, double b, double c){

    //find the value produced by solving inside the square root in the quadratic formula
    double resultInsideSqrt = pow(b,2) - (4*a*c); 

    //return true if it is positive or false if it is negative
    return resultInsideSqrt == fabs(resultInsideSqrt); 
}

/*
@ What it does: this function finds a single root, determined by whether or not its call tells
it to add the square root or subtract the square root

@ Parameter a : corresponds to the "a" part in ax^2 + bx + c
@ Paramter b : corresponds to the "b" part in ax^2 + bx + c
@ Parameter c : corresponds to the "c" part in ax^2 + bx + c
@ Parameter wantToAdd : tells the function whether or not it should add or subtract the square root
value, with a value of true indicating that it should 

@ Returns: a double value that is a root of the inputed quadratic equation with a, b, and c
*/

double findRoots(double a, double b, double c, bool wantToAdd){

    //declare a variable to hold the root 
    double root; 

    //get value for inside of square root 
    double valInsideSqrt = pow(b,2) - (4*a*c);

    //perform the calcuation indicated by the parameter
    if(wantToAdd){
        root = (-1*b) + (sqrt(valInsideSqrt));
        root /= (2*a);
    }else{
        root = (-1*b) - (sqrt(valInsideSqrt));
        root /= (2*a);
    }

    return root; 
}