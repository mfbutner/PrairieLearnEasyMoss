# My Algorithm (steps to solve the problem)

##Create a void function that prints the number of real solutions of a quadratic function
- Calculate the discriminant
- Compare the value of the discriminant to 0
- Retain the number of solutions based on the comparison
- Print that number to the screen

##Create a void function that prints the first solution of a quadratic function (If there is one)
- Use the quadratic formula to calculate the solution
- This will be the + solution in the plus or minus part
- Check to see if it is imaginary
- If not, print it

##Create a second void function that prints the second solution of a quadratic function (If there are two)
- Use the quadratic formula to calculate the solution
- This will be the - solution in the plus or minus part
- Check to see if it is imaginary
- If not, print it

##(In main) Take input in the standard quadratic form from the user
- Scan value for a
- Scan value for b
- Scan value for c

##(In main) Call all the functions in the appropriate order
- Call the function that prints the number of solutions
- Call the function that prints the first solution
- Call the function that prints the second solution