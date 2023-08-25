/* Author: Nicolás Kennedy
 * Filename: quad.c
 * Description:
 *  This program takes three double values from standard in, which correspond to the three coefficients of a general quadratic formula when equated to 0: ax^2 + bx + c = 0; Then, the program computes the real roots of this equation, and outputs the roots if they exist. If roots are imaginary, then the program will output that no real roots exist.
 *
 */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>


/* I do not like working with null values, so I created a struct that
 * stores two options: either it contains something and an associated
 * value, or it contains nothing.
 */
enum OptionChoice {OPTION_SOME, OPTION_NONE};

struct Option {
    enum OptionChoice exists;
    double value;
};

/* All Option structs are initialised with "NONE," and the value is
 * left undefined. This function takes the following arguments: a
 * pointer to an Option struct, and an integer representing the
 * number of sequential Option structs in memory that the first
 * argument points to.
 * This function does not return a value.
 */
void option_init(struct Option* options, int num)
{
    for (int i = 0; i < num; ++i)
    {
        options[i].exists = OPTION_NONE;
    }
}

/* This function computes the roots of a quadratic equation. The
 * coefficients of the quadratic equation are given in the first
 * three arguments: the quadratic term has coefficient "a," the
 * linear term has coefficient "b," and the constant term has
 * coefficient "c." The fourth argument of the function is a pointer
 * to an array of two Option structs, which store the two possible
 * roots of the quadratic equation. The function modifies this array
 * and sets it to the roots of the quadratic equation if such roots
 * exist.
 * This function does not return a value.
 */
void compute_roots(double a, double b, double c, struct Option roots[])
{
    if (pow(b, 2) - 4 * a * c >= 0)
    {
        roots[0].exists = OPTION_SOME;
        roots[0].value = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

        double lower_root = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        if (lower_root != roots[0].value)
        {
            roots[1].exists = OPTION_SOME;
            roots[1].value = lower_root;
        }
    }
}

/* This is the main function and it is the entry point to the program; that is, this is the function that is first run when the program is executed. It returns a "return code" which tells the operating system the resulting status of the program's execution. This program will always output "0," telling the operating system that execution was successful, if the program is successfully executed.
 */
int main()
{
    struct Option roots[2];
    option_init(roots, 2);

    int num_solutions = 0;
    double a, b, c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf(" %lf", &a);

    printf("Please enter b: ");
    scanf(" %lf", &b);

    printf("Please enter c: ");
    scanf(" %lf", &c);

    compute_roots(a, b, c, roots);

    if (roots[0].exists == OPTION_SOME)
    {
        ++num_solutions;
    }
    if (roots[1].exists == OPTION_SOME)
    {
        ++num_solutions;
    }

    if (num_solutions == 0)
    {
        printf("There are no real solutions\n");
    }
    else if (num_solutions == 1)
    {
        printf("There is one real solution: %.2lf\n", roots[0].value);
    }
    else if (num_solutions == 2)
    {
        printf("There are 2 real solutions\n");

        for (int i = 0; i < 2; ++i)
        {
            printf("Solution %d: %.2lf\n", i + 1, roots[i].value);
        }
    }

    return 0;
}
