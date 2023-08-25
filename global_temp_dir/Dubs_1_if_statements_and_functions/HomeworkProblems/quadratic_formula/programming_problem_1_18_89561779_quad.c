//Names: Jonathan Mitelman Aryan Karnwal
//this program takes 3 inputted A,B and C values and plugs them into the quadtratic formula.
// If the root is >0 it will print both solutions, if its =0 it prints the single solution and if its less <0 then it explains how it has no solutions.

#include <stdio.h>
#include <math.h>
// this function takes the square root of the root value and prints the 2 solutions available. it takes said values from the main int function
void square_root(float root, double a, double b, double c) {
       float negative_root, positive_root;

        root = sqrt(root);
        positive_root = (-b - (root)) / (2 * a);
        negative_root = (-b + (root)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", negative_root);
        printf("Solution 2: %.2f\n", positive_root);
}
// this function is responsible for calculating the values of a,b and c and then  soling for one real solution or finding out if it has no solutions. 
//It is also calculates 2 solutions through sending it to the other function.
int main()
{
   double a,b,c;
   float root;



    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    root = b * b - 4 * a * c;
        if (root > 0){
        square_root(root,  a,  b, c);
        }
        else if (root == 0){
               root = -b/(2*a);
               printf("There is one real solution: %.2f\n", root);

        }
        else{
            printf("There are no real solutions\n");
        }
return 0;
}





