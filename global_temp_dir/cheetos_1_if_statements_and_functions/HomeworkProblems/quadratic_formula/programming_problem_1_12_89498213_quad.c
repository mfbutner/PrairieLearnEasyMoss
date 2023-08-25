#include <stdio.h>
#include <math.h>

int main() { // start of the function
    double a, b, c;// declaring variables that stores floating numbers
    double numbers, numbers1, equation; // Also declaring numbers that are floats

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n\n"); //print output statement that provides the user a prompt to work with
    printf("Please enter a: "); // print statement that gives the user somewhere to type
    scanf("%lf", &a); // input for user
    printf("Please enter b: "); // print statement that gives the user somewhere to type
    scanf("%lf", &b); // input for user
    printf("Please enter c: "); // print statement that gives the user somewhere to type
    scanf("%lf", &c); //input for user


    equation = b * b - 4 * a * c; // needed to put the quadratic equation together in one variable

    if (equation > 0) { // if the value is greater than 0, this statement will be true and execute
        numbers = (-b + sqrt(equation)) / (2*a); // set of commands that will calculate and simplify equation with inputs
        numbers1 = (-b - sqrt(equation)) / (2*a); // since the sign plus or minus is in play, this is needed to make sure all possible solution are printed.

        printf("There are 2 real solutions\n"); // This statement will print if the equation is greater than 0, which will find two real solutions
        printf("Solution 1: %.2f\n", numbers); // The first solutions that is printed
        printf("Solution 2: %.2f\n", numbers1);// The second solutions that is printed after the first one

  }   else if (equation == 0) { // This statement will print of the if statement above does not execute and is not true
        numbers = numbers1 = -b / (2*a); // if there is a solution, loop will continue onwords, otherwise it ends
        printf("There is one real solution: %.2f\n", numbers); // will print if "equation" is equal to 0


    } else { // else statements that serves as a backup in case the else if statement does not execute to the conditions that were given
        printf("There are no real solutions\n"); // prints the output saying that there were no real solution due to the inputs that were given.
    }

    return 0; // program will exit if code is properly executed
}
