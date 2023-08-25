#include <stdio.h>
#include <math.h>
/*

this program finds how many solutions a quadratic function has and what 
those solutions are if it has any

*/

/*
discriminant is stored double and i entered its formula (b * b) - 4 * a * c and it returns d
in order to use it later for the print statements
*/

double discrim(double a, double b, double c) {
    double d = (b * b) - 4 * a * c;
    return d;
}


/*
quadratic formula has to have a,b,c and d passed through it
*/
double* quadform(double a, double b, double c, double d) {  /* storing a,b,c,d as doubles */
    static double solutions[2];   /* stored solutions as a static and use indexing  */
    if (d > 0) {   /* 2 real solutions */
        solutions[0] = (-b + sqrt(d)) / (2 * a);  /* separate the plus and the minus for the quadratic formula */
        solutions[1] = (-b - sqrt(d)) / (2 * a);
        return solutions;
    } 
    else if (d == 0) {  /* only one real solution  */
        solutions[0] = (-b) / (2 * a);  
        return solutions;
    } 
    else {
        return NULL;  /* if there are no real solutions, return nothing */
    }
}

int main() {  /*  main function that gets user input and prints the final solutions */
    double a, b, c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    double d = discrim(a, b, c);   
    double * solutions = quadform(a, b, c, d);
    if (solutions == NULL) {   /* prints how many solutions and what the values are  */
        printf("There are no real solutions");
    } else if (solutions[1] == 0) { 
        printf("There is one real solution: %.2lf", solutions[0]);
    } else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solutions[0]);
        printf("Solution 2: %.2lf", solutions[1]);
    }
    return 0;
}
