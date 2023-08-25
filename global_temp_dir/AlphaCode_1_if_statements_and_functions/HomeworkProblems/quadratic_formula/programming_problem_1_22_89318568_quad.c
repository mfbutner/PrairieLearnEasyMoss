#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// This program asks the user for a quadratic equation in the form ax^2 + bx + c. Then it tells the user if there are any solutions. If there were solutions it will display the number of solutions and the solutions 


//This function plugs in the values in a quadratic equation where the discriminant is added.
double quadratic_equation_plus(double b_value, double discriminant, double a_value, double a_value_twice) {
  double solution_1 = (-b_value + discriminant) / (a_value_twice); //b value is the b value entered by the user. Discriminant is calculated by the square root of b - 4 multiplied by a multiplied by c. a value is entered by the user. a value twice is basically 2 times a.
   return solution_1; // solution 1 is basically the first solution. Which is -b + discriminant divided by a value multiplied by 2.If one solution exists only solution 1 will print. 
}//This function plugs in the values in a quadratic equation where the discriminant is subtracted.
double quadratic_equation_minus(double b_value, double discriminant, double a_value, double a_value_twice) {
   double solution_2 =(-b_value - discriminant) / (a_value_twice);//b value is the b value entered by the user. Discriminant is calculated by the square root of b - 4 multiplied by a multiplied by c. a value is entered by the user. a value twice is basically 2 times a.
   return solution_2;// solution 2 is the second solution. Which is -b - discriminant divided by a value multiplied by 2. It will only print if two solutions exist.
}


int main(){
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
    double a_value_twice = a_value * 2;
    double b_squared = pow(b_value ,2);
    double discriminant = sqrt(b_squared - (4*a_value*c_value));
    double solution_1 = quadratic_equation_plus(b_value, discriminant, a_value, a_value_twice);
    double solution_2 = quadratic_equation_minus(b_value, discriminant, a_value, a_value_twice);
    if (discriminant == 0){
        printf(" There is one real solution: %.2lf\n" , solution_1);
    } else if (discriminant > 0){
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n" , solution_1);
        printf("Solution 2: %.2lf\n" , solution_2);
    }

    else{
        printf("There are no real solutions\n");
        
    }
return 0;
}

        