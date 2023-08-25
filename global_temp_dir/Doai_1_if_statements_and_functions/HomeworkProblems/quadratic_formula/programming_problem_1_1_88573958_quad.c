#include <stdio.h>
#include <math.h>

double input(char coef);
double calc_discriminant(double a, double b, double c);
double calc_solution(double a, double b, double discriminant);

int main(void)
{
    // Ask for inputs from users.
    // Step 1
    double a, b, c, discriminant, first_sol, second_sol;
    printf("Given a quadratic equation of the form ax^2 + b x + c\n");
    a = input('a');
    b = input('b');
    c = input('c');

    // Calculate the discriminant to find how many real solutions are available.
    // Step 2
    discriminant = calc_discriminant(a, b, c);

    // Calculate the solutions if there discriminant >= 0.
    // Calculate and print the result(s).
    // Step 3 & 4

    // One solution.
    if (discriminant == 0)
    {
        first_sol = calc_solution(a, b, discriminant);
        printf("\nThere is one real solution: %.2lf\n", first_sol);
    }
    // 2 real solutions.
    else if (discriminant > 0)
    {
        first_sol = calc_solution(a, b, discriminant);
        second_sol = calc_solution(a, b, -discriminant);
        printf("\nThere are 2 real solutions\n");
        printf("\nSolution 1: %.2lf\n", first_sol);
        printf("\nSolution 2: %.2lf\n", second_sol);
    }
    // No real solutions.
    else
    {
        printf("\nThere are no real solutions\n");
    }
    
    return 0;
}


// Function to take the input
// take argument char for the correspsoning coefficient.
double input(char coef)
{
    double value;
    printf("\nPlease enter %c: ", coef);
    scanf("%lf", &value);
    return value;
}

// Find the discriminant sqrt(b^2 - 4ac).
// Arguments are the coefs of the equation.
double calc_discriminant(double a, double b, double c)
{
    return sqrt(b * b - 4 * a * c);
}

// Calculate teh solution using the formula provided.
// Arguments are the component needed to use the formula
double calc_solution(double a, double b, double discriminant)
{
    return (- b + discriminant) / (2 * a);
}