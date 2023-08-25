/*This assignemnt outputs the number of solutions that exist from the user input of a,b,c using the quadratic formula
If the discriminant (bsquared - 4*a*c) is negative, then there are no real solutions,
if the discriminant is zero then there is one real solution.
If the discriminant is positive then there are two real solutions */
#include <stdio.h> //need for output and input
#include <math.h> //so i can use the pow function

//up here are the function declarations so i can define them wherever it makes sense for me
double get_coefficient(char coefficient_name); // makes a function for a,b,c to reduce lines of code
int get_num_solutions(double a, double b, double c); //get num solutions based on how many solutions there are
double only_1_solution(double a, double b); // separate functions for each
double solution_1_add_discrim(double a, double b, double c); // add discrim
double solution_2_subtract_discrim(double a, double b, double c); //subtract discrim

double get_coefficient(char coefficient_name){ 
    double coefficient_value = 0; // need a local variable 
    printf("Please enter %c: ", coefficient_name);  // as many variables as placeholders... a b c
    scanf("%lf", &coefficient_value); //lets user input value for a,b,c
    return coefficient_value;
}

int get_num_solutions(double a, double b, double c){ 
int num_solutions = 0; //declaring local variable num solutions because want to use it in output to determine num solutions. 
double first_part_discrim = pow(b, 2);
double second_part_discrim = 4.0 * a * c;
double discrim_result = first_part_discrim - second_part_discrim; //separating my discriminant to result in fewer errors
double discrim_result_precise_checker = fabs(discrim_result); 

if (discrim_result_precise_checker <= 0.00001){ //to reduce rounding error 
    num_solutions = 1; // because if discriminant is negative here are no real solutions
} else if (discrim_result == 0) {
    num_solutions = 0; //only one solution in this case
} else if (discrim_result > 0) {
    num_solutions = 2; // because plus or minus the square root of discriminant
}
return num_solutions; 
}
// no double c here, delete C elsewhere later on.. int c not used here.
double only_1_solution(double a, double b){
    double calc_only_1_solution = (-1 * b) / (2 * a);
//only one solution if discriminant is zero
return calc_only_1_solution; //return the value of the solution. 
}

double solution_1_add_discrim(double a, double b, double c){
    //check whether double or int matters
    double discrim_interior = pow(b,2) - (4.0*a*c);
    double discrim_numerator = (-1 * b) + sqrt(discrim_interior);
    double discrim_denominator = (2*a);
    double discrim_result_adding = discrim_numerator / discrim_denominator;
    return discrim_result_adding; //return the result 
}

double solution_2_subtract_discrim(double a, double b, double c){
    //check whether double or int matters
    double discrim_interior = pow(b,2) - (4.0*a*c);
    double discrim_numerator = (-1 * b) - sqrt(discrim_interior);
    double discrim_denominator = (2*a);
    double discrim_result_subtracting = discrim_numerator / discrim_denominator;
    return discrim_result_subtracting; //return the result
}


int main() {
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
double a = get_coefficient('a'); // value of return coefficient_value the user input for A gets stored here 
double b = get_coefficient('b'); //same thing as above
double c = get_coefficient('c'); //same thing as above. 
//function calls up here. pass in the character. a b c, get return values for what the user inputed. 

int output_num_solutions = get_num_solutions(a,b,c); // stores return value of num solutions

double only_1_solution_output = only_1_solution(a,b); //stores value of the function call
double output_solution_1_add_discrim = solution_1_add_discrim(a,b,c); //same thing
double output_solution_2_subtract_discrim = solution_2_subtract_discrim(a,b,c); //same thing again

if (output_num_solutions == 0){
    printf("There are no real solutions");
} else if (output_num_solutions == 1) {
    printf("There is one real solution: %.2lf", only_1_solution_output);
} else if (output_num_solutions == 2) {
    printf("There are 2 real solutions\n Solution 1: %.2lf\n Solution 2: %.2lf\n", output_solution_1_add_discrim, output_solution_2_subtract_discrim);
}

}