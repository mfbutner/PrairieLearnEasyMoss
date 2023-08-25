#include <stdio.h>
#include <math.h>

//change the name or the variable not just - or +  
//if want  to get a value of a function need to return a thing

double discriminant(double a ,double b ,double c){
    double equation =  (pow(b,2)-4*a*c) ;
    return equation;
}

//double quadratic(int a ,int b ,int c,double x){
   // double qequation(a*(pow(x,2)))+(b*x)+c ;}

int main(void) {
    double a,b,c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf ("%lf",&a);
    printf("Please enter b: ");
    scanf ("%lf",&b);
    printf("Please enter c: ");
    scanf ("%lf",&c);

    //x equation= (-b +- squartroot  ((b^2)-4ac))/2a
    //quadratic equation = (a*x^2） +（b*X)+C  (a*(pow(x,2)))+(b*x)+c ;

    //double function (int a ,int b ,int c )
    double functionp = (-b + sqrt((pow(b,2)-4*a*c))) /(2*a) ;
    double functionm = (-b - sqrt((pow(b,2)-4*a*c))) /(2*a) ;
    //printf("%lf",functionp);


    double equation = discriminant(a,b,c);
    if(equation <0){
        printf("There are no real solutions\n");
    } else if(equation >0){
        printf("There are 2 real solutions\n");
		printf("Solution 1 :%.2f\n",functionp );
		printf("Solution 2 :%.2f\n",functionm);

    }else{
        printf("There is one real solution:%.2f\n",functionp );

    }
    return 0 ;

}



// type a ,b , c  ,than calculate the x  than we use the formula to calculate the equation  
// we calculate the x by using the  quadratic equation  first than we use x to solve the equation 
