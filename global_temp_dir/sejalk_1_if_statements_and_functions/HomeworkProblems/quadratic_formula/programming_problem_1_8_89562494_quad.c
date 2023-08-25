/*
    This program has one function other than the main which is numSolutions. This 
    function returns the number of solutions these quadratic equation will have 
    given the a, b, and c values. The number of solutions is calculated using
    b^2 - 4ac. Given the number of solutions the solutions are calculated. If 
    there are no solutions, a statement is printed. If there is one solution 
    they will calculate one and display it to the user. If there are two solutions,
    both will be calculated and displayed to the user.
*/
#include <stdio.h>
#include <math.h>

/*
    This function returns the number of solutions a quadratic equation will have.
    The parameters for this fuction are the a, b, and c values of the equation.
    The function calculates the number of solutions using the equation b^2 -4ac. 
    @param a: a value of the quadratic equation
    @param b: b value of the quadratic equation
    @param c: c value of the quadratic equation
    @return: the number of solutions that the quadratic equation will have
*/
double numSolutions(double a, double b, double c){
    double num = pow(b, 2.0) - (4 * a * c);
    if(num > 0){
        return 2;
    } else if(num == 0){
        return 1;
    } else {
        return 0;
    }
}

/*
    In this function, the users will be prompted for the a, b, and c values for the 
    quadratic equation. A variable stores the value returned from the numSolutions 
    function. Then the number is checked and based on it the corresponding statements 
    are printed. If there are one or two solutions, then the solution(s) are calculated
    and printed. 
*/
int main(){
    double a;
    double b;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    int numSols = numSolutions(a, b, c);
    if(numSols == 0){
        printf("There are no real solutions\n");
    } else if(numSols == 1){
        double sol = (double)((-b)/(2 * a));
        printf("There is one real solution: %.2f\n", sol);
    } else if(numSols == 2){
        double sol1 = (double)(((-b) + sqrt(pow(b, 2.0) - (4 * a * c)))/(2 * a));
        double sol2 = (double)(((-b) - sqrt(pow(b, 2.0) - (4 * a * c)))/(2 * a));
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", sol1);
        printf("Solution 2: %.2f\n", sol2);
    }
    return 0;
}

