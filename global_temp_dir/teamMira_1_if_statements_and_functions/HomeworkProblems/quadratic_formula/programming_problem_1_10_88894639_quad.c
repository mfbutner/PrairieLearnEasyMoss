// quad.c 
#include <stdio.h>
#include <math.h>

// this program will use quadratic equation to get the roots values of x

// using another function beside main()
// using void as a function retun type with two parameters that will print the values of case 1
void printRoots(double root1, double root2) {
  printf("Solution 1: %.2lf\nSolution 2: %.2lf\n",root1 , root2);
}
int main(){
double a, b, c, discriminant, root1, root2;
// give the user example of the form of a quadratic equation 
printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

// ask the user for the value of a 
printf("Please enter a: ");
scanf("%lf", &a);

// ask the user for the value of b
printf("Please enter b: ");
scanf("%lf", &b);

// ask the user for the value of b
printf("Please enter c: ");
scanf("%lf", &c);

// calculate the discriminant
discriminant =  (pow(b,2) - 4 * a * c);

// calculate root1 and root2
root1 = ((-b + sqrt(discriminant))/(2 * a));
root2 = ((-b - sqrt(discriminant))/(2 * a));

// condition for the 3 possible cases of the roots

if (discriminant > 0){
    // case 1: discriminant is positive number so there is 2 real solution
    printf("There are 2 real solutions\n");
    // print root1 and root2 to user
    printRoots(root1, root2);
}
    else if (discriminant == 0){
    // case 2: discriminant is zero so 1 real solution so root1 = root2 
    printf("There is one real solution: %.2lf\n", root1);

}
// (discriminant < 0)
    else {
    // case 3: discriminant in negative so no real solution
    printf("There are no real solutions\n");

}

return 0; 
}


