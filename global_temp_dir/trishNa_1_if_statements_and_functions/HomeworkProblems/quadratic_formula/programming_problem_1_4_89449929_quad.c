/* HW 3.1, Solving Quadratic Formula, by Trishna Basnet :), this program will ask user
for values of a, b, c to find the roots of a quadratic equation using the quadratic 
formula 
*/
#include <stdio.h>
#include <math.h> // math library

int main() {
double a, b, c, solution1, solution2; // number value precision 

printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
// print input statements, lf for double
printf("Please enter a: ");
scanf("%lf", &a);

printf("Please enter b: ");
scanf("%lf", &b);

printf("Please enter c: \n");
scanf("%lf", &c);
// if discriminant of equation is equal to a number over 0, then 
if (b * b-4 * a * c > 0) { // calculations for the solutions/roots
solution1 = (-b + sqrt(b*b-4.*a*c) ) / (2*a);
solution2 = (-b - sqrt(b*b-4.*a*c) ) / (2*a);

//if (solution1 && solution2 != 0) 
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", solution1);
    printf("Solution 2: %.2lf\n", solution2);
// if the discriminant is equal to 0 then 
}else if (b * b-4 * a * c == 0){
    solution1 = solution2 = -b/(2*a);
    printf("There is one real solution: %.2lf\n", solution1);
   \
}// if the answer is anything other then there's no real solutions
else{
    printf("There are no real solutions");
}


return 0;   
}