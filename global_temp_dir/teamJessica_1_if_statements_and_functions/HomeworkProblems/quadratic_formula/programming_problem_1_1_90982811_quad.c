#include <stdio.h>
#include <math.h>
/*This program takes the users input for the values of a, b, and c of the quadratic equation in order to then calculate
if there are 0, 1, or 2 real solutions. The program then displays to the user if there are any real roots, and what they are */

double calculate_real_roots_of_x(int solution_number, double constant_a, double constant_b, double constant_c) {
    /*This function uses the quadratic equation in order to calculate the real roots of x, depending on how my real solutions the quadratic equation
    and returns the first and/or second solution of the quadratic equation*/ 
    /*
    solution_number: The number of the solution of the qudratic formula
    constant_a: The value of a of the quadratic equation given by the user
    constant_b: The value of b of the quadratic equation given by the user
    constant_c: The values of c of the quadratic equation given by the user 
    */
    
    
    if(solution_number == 1){
        return ((-constant_b + sqrt((constant_b * constant_b) - (4 * constant_a * constant_c))) / (2 * constant_a));
    }else {
        return ((-constant_b - sqrt((constant_b * constant_b) - (4 * constant_a * constant_c))) / (2 * constant_a));
    }
    return 0;
}



double display_real_solutions(int number_of_real_solutions, double constant_a, double constant_b, double constant_c) {
    /* This function displays to the user the number of real solutions of the quadratic formula and
    what those real solution are if any.
    This function returns nothing.*/
    /*
    number_of_real_solutions: The number of real solutions the quadratic equation has
    constant_a: The value of a of the quadratic equation given by the user
    constant_b: The value of b of the quadratic equation given by the user
    constant_c: The values of c of the quadratic equation given by the user 
    */
    
    
    int solution_number;

    if(number_of_real_solutions == 0){
        printf("There are no real solutions\n");
    }else if(number_of_real_solutions == 1){
        solution_number = 1;
        printf("There is one real solution: %.2lf\n", calculate_real_roots_of_x( solution_number,  constant_a,  constant_b,  constant_c));
    }else{
        printf("There are 2 real solutions \n");
        
        solution_number = 1;
        printf("Solution 1: %.2lf\n", calculate_real_roots_of_x( solution_number,  constant_a,  constant_b,  constant_c));
        
        solution_number = 2;
        printf("Solution 2: %.2lf\n", calculate_real_roots_of_x( solution_number,  constant_a,  constant_b,  constant_c));
    }
    return 0;
} 


double get_num_of_real_solutions(double constant_a, double constant_b, double constant_c){
    /*This function calculates the number of real solutions the quadratic equation has, based off of the value of 
    the discriminant with the given values of a, b, and c. Based on the number of real solutions calculated, the function 
    display_real_solutions is called with the number of real solutions calculated and the values of a, b, and c.
    This function returns nothing.  */
    /*
    constant_a: The value of a of the quadratic equation given by the user
    constant_b: The value of b of the quadratic equation given by the user
    constant_c: The values of c of the quadratic equation given by the user 
    */
    int number_of_real_solutions;
    double discriminant_of_quad_formula;


    discriminant_of_quad_formula = (constant_b * constant_b) - (4 * constant_a * constant_c);

    if(discriminant_of_quad_formula < 0){
        number_of_real_solutions = 0;
        display_real_solutions(number_of_real_solutions, constant_a, constant_b, constant_c);
    }else if (discriminant_of_quad_formula == 0){
        number_of_real_solutions = 1;
        display_real_solutions(number_of_real_solutions, constant_a, constant_b, constant_c);
    }else {
        number_of_real_solutions = 2;
        display_real_solutions(number_of_real_solutions, constant_a, constant_b, constant_c);
    }

return 0;
}

int main() {
    /*This function asks for and recieves the input values for the constants a, b, and c of the quadratic equation
    in order to then use them to call the function get_num_of_real_solutions with the constants as parameters. 
    This function returns nothing.*/

    double constant_a; 
    double constant_b; 
    double constant_c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf("%lf", &constant_a);
    
    printf("Please enter b: ");
    scanf("%lf", &constant_b);
    
    
    printf("Please enter c: ");
    scanf("%lf", &constant_c);
    

    get_num_of_real_solutions(constant_a, constant_b, constant_c);

    return 0;

}
