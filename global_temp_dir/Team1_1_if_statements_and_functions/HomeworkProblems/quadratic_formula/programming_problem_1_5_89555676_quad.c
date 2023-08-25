#include<stdio.h>
#include<math.h>
double ComputeSquare(double numTosquare){
    return numTosquare*numTosquare; // use a function to define square for the delta-value calculation
}
double delta_Value (double function_ValueA, double function_ValueB, double function_ValueC) {
    double delta_Value;//define delta value
    delta_Value = (ComputeSquare(function_ValueB))- (4 * function_ValueA * function_ValueC);//delta value calculation formula
    return delta_Value;//
}
int main () {
    double function_Solution1;//solution x1
    double function_Solution2;//solution x2
    double function_CommonA;//user input value a
    double function_CommonB;//user input value b
    double function_CommonC;//user input value c
    double dValue;//delta value 
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");//print the normal funtion for quadratic funcion
    printf("Please enter a: ");//ask to input a
    scanf("%lf",&function_CommonA);//assign a to variable 
    printf("Please enter b: ");// ask to input b
    scanf("%lf",&function_CommonB);//assign b to variable
    printf("Please enter c: ");//ask to input c
    scanf("%lf",&function_CommonC);//assign c to variable
    dValue = delta_Value (function_CommonA,function_CommonB,function_CommonC);//calculate the delta value through the function defined before
    if (dValue > 0) //determine the value greater than 0
    {
        function_Solution1 = ((-(function_CommonB))+sqrt(dValue))/ (2 * function_CommonA);//find out the function solution1
        function_Solution2 = ((-(function_CommonB))-sqrt(dValue))/ (2 * function_CommonA);//find out the function solution2
        {
        printf ("There are 2 real solutions\n");
         if (fabs(function_Solution1) - fabs(function_Solution2) < 0)//compare the absolute value to determine which go first
            {
            printf ("Solution 1: %.2lf\n",function_Solution1);
            printf ("Solution 2: %.2lf\n",function_Solution2);
            }
            else
            {
            printf ("Solution 1: %.2lf\n",function_Solution2);
            printf ("Solution 2: %.2lf\n",function_Solution1);
            } 
        }
    }
    else if ((int)(dValue*100) == 0)//for delta equal to 0
    {
        function_Solution1 = ((-(function_CommonB))+sqrt(dValue))/ (2 * function_CommonA);//calculate the function value again for this statement
        function_Solution1 = ((-(function_CommonB))+sqrt(dValue))/ (2 * function_CommonA);
        printf ("There is one real solution: %.2lf",function_Solution1);// only one output fot this kind of function
    }
    
    else{
        printf("There are no real solutions");//if dValue <0 there is no value
    }
return 0;
}
