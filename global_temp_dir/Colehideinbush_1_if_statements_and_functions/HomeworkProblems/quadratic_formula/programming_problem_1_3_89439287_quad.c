#include <stdio.h>
#include <math.h>

int main() {
    
    double a, b, c;
    
    double CheckRoot, Root1, Root2;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    
    scanf("%lf", &a);
    
    printf("Please enter b: ");
    
    scanf("%lf", &b);
    
    printf("Please enter c: ");
    
    scanf("%lf", &c);


    CheckRoot = b * b - 4 * a * c;

    if (CheckRoot > 0) {
        Root1 = (-b + sqrt(CheckRoot)) / (2 * a);
        Root2 = (-b - sqrt(CheckRoot)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f", Root1);
        printf("\nSolution 2: %.2f", Root2);
    }
    
    if (CheckRoot == 0) {
        Root1 = Root2 = -b / (2 * a);
        printf("There is one real solution: %.2f", Root1);
    } 
    
    
    if (CheckRoot < 0) {
        printf("There are no real solutions");
    }

    return 0;
}