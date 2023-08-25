//Noah Chang - ECS36A
//Gets a trinomial from the user and prints all solutions with the quadritic formula.

#include <stdio.h>
#include <math.h>

//Calculates all solutions using the quadratic formula (both positive and negative versions)
//Also prints how many solutions there are along with the real roots (greater real root comes first if there is)
//@a,b,c: the real numbers gotten from the user
//@returns: real root of x (solution of quadratic formula)
void CalculateQuadraticFormula(double a, double b, double c){
    double discriminant;
    double realRoot1, realRoot2;
    int numSolutions;

    //calculate using quadratic formula
    discriminant = pow(b,2) - (4 * a * c);
    if(discriminant < 0){
        numSolutions = 0;
    } else{
        realRoot1 = (-b + sqrt(discriminant)) / (2 * a);
        realRoot2 = (-b - sqrt(discriminant)) / (2 * a);
        //how many solutions there are
        if(realRoot1 == realRoot2){
            numSolutions = 1;
        } else{
            numSolutions = 2;
        }
    }

    //print statements
    if(numSolutions == 0){
        printf("There are no real solutions\n");
    } else if(numSolutions == 1){
        printf("There is one real solution: %.2lf\n", realRoot1);
    } else if((numSolutions == 2) && (realRoot2 > 0) && (realRoot1 < 0)){
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", realRoot2, realRoot1);
    } else if((numSolutions == 2)){
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", realRoot1, realRoot2);
    }
}

int main(){
    double a, b, c;

    //get a, b, and c from user
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);

    CalculateQuadraticFormula(a, b, c);

    return 0;
}