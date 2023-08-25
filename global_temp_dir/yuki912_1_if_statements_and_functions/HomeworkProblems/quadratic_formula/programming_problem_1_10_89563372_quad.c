/*answer the real solutions of the quadratic equations using the quadratic formula */

#include<stdio.h>
#include<math.h>

void calculateEquation (double coefficient_a, double coefficient_b, double constant_c); //Function Declaration

int main(){
    double coefficient_a; //coefficient a of x^2
    double coefficient_b; //cofficient b of x
    double constant_c; //constant c

    printf("Given a quadratic equation of the form a * x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf\n", &coefficient_a);

    printf("Please enter b: ");
    scanf("%lf\n", &coefficient_b);

    printf("Please enter c: ");
    scanf("%lf\n", &constant_c);

    calculateEquation (coefficient_a, coefficient_b, constant_c);
    
    return 0;
}

void calculateEquation (double coefficient_a, double coefficient_b, double constant_c){  //calculate the quadratic equation based on the inputted value.
    double discriminantQuadratic = pow(coefficient_b, 2) - (4 * coefficient_a * constant_c);   //the discriminant of the quadratic equations
    double quadraticFormula_1 = (- coefficient_b + sqrt(discriminantQuadratic)) / (2 * coefficient_a); //the first one of the answers of the equation (the quadratic formula is used)
    double quadraticFormula_2 = (- coefficient_b - sqrt(discriminantQuadratic)) / (2 * coefficient_a); //the second one of the answers of the equation (the quadratic formula is used)

    if (discriminantQuadratic > 0){ //when the value of the discriminant is more than 0, the quadratic equation has 2 real solutions.
        if(((quadraticFormula_1 < 0) && (quadraticFormula_2 > 0)) || ((quadraticFormula_2 < 0) && (quadraticFormula_1 > 0))){
            if(quadraticFormula_1 > quadraticFormula_2){
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_1);
                printf("Solution 2: %.2lf\n", quadraticFormula_2);
            }

            else{
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_2);
                printf("Solution 2: %.2lf\n", quadraticFormula_1);
            }
        }
        else if((quadraticFormula_1 > 0) && (quadraticFormula_2 > 0)){ 
            if(quadraticFormula_1 < quadraticFormula_2){
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_1);
                printf("Solution 2: %.2lf\n", quadraticFormula_2);
            }

            else if(quadraticFormula_1 > quadraticFormula_2){
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_2);
                printf("Solution 2: %.2lf\n", quadraticFormula_1);
            }
        }
        else{
            if(quadraticFormula_1 > quadraticFormula_2){
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_1);
                printf("Solution 2: %.2lf\n", quadraticFormula_2);
            }

            else{
                printf("There are 2 real solutions\n");
                printf("Solution 1: %.2lf\n", quadraticFormula_2);
                printf("Solution 2: %.2lf\n", quadraticFormula_1);
            }
        }
    }

    else if(discriminantQuadratic == 0){ ////when the value of the discriminant is equal to 0, the quadratic equation has 1 real solution.
            printf("There is one real solution: %.2lf\n", quadraticFormula_1);
    }

    else { ////when the value of the discriminant is less than 0, the quadratic equation has no real solution.
            printf("There are no real solutions");
    }
    
}