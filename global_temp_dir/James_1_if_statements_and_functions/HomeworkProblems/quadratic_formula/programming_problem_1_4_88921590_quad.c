#include <stdio.h>
#include <math.h>
double plusquad(double a, double b, double c){
    double x;

    x = (-b+pow(pow(b,2)-4*a*c,0.5))/(2*a);
    return x;
}
double minusquad(double a, double b, double c){
    double y;

    y = (-b-pow(pow(b,2)-4*a*c,0.5))/(2*a);
    return y;
}
int main(void) {
    double a;
    double b;
    double c;
    double root1;
    double root2;
    


    
    
   
    printf("Given a quadratic equation of the form a*x^2 + b * x +c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);

    printf("Please enter b: ");
    scanf("%lf", &b);

    printf("Please enter c: ");
    scanf("%lf", &c);
    
    root1 = plusquad(a,b,c);
    root2 = minusquad(a,b,c);
    

    
    if(root1==root2){
        printf("There is one real solution: %.2lf", root1);
    }
    else if(fabs(root1)>=0 && fabs(root2)>=0){
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", root1);
        printf("Solution 2: %.2lf", root2);
    }
    else if(fabs(root1)>=0){
        printf("There is one real solution: %.2lf", root1);
    }
    else if(fabs(root2)>=0){
        printf("There is one real solution: %.2lf", root2);
    }
    else{
        printf("There are no real solutions");
    }
  
    
    

    return 0;

    
}