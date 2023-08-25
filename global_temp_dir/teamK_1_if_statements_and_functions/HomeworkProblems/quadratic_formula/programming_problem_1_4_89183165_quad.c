#include<stdio.h>
#include<math.h>
/*
This program is designed to  state the number of real roots
a quadratic function has a what those roots are given the 
quadratic equation in the form ax^2 + bx + c. 
*/


/*
This function calculates the discriminant of the quadratic equation
given the parameters a, b, and c, which are all of the double
type and make up the coefficients of each portion of the 
general quadratic equation format ax^2 + bx + c. The function
returns the calculated discriminant given these parameters.
*/
double discriminant(double a, double b, double c)
{
    double discr;

    discr = sqrt((b * b) - (4 * a * c));

    return discr;
}

/*
This function calculates the root involving the plus sign of the
quadratic formula. The formula is (-b + sqrt(b^2 - 4ac))/ 2a given
the parameters a, b, and c which are all of the double
type and make up the coefficients of each portion of the 
general quadratic equation format ax^2 + bx + c. The function returns
the root that involves the plus sign. 
*/
double plusRoot(double a, double b, double c)
{
    double root1;

    root1 = ((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a);

    return root1;
}

/*
This function calculates the root involving the minus sign of the
quadratic formula. The formula is (-b - sqrt(b^2 - 4ac))/ 2a given
the parameters a, b, and c which are all of the double
type and make up the coefficients of each portion of the 
general quadratic equation format ax^2 + bx + c. The function returns
the root that involves the minus sign. 
*/
double minusRoot(double a, double b, double c)
{
    double root2;

    root2 = ((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a);

    return root2;
}

/*
This function prints how many solutions there are(if there are any),
and what those solutions are based on if 
the discriminant is greater than, equal to
or less than 0. If there are no solutions, 
it states that. The parameters are a, b, and c, which are 
all of the double type and make up the coefficients of each
portion of the  general quadratic equation format ax^2 + bx + c. 
The function does not return anything, but prints statements when called.
*/
void solPrinter(double a, double b, double c)
{
    if (discriminant(a, b, c) > 0)
    {
        printf("There are 2 real solutions\n");
        printf("\nSolution 1: %.2lf\n", plusRoot(a, b, c));
        printf("\nSolution 2: %.2lf\n", minusRoot(a, b, c));
    }
    else if (discriminant(a, b, c) == 0)
    {
        printf("There is one real solution: %.2lf", plusRoot(a, b, c));
    }
    else
    {
        printf("\nThere are no real solutions");
    }

}


int main()
{
    double a;
    double b;
    double c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c");

    printf("\nPlease enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);

    solPrinter(a, b, c);

    return 0;

}