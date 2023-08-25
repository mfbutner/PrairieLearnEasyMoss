# My Algorithm (steps to solve the problem)

Solving quadratic formula: (Breaking down of each step below)
1. Take the user inputs for each constant in the formula.
2. Find the number of solution(s) the equation has.
3. Calculate the actual solutions based on the formula given.
4. Output the result to the user.

1:
Take the user input for each constant in the equation one by one. (ax^2 + bx + c)
Take and store a, then b, then c.
2:
Number of real solutions can be found by calculating square root (b^2 - 4ac).
If this value is less than 0 -> No real solutions.
value = 0 -> 1 real solution.
value > 0 -> 2 real solutions.
3:
Calculate the solution based on the result of the value just found on step 2.
When there is no solution then simply do nothing.
When there is solution(s), calculate the result(s) using the x = (-b +- sqrt(b^2 - 4ac))/ (2a)
4: 
Tell the user the final result that has been found in step 3.