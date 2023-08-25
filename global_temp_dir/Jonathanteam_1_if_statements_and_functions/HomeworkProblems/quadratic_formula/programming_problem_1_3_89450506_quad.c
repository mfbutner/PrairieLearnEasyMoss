/*this code is use to solve the Quadratic question mainly by "if & else"*/



//header
#include <stdio.h>
#include <math.h>

// use function to calculate determinant value
double CalculateDeterminant (double a , double b , double c ) {
    double d;
    d = b * b - 4.0 * a *c ;
    return d;

}

// main function
int main(){
    double a , b , c , root1 , root2 , root3; //declare variable 
    printf("Given a quadratic equation of the form a *x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf" , &a);
    printf("Please enter b: ");
    scanf("%lf" , &b);
    printf("Please enter c: ");
    scanf("%lf" , &c);

    double Dtm = CalculateDeterminant (a , b , c );

    if (Dtm > 0){

          // calculate root1 and root2
        root1 = (-b + sqrt(Dtm))/(2*a);
        root2 = (-b - sqrt(Dtm))/(2*a);
        printf("There are 2 real solutions");
        printf("\nSolution 1: %.2lf" , root1); // display root1
        printf("\nSolution 2: %.2lf" , root2); //display root2

    }
    //"if" function to determine the number of root by comparing whether d larger than 0

    else if (Dtm == 0){
        root3 =  -b/(2*a);

        printf("There is one real solution: %.2lf" , root3);
    }
    //"else if" function determine when d equal to 0

    else if (Dtm < 0){

        printf("There are no real solutions");
    }
    //"else if" function determine when d less than 0
    return 0;

}//end of program