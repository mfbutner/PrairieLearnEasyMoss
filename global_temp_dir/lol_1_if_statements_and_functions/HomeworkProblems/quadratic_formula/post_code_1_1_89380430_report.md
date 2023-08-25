# Algorithm (steps to solve the problem)
## gain user input
## calculate the solution based on formula given
- determine how many solutions a function have by calculating pow(b, 2) - 4 * a * c).
- the function have real solution(s) if pow(b, 2) - 4 * a * c) >= 0
    - calculate the x1 and x2 based on formula provided
        - when x1 = x2, the function have 1 single solution rather than 2 solutions
        - when x1 != x2, function have 2 different real solutions
- the function will not have real solutions if pow(b, 2) - 4 * a * c) < 0.
- output the corresponding result.
# Differences