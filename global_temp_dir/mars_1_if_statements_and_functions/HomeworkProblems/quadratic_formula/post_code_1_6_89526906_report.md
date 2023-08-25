# Algorithm (steps to solve the problem)





* We must declare the header which deals with standard input and out
* Next we declare the header which deals with the math functions


# Next we must declare the function used to calculate the discriminant 'd'

Main function starts

* Now, we declare variable a which is coefficient of x^2 with appropriate data type
* Declare variable b which is coefficient of x with appropriate data type
* Declare variable c which is a constant with appropriate data type
* Declare variable d which is the discriminant with appropriate data type
* Declare variable for the first real solution with appropriate data type
* Declare variable for the second real solution with appropriate data type

# Next we must display the standard form of a quadratic equation

1. Now we ask the user to input the value of a


2. We ask the user to input the value of b


3. We ask the user to input the value of c

# Next we check different conditions for the discriminant to see if real roots exist or not




1. If the discriminant is lesser than zero then the message that no real solution is present must be displayed



2. If discrimanant is not lesser than zero, then we check if discriminant is equal to zero.
If it is, then we the math operation -b/(2a) is performed to find the real solution
The message that a real solution is present along with the calculated real solution is displayed.

3. If discriminant is not lesser than or equal to zero, it means that it is greater than zero.
In this case, we perform the mathematical operation to find solution 1 which is -b+sqrt(d)

* Futher, the answer to the previous operation is divided by 2a giving rise to solution 1

* Next we perform the mathematical operation to find solution  which is -b-sqrt(d)

* Futher, the answer to the previous operation is divided by 2a giving rise to solution 2

* The output message that two solutions are present along with the values of solution 1 and solution 2 is displayed.




Main function ends

# Now we describe the function of the discriminant which is used in the main function.





To calculate the value of the discriminant we use the operation (b^2-4ac)

# Differences
* This version of the problem solving steps is more in detail compared to the last one.
* This version has an additional statement describing how the value of the discriminant is calculated.
* This version has a line by line explaination of the code.