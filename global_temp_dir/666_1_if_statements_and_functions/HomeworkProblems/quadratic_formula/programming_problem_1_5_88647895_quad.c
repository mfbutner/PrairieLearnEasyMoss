#include <stdio.h>
#include <math.h>

//calculate the delta value to see how many solution there are.
//parameter: double a,b,c from a quadratic equation a*x^2 + b * x + c
//return the delta value
double getDelta(double a, double b, double c){
    return pow(b, 2) - 4 * a * c; 
}

//calculate the quadradic equation using equation provided
//parameter: double a,b,c from a quadratic equation a*x^2 + b * x + c
//parameter: since there are two type of equaion, use a char sign('+' or '-') to return different solution
//return the calculating result. return 0.0 for sign typo
double quadCalc(double a, double b, double c, char sign){
    //if the sign is '+', return the + solution
    if (sign == '+')
    {
        return (-b + sqrt(getDelta(a,b,c)))/(2*a);
    }
    //if the sign is '-', return the - solution
    else if (sign == '-')
    {return (-b - sqrt(getDelta(a,b,c)))/(2*a);}
    //return 0 for sign typo
    else{return 0.0;}

}

//main function to run code
int main(){
    //double a,b,c from a quadratic equation a*x^2 + b * x + c
    //double delta to store the delta value
    //double solution1 and solution2 to store the result value
    double a,b,c, delta, solution1,solution2;    

    //states the instruction and ask users for a,b,c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    //calculate and store the delta value
    delta = getDelta(a,b,c);

    //if delta is 0, there is only on solution. So use solution 1 only
    if(delta == 0){
        solution1 = quadCalc(a,b,c,'+');
        printf("There is one real solution: %.2lf\n", solution1);
    }

    //if delta is greater than 0, there are 2 solutions. Use quadCalc with different sign(+/-) and store them in solution 1 and 2.
    if(delta > 0){
        solution1 = quadCalc(a,b,c,'+');
        solution2 = quadCalc(a,b,c,'-');
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }

    //if delta is less than 0, there are no solution. no need to calculate
    if(delta < 0){
    printf("There are no real solutions\n");}
    
    //return 0 for the main function
    return 0;
}