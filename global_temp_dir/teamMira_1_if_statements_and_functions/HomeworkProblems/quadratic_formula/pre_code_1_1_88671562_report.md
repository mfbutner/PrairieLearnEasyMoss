# My Algorithm (steps to solve the problem)
### Calculate the roots value of X
- Introduce the user to the form of a quadratic equation
- Ask the user for the values of a,b,&c
- Calculate the roots of a quadratic
- Determine the 3 possible cases 
- Calculate the values based on the case possibilities 

### Introduce the user to the form of a quadratic equation
- Start the program with a simple statement to introduce the user to the form of a quadratic equation.
- Giving the user the form of a quadratic will help them identify the values of a,b,&c.
Use the form of a quadratic equation "ax^2 + bx + c" in the statement.

### Ask the user for the values of a,b,&c
- The first statement will ask the user for the value of 'a' which corresponds to the value of 'ax^' in the quadratic equation.
- The second statement will ask the user for the value of 'b' which corresponds to the value of 'bx' in the quadratic equation.
- The third statement will ask the user for the value of 'c' which corresponds to the value of 'c' in the quadratic equation.

### Calculate the roots of a quadratic
- The quadric formula is  (-b+-[?](b2-4ac))/(2a)
- Start the calculation process by calculating the discriminant 
- Discriminant = b2-4ac
- Then use the discriminant to get the values for root 1 and root 2
- Root 1 = -b + discriminant  / 2a
- Root 2 = -b - discriminant  / 2a

###Determine the 3 possible cases 
- There are 3 possible cases when solving for the roots of a  quadratic equation
- B2-4ac < 0 NO solution 
- B2-4ac = 0 ONE solution
- B2-4ac > 0 TWO solutions

###Calculate the values based on the case possibilities 
- If the discriminant falls under case 1 which is no solution 
--The program will indicate that there are no possible solutions
- If the discriminant falls under case 2 which is one solution 
-- The program will indicate that there is one solution 
-- Give the answer for the root of x
- If the discriminant falls under case 3 which is two solutions
-- The program will indicate that there are two solutions
-- Give the first solution for the root 1 of x
-- Give the second solution for the root 2 of x