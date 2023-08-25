# Algorithm (steps to solve the problem)
Find the solution(s) of a quadratic equation
1. Complete the equation (get the values of a,b and c)
2. Calculation and show the solution(s)


# Complete the equation:
1. Inform user the standard form of the quadratic equation, so they know what are a, b and c stand for.
2. Prompt user to enter their numbers, the cooeficents.

# Calculation and show the solution(s)
1. Determine how many solution(s) we have, 0, 1 or 2.
    - Find the value of (b^2 -4ac) which is the part under the square root sign.
    - Compare it with 0 to determine the number of solutions we may have.
2. Perform the quadratic formula.
    - When it's the case that there are 2 solutions, use fomula to find these 2 solutions, and tell user that there are 2 solutions and show them on the screen.
    - When it's the case that there are 1 solutions, use formula to find that solution, and tell user that there is only 1 solution and show it on the screen.
    - When there is no solution, just say there are no real solutions.

# Differences
Before coding, I was plannig to separate the Calculation and Giving output parts. But when I was coding, I found that it's a lot easier to make two functions (since there may be at most 2 solutions) which get 3 coefficients and performs the quadratic formula, and use them when making output according to different scenarios.