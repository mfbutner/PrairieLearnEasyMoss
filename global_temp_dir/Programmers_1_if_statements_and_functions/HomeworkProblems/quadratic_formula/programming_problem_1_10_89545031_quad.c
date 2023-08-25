 #include <stdio.h>
 #include <math.h>
  /* This program helps you get the real roots of the quadratic formula. It asks you to input a b c and then it calculates 
  the discrminant which it uses to determine the number of solution and display the real roots to you */
     
     
     //This takes the determinant and uses it to find real roots. the parameters are the values of the quadratic eqn a+b+c
    void quadratic_equation(double a, double b, double c){
    double discrminant;
    double formula_1a;
    double formula_1b;
    double formula_2;
    double formula_2b;
    double formula_3;
    discrminant=  pow(b,2) - 4*a*c ;
  

    if (discrminant>0)
     {
     formula_1a = -b + sqrt(discrminant);
     formula_1b = formula_1a/(2*a);
     formula_2 = -b - sqrt(discrminant);
     formula_2b = formula_2/(2*a);
      printf("There are 2 real solutions\n");
      printf("Solution 1: %.2lf\n",formula_1b);
      printf("Solution 2: %.2lf", formula_2b);
   
      
      
     }
     else if(discrminant == 0)
     {  formula_3 = -b/(2*a);
        printf("There is one real solution:");
        printf("%.2lf", formula_3);
        
     }
     else {
    printf("There are no real solutions");
    
    }   }
  
                   


     //This function asks for your input a,b,c and calls the previous function to give you your answers
    int main (void){
    double b;
    double a;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    quadratic_equation(a,b,c);
   
     return 0;
     
   
 }
