#include<stdio.h>
#include <math.h>


double take_inputs(char * letter){
    double value;
    printf("Please enter %s: ", letter);
    scanf("%lf", &value);
    return value;
}

double discriminant_calculations(double a, double b, double c){
    double discriminant;
    discriminant = pow(b,2)-(4*a*c);
    return discriminant;
}

double positive_root_calcualations(double a, double b, double c, double discriminant){
    double root;
    root = (-b + sqrt(discriminant))/(2*a);
    return root;
}

double negative_root_calcualations(double a, double b, double c, double discriminant){
    double root;
    root = (-b - sqrt(discriminant))/(2*a);
    return root;
}


int main(){
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    double a = take_inputs("a");
    double b = take_inputs("b");
    double c = take_inputs("c");
    double discriminant = discriminant_calculations(a,b,c);
    if (discriminant>0){
        double positive_root = positive_root_calcualations(a,b,c,discriminant);
        double negative_root = negative_root_calcualations(a,b,c,discriminant);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", positive_root);
        printf("Solution 2: %.2lf", negative_root);
    
    }   else if (discriminant==0){
        double positive_root = positive_root_calcualations(a,b,c,discriminant);
        printf("There is one real solution: %.2lf", positive_root);

    }   else if (discriminant<0){
        printf("There are no real solutions");
    }
    

}

