# Algorithm (steps to solve the problem)

## Finding real roots of x
1. Set up expression
2. Check how many solutions there are, if there is one or more, proceed
3. Solve for root(s)

## Set up expression
1. Start with an equation in the form ax^2 + bx + c
2. Plug in the given values for a, b, and c

## Check for number of solutions
1. Square b
2. Mulitply 4 by a and c
3. Subtract sum from the last step (step 2) from the square of b
4. If this number is less than zero, there are no solutions and you are done
5. If this number is zero, there is one solution, and you should proceed with the calculation
6. If this number is greater than zero, there are two solutions, and you should proceed with the calculation

## Solve for roots
1. Solve for root number 1 (if the discriminant is equal to zero or greater than zero)
2. Solve for root number 2 (if the discriminant is greater than zero)

## Solve for root number 1
1. Multiply value b by -1 to get -b
2. Find the value inside the radical by first squaring b and then subtracting the sum of 4 times a times c from it
3. Square root the value
4. Add -b to your square rooted value from the last step
5. Divide your answer from the last step by 2 times a to get your solution

## Solve for root number 2
1. Multiply value b by -1 to get -b
2. Find the value inside the radical by first squaring b and then subtracting the sum of 4 times a times c from it
3. Square root the value
4. Subtract your square rooted value from the last step from -b
5. Divide your answer from the last step by 2 times a to get your solution

# Differences
- I realized when coding the program that it's easier to separate the steps for solving for the first root and the second root (in the case that the discriminant is greater than zero). This way, we know that in the case that the discriminant is greater than zero or equal to zero we will have to solve for one root. If the discriminant is greater than zero, we will also have to solve for a second root.