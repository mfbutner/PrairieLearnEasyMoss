#include <stdio.h>
#include <math.h>


int main() {
// This will introduce the quadratic equation to the user.
printf("Given a quadratic equation of the form a*x^2 + b * x + c");

// a, b, and c can be floating numbers and we use "double" to make it more accurate.
// Solution1 and Solution2 are the solutions when determinants > 0. 
// Solution1 and Solution2 can also be floating numbers.
// After we define variables, we ask the user to input a, b, and c.
double a, b, c, Solution1, Solution2;

printf("\nPlease enter a: ");
scanf("%lf", &a);

printf("\nPlease enter b: ");
scanf("%lf", &b);

printf("\nPlease enter c: ");
scanf("%lf", &c);

// Determinant is the definition of b^2-4*a*c
// We should also use "double" to make it more accurate.
double Determinant = pow(b,2) - 4*a*c ;

// We will if..else if..else statement to determine the numbers of solutions
// Determinant can be bigger, smaller, or zero.
if(Determinant > 0){
    Solution1 = (-b + sqrt(Determinant)) / (2*a);
    Solution2 = (-b - sqrt(Determinant))/ (2*a);
    printf("There are 2 real solutions\n");
    printf("Solution 1: %0.2lf\n", Solution1); // Solution1 and Solution2 are precise to two decimals
    printf("Solution 2: %0.2lf\n", Solution2);}

else if(Determinant < 0){
    printf("There are no real solutions");
}  

// if the determinant is zero, then there is only one solution
else{
    Solution1 = (-b) / (2 * a) ; 
    printf("There is one real solution: %0.2lf\n", Solution1);}
}
    
