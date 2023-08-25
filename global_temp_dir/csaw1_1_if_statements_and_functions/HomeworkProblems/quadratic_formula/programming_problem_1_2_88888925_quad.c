#include <stdio.h>
#include <math.h>
/*
Given an a, b, and c, finds the roots of a quadratic equation with the form ax^2 + bx + c according to the quadratic formula ((-b + or - sqrt(b^2-4ac))/2a).
Tells the user how many roots there are (0, 1, 2) and then displays said roots if neccesary
*/

int findRootsOfQaudEq(double a, double b, double c);
void displayRootsOfQuadEq(double possibleRoot1, double possibleRoot2, int numRoots);

int main(void){
    //Main function, get's the user input for a, b, and c, then passes it to be solved
    // @ return a 0 for succesful completion of the program, -1 if otherwise

    double a = -99.1, b = -99.2, c = -99.3;
    int error_check;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&a);
    printf("Please enter b: ");
    scanf("%lf",&b);
    printf("Please enter c: ");
    scanf("%lf",&c);

    error_check = findRootsOfQaudEq(a, b, c);
    if (error_check == 0){
        return 0;
    } else {
        return -1;
    }
}

int findRootsOfQaudEq(double a, double b, double c){
    /* 
     Given an a, b, and c, solves for the roots according the quadratic formula
     First finds b^2-4ac to see if there is any possible roots (if the result is negative, there are no roots)
     Then solves it the rest of the way twice, once with -b - , and once with +b, comparing the results to see if they are the same
     finally passes the results along to be printed
     @param a A double representing a in the equation ax^2 + bx + c
     @param b A double representing b in the equation ax^2 + bx + c 
     @param c A double representing c in the equation ax^2 + bx + c
     @ return a 0 for succesful completion of the program, -1 if otherwise
    */ 

    double bSquaredSubtractedBy4ac = -99.5, possibleRoot1= -99.2, possibleRoot2 = -99.3;
    int numRoots;
    numRoots = -1;

    bSquaredSubtractedBy4ac = (pow(b, 2)) - (4 * a * c);

    if (bSquaredSubtractedBy4ac < 0){

        numRoots = 0;
    }else {

        possibleRoot1 = (-b + sqrt(bSquaredSubtractedBy4ac)) / (2 * a);
        possibleRoot2 = (-b - sqrt(bSquaredSubtractedBy4ac)) / (2 * a);
        if (possibleRoot1 == possibleRoot2){ // if the 2 possible roots are the same, then there is only 1 root

            numRoots = 1;
        }else {

            numRoots = 2;
        }
    }

    displayRootsOfQuadEq(possibleRoot1, possibleRoot2, numRoots);

    return 0;

}

void displayRootsOfQuadEq(double possibleRoot1, double possibleRoot2, int numRoots){
    /*
    Given the number of roots passed, displays to the user how many roots were found, and if any, then what those roots are.
    @param possibleRoot1 a double representing a possible root of a quadratic equation
    @param possibleRoot2 a double representing a possible root of a quadratic equation
    @param numRoots an int representing how many roots were found in the given quadratic equation
    */

    switch(numRoots){
        case 0: // 0 possible roots
            printf("There are no real solutions");
            break;
        case 1: // 1 possible root
            printf("There is one real solution: %0.2lf", possibleRoot1);
            break;
        case 2: // 2 possible roots
            printf("There are 2 real solutions\nSolution 1: %0.2lf\nSolution 2: %0.2lf", possibleRoot1, possibleRoot2);
            break;

    }
}