# My Algorithm (steps to solve the problem)

1. Get user input for a, b, c 

2. Figure out how many solutions there are to quadratic formula using the user input of a,b,c into the discriminant (square root of b squared minus 4ac)
-> If the discriminant is 0. There is only one solution. 
-> If discriminant is positive there are 2 solutions
-> If the discriminant is negative there are no real solutions.

3. Based on the number of solutions, calculate using the quadratic formula, solution = -b +- the square of b^2 - 4ac all over 2a. 
-> If there is one solution, calculate and print the value
-> If two solutions, calculate both and print. 
-> If zero solutions, don't calculate anything. Tell the user "there are 0 solutions".

4. If two solutions, print larger solution first if there are two solutions.