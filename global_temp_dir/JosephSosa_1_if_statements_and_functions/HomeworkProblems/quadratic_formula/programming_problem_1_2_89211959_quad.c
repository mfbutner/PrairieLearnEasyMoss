#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//Quadratic Formula Calculator

//Checks if there even is a solution to the quadratic formula
int hasSolution(double a, double b , double c){
    //I made each statement tell how many solutions there were
    //makes it easier to see how many solutions I need.
    //no solutions
    if((pow(b,2.0) -(4 * a * c)) < 0){
        return 0;
    }
    //one solution
    else if((pow(b,2.0) -(4 * a * c)) == 0){
        return 1;
    }
    //two solutions
    else{
        return 2;
    }
}

/*Gives the positive solution
    If there is only one solution the program will just run this one because both will produce
    zero in the sqaure root.
*/
double posSolution(double a, double b, double c) {
    double d;
    d = (-b + sqrt((pow(b, 2.0) - (4 * a * c)))) / (2 * a);
    return d;
}

//Gives the negative solution
double negSolution(double a, double b, double c){
    double d;
    d = (-b - sqrt( ( pow(b, 2.0) - (4 * a * c) ) ) ) / (2 * a);
    return d;
}

//main function
int main(void){
    //printed and scanned to 2 decimal places
    double a;
    double b;
    double c;
    double oneSol = 0;
    double secSol = 0;
    int sol;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    //checks if there is a solution
    sol = hasSolution(a,b,c);

    //uses that sol variable to see what to print and get solutions
    //zero solutions
    if(sol == 0){
        printf("There are no real solutions");
    }
    //one solution
    else if(sol == 1){
        oneSol = posSolution(a,b,c);
        printf("There is one real solution: %.2lf", oneSol);
    }
    //two solutions
    else {
        oneSol = posSolution(a, b, c);
        secSol = negSolution(a, b, c);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", oneSol);
        printf("Solution 2: %.2lf", secSol);
    }
    return 0;
}