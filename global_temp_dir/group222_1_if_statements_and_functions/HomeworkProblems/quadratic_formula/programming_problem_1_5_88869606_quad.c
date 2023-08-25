
#include <stdio.h>
#include <math.h>
/* this program finds the real solutions for quadratic functions in the form of ax^2 +bx + c =0
*/
double Discriminant(double a, double b, double c){ //finds the discriminant of the quadratic function
    double d = (b * b)- (4 * a * c); //d is short for discriminant
    if (d<0){
        return -1; //returns -1 when unreal, only possible negative return
    }
    else if (d==0) {
        return 0; //returns 0 if only one real solution
    }
    else {
        return d; //returns the discriminant for further solving later if 2 real solutions present
    }

}

int main()
{ //main function for asking for user input, and displaying solutions as output.
    double a,b,c;
    double solution1, solution2;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
scanf(" %lf", &a);
printf("Please enter b: ");
scanf(" %lf", &b);
printf("Please enter c: ");
scanf(" %lf", &c);
double Discrim= Discriminant(a,b,c); //short for discriminant, so doesnt get confused with Discriminant function
if (Discrim<0){
    printf("There are no real solutions\n");
}
else if (Discrim==0){
    solution1= -b/(2*a);
    printf("There is one real solution: %.2f\n", solution1);
}
else {
    solution1= (-b + pow(Discrim,0.5) ) /(2 * a);
    solution2= (-b - pow(Discrim,0.5) )/(2 * a);
     printf("There are 2 real solutions\n");
     printf("Solution 1: %.2f\nSolution 2: %.2f\n", solution1,solution2);
}

    return 0;
}
