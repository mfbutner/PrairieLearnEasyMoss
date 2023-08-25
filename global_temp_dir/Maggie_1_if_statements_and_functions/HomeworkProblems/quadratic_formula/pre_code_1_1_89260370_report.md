# My Algorithm (steps to solve the problem)
## Solve for the quadratic equation
1. Show the user what the quadratic equation form looks like (ax^x + bx + c)
2. Ask the user to enter values for a, b, and c.
3. Find whether there are one, two, or no real solutions.
4. Tell the user the solutions, if any.

## Find whether there are one, two, or no real solutions
1. Plug in the values of a, b, and c that the user sent into the quadratic formula x = (-b +/- sqrt(b^2 -4ac)) / (2a)
2. When x equals to a nonreal answer (when there is a negative in the square root)
    * It is not counted as a solution, so if there are two nonreal answers tell the user there are no solutions.
        * if there is one nonreal answer, tell the user there is one real answer and give the solution.
3. When x equals to a real answer
    1. If there is two real answers, tell the user there are two real answers then give the solutions
        * Give the positive answer first
    2. if there is one real answer, tell the user there is one real answer and give the solution.