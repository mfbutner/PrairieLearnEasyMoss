# include <stdio.h>
# include <math.h>

// Andres Alcantar, February 3, 2023
// ECS 36A Butner
// Takes in values of a, b, and c from a polynomial
// and finds the roots using the quadratic formula

// Evaluating Delta to be later used during calculations
double findDelta(double a, double b, double c) {
    return (pow(b,2.0) - 4 * a * c);
}

// Finding the root using the given data (Used the scenarios of one and two solutions by changing positive to negative)
double findRoot(double deltaSqrRoot, double a, double b) {
    return (-b + deltaSqrRoot)/ (2.0 * a);
}
int main(void){
    double a;
    double b;
    double c;
    double delta; // Value under the square root

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
   
    // Taking user input for a
    scanf(" %lf", &a);

    printf("\nPlease enter b: ");

    // Taking user input for b
    scanf(" %lf", &b);  

    printf("\nPlease enter c: ");

    // Taking user input for c
    scanf(" %lf", &c);

    printf("\n");  

    // Storing value of delta to be used later in boolean comparisons and also in function calls
    delta = findDelta(a,b,c);

    // Delta is negative (No Solutions)
    if (delta < 0.0) {
        printf("There are no real solutions");
    }

    // Delta is zero (One Solution)
    else if (delta == 0.0) {
        printf("There is one real solution: %.2lf\n", findRoot(delta, a, b));
    }

    // Delta is postive (Two Solutions)
    else{
        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", findRoot(sqrt(delta), a, b), findRoot(-1 * sqrt(delta), a, b)  );
    }

    return 0;
}