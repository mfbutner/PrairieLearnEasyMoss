#include <math.h>
#include <stdio.h>
//This program gets a, b, and c values in a quadratic equation and solves it 


/*Checks to see if it a perfect square. This is achieved by seeing if the discriminant is 0
Also checks if the roots will be positive or negative, returns a character depending on what
it finds. p for positive, n for negative, z for zero.
The parameters are all doubles and are simply the a, b, and c values the user inputted*/
char disCheck(double a, double b, double c){
double dis = b*b - 4*a*c;
if (dis == 0){
    return 'z';
}
else if (dis > 0){
    return 'p';
}
else{
    return 'n';
}

}
/*This is where we get the users input and actually do the math. We used our disCheck function
to check the discriminant and proceed with our print statements from there based on the result*/
int main(){
double a, b, c = 0.0;
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf(" %lf", &a);
printf("Please enter b: ");
scanf(" %lf", &b);
printf("Please enter c: ");
scanf(" %lf", &c);
double dis = sqrt(b*b - 4*a*c);
if (disCheck(a,b,c) == 'z'){
    printf("There is one real solution: %.2lf\n", -b/(2*a) );
}
else if (disCheck(a,b,c) == 'p'){
    printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", (-b + dis)/(2*a), (-b - dis)/(2*a));
}
else {
    printf("There are no real solutions\n");
}



}