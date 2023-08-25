#include <stdio.h>
#include <math.h>


int main (void) {
double a, b, c, x1, x2;
int delt;

printf ("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf ("Please enter a: ");
scanf ("%lf", &a);
printf ("Please enter b: ");
scanf ("%lf", &b);
printf ("Please enter c: ");
scanf ("%lf", &c);
delt=(b*b-4*a*c);
if(delt>0){
   x1=(-b+sqrt(delt))/(2*a);
   x2=(-b-sqrt(delt))/(2*a);
    printf ("There are 2 real solutions\n");
    printf ("Solution 1:%0.2lf\n",x1);
    printf ("Solution 2:%0.2lf\n",x2);

}
else if(delt<0){
  printf("There are no real solutions\n");
}
else{
  x1=(-b+sqrt(delt))/(2*a);
  printf ("There is one real solution: %0.2lf\n",x1);

}
return 0;
}
