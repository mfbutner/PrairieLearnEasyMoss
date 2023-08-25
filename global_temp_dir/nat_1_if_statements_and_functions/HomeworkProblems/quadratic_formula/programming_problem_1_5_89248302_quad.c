# include <stdio.h>
# include <math.h>

/* 
Uses the quadratic equation to find the real roots of x given a, b, and c
*/

int main() {
    
    double a = -6, b = -29, c = -45; 

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    // get user inputted values (a,b,c) to plug into the quadratic equation
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    double quadraticExpression = (pow(b, 2) - (4 * a * c)); // evaluates part of the quadratic equation first
    double solution1 = -34, solution2 = -48;

    /*
    if the quadratic expression is positive, finish calculating the solution(s)
    if the quadratic expression is negative, no real solutions exist
    */
    if ( quadraticExpression >= 0) {
        solution1 = (sqrt(quadraticExpression) - b) / (2 * a);
        solution2 = (sqrt(quadraticExpression) + b) / -(2 * a);
        if (solution1 != solution2) {
            printf("There are 2 real solutions\n");
            // if one or more solution is negative, print the more positive solution first
            if (solution1 > solution2 && solution2 < 0) {
                printf("Solution 1: %.2lf\nSolution 2: %.2lf", solution1, solution2);
            } 
            // if the solutions are both positive, print the less positive solution first
            else if (solution1 < solution2 && solution1 > 0) {
                printf("Solution 1: %.2lf\nSolution 2: %.2lf", solution1, solution2);
            }
        } else {
            printf("There is one real solution: %.2lf", solution1);
        }
    } else {
        printf("There are no real solutions");
    }

    return 0;
}