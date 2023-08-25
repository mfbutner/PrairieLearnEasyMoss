#include<stdio.h>
#include<math.h>

    void quadractic_Function() {
        double a,b,c; //These are the variables used in the equation.
        double x1,x2; /*This is the final value of quadraction equation. 
        *You need two because there are two formula variations + and -.*/
        double sq_rt; //b^2 - 4ac
        double num_erator; //-b +/- y
        double deno_minator; // 2 * a

        printf("Given a quadratic equation of the form a*x^2+ b*x +c\n");

        printf("Please enter a: ");
        scanf("%lf",&a);

        printf("Please enter b: ");
        scanf("%lf",&b);

        printf("Please enter c: ");
        scanf("%lf",&c);

        sq_rt = sqrt(pow(b,2) - 4 * a * c); //The formula in the square rood (b^2 - 4ac).
        num_erator = -b; //The reason i kept assigned -b a different varibale is because i need to use two different time in x1 and x2.
        deno_minator = 2 * a; //The formula 2a for quadratic eqation.
        x1 = (num_erator + sq_rt) / deno_minator; 
        x2 = (num_erator - sq_rt) / deno_minator;
        if (x1 == x2){
        printf("There is one real solution: %.2lf", x1); 
        } else if ((pow(b,2) - 4 * a * c) < 0){ /*The reason for this else if statment is because
         when you put in the value 4,3,7 from the example you get nan as the answer, which means Not a number. Because you can't have negative value in square root, so hence it will give nan.  */
            printf("There are no real solutions\n");
        } else {
            printf("There are 2 real solutions \nSolution 1: %.2lf \nSolution 2: %.2lf", x1, x2);
        } 

    }
    int main(void) {

        quadractic_Function();
        return 0;
    }
