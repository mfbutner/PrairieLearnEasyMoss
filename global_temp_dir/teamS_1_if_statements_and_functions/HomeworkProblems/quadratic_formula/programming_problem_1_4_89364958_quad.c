# include<stdio.h>
# include<math.h>
# include<stdlib.h>
/*This program gives the number of solutions to the quadratic equation and displays the real roots of x if there are any.*/
void get_solution(double a, double b, double c);//declaration to connect the definition
int main(){
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    double a;double b;double c;//Define three variables of type double to represent the coefficients of different terms in the quadratic equation
    printf("Please enter a:");
    scanf("%lf",&a);// input the coefficient of the quadratic term
    printf("Please enter b:");
    scanf("%lf",&b);//input the coefficient of the primary term
    printf("Please enter c:");
    scanf("%lf",&c);//input the coefficient of the constant term
    get_solution(a,b,c);//output the result
    return 0;}
/*this definition gives the number of solutions. When the number of solutions is greater than 1, it also provides what the solution is*/
void get_solution(double a,double b,double c){
    int num_of_solutions;
    /*Firstly, the formula is used to judge the number of solutions, and then the corresponding results are output*/
    if (b*b-4*a*c > 0){
        num_of_solutions=2;//determine the number of solution
        double solution1;double solution2;//Define two variables of type double to represent solutions to quadratic equations
        solution1=(-b+sqrt(b*b-4*a*c))/(2*a);//calcalate the value of the bigger solution
        solution2=(-b-sqrt(b*b-4*a*c))/(2*a);//calculate the velue of the smaller solution
        printf("There are %d real solutions\n Solution 1: %.2lf\n Solution 2: %.2lf\n",num_of_solutions,solution1,solution2);//show the result
    }
    else if (b*b-4*a*c < 0){
        num_of_solutions=0;//determine the number of solution
        printf("There are no real solutions");//show the result
    }
    else{double only_solution;//Define one variable of type double to represent solutions to quadratic equations
    only_solution=(-b+sqrt(b*b-4*a*c))/(2*a);//calculate the only one solution
    printf("There is one real solution: %.2lf",only_solution);//show the result
}
}