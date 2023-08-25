#include <stdio.h>
#include <math.h>

//program will take the users a ,b ,c values from a quadratic function in the form ax^2+bx+c
//and then determine whether there are any real solutions and if there are, the program will provide them
double descriminant(double a, double b,double c){
                                                        //function will calculate the descriminate value
                                                        //function will accept three double type values given by user 
                                                        //function will return the descriminant value    
   double descriminant_val;
    descriminant_val =pow(b,2) - 4 * a * c;
return descriminant_val ;
}






int main(){

double a , b ,c ;

//double descriminant;
double denominator;
double positive_root;
double negative_root;
double descriminant_val;
printf("Given a quadratic equation of the form a*x^2 + b * x + c ");
printf("Please enter a: ");
scanf("%lf", &a);

printf("\nPlease enter b: ");
scanf("%lf", &b);

printf("\nPlease enter c: ");
scanf("%lf", &c);

descriminant_val=descriminant(a,b,c);
denominator= 2*a;

//loops
if (descriminant_val >0){
    printf("There are 2 real solutions ");
  
    
    
    positive_root= (-b+sqrt(descriminant_val))/(denominator);
    negative_root= (-b-sqrt(descriminant_val))/(denominator);

    printf("Solution 1: %.2f", positive_root);
    printf("Solution 2: %.2f", negative_root);
}
else if (descriminant_val ==0 ){

    printf("There is one real solution: ");
    //Positive root and negative root should equal the same thing when descriminant is 0
    
    positive_root= (-b+sqrt(descriminant_val))/(denominator);
    printf("%.2f", positive_root);



}
else {

printf("There are no real solutions");


}





    return 0;
}
