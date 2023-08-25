#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 this program gets an a value, a b value, and a c value from the user and evaluates the quadratic formula
 it tells the user if there are no real solutions, one real solution, or two real solutions and says what they are
 */

// x = (-b + sqrt(b^2 - 4*a*c)/2*a)
// x = (-b - sqrt(b^2 - 4*a*c)/2*a)


void print_two_solutions(double solution1, double solution2){
    /**
     *this function prints out the two solutions in the correct order depending on the values
     *@param solution1 is the first solution to be evaluated
     *@param solution2 is the second solution to be evaluated
     *@return void
     */
    if (solution1 >= 0 && solution2 >= 0) {
        //checks which solution is positive and prints the positive solution first
        //if positive just print
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf", solution2);
    }
    else {
        //if both negatives, print the bigger of the two
        if(solution1 > solution2) {
            printf("Solution 1: %.2lf\n", solution1);
            printf("Solution 2: %.2lf", solution2);
        }
        else {
            printf("Solution 1: %.2lf\n", solution2);
            printf("Solution 2: %.2lf", solution1);
        }
        }
}

int calculate_solution(double a, double b, double c) {
    /**
     *this function calculates the components of the quadratic equation and prints out the results
     *@param a holds the a value that the user inputs
     *@param b hold the b value that the user inputs
     *@param c holds the c value that the user inputs
     *@returnthis function doesn't return anything
     */
    double pos_numerator;
    double neg_numerator;
    double rooted_value;
    double negative_rooted_value;
    double solution1 = 9.0;
    double solution2 = 9.0;
    
    double denominator = 2.0 * a;
    double inside_root_value = (pow(b, 2)) - (4.0 * a * c);
    if (inside_root_value < 0) {
        //a negative number means there are no real number solutions
        printf("There are no real solutions");
    }
    else {
        if (inside_root_value == 0) {
            //a zero in the root means that there is only one real solution
            solution1 = -b / denominator;
            printf("There is one real solution: ");
            printf("%.2lf", solution1);
        }
        else {
            printf("There are 2 real solutions\n");
            rooted_value = sqrt(inside_root_value);
            negative_rooted_value = -1 * rooted_value;
            //the equation is plus or minus so have a positive and a negative value
            //alternativatively could add and subtract ...
            pos_numerator = -b + rooted_value;
            neg_numerator = -b + negative_rooted_value;
            solution1 = pos_numerator / denominator;
            solution2 = neg_numerator / denominator;
            print_two_solutions(solution1, solution2);
        }
    }
    return 0;
}

int main() {
    //this main function gets the user input and runs the calculation function
    double a_value;
    double b_value;
    double c_value;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a_value);
    printf("Please enter b: ");
    scanf("%lf", &b_value);
    printf("Please enter c: ");
    scanf("%lf", &c_value);

    calculate_solution(a_value, b_value, c_value);
    return 0;
}

