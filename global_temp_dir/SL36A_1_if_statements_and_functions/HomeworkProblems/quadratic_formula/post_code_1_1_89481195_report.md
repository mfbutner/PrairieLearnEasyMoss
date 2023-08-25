# Algorithm (steps to solve the problem)
## Find solutions to the quadratic equation
1. Ask the User for values a, b, and c (a can't be 0) 
2. Find the discriminant
3. Calculate the roots
## Find the discriminant
1. Calculate b^(2)-4ac
## Calculate the roots
### Two real solutions
1. If the discriminant is positive
2. Solution 1 is (-b+sqrt(b^(2)-4ac))/2a
3. Solution 2 is (-b-sqrt(b^(2)-4ac))/2a
4. Tell the User there are 2 solutions and print the solutions
### One real solution
1. If the discriminant is zero
2. Solution is -b/2a
3. Tell the User there is 1 solution and print the solution
### No real solutions
1. If the discriminant is negative
2. Tell the User there is no solution


# Differences
* I rearranged the order of the different results for the discriminant (aesthetic change)
* I put the print statements directly inside each section after the discriminant is found (for clarity)
* Otherwise no major changes