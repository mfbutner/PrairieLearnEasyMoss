# Algorithm (steps to solve the problem)
# Finding the real solutions of a quadratic equation
1. Get the values for a, b, and c
2. Plug them into the quadratic equation
3. Announce solution(s)

## Get the values for a, b, and c

## Plug a, b, and c into the quadratic equation
1. Evaluate b squared - 4a*c
2. If the answer is positive:
    1. Take the square root of the answer, add b, then divide by -2a to get the 1st solution
    2. Take the square root of the answer, subtract b, then divide by 2a to get the 2nd solution
        - If the 1st and 2nd solution are the same, there is one real solution
        - If the 1st and 2nd solution are different, there are 2 real solutions
    - If the answer is negative, there is no real solution
## Announce solution(s)
1. If b squared - 4a*c is positive:
    - There are 1 or 2 real solutions
        - If there is one real solution, announce that solution
        - If there are two real solutions:
            - if both solutions are positive: announce the less positive solution first
            - if one or both solutions are negative: announce the more positive solution first
2. If b squared - 4a*c is negative, there is no real solution

# Differences
- dividing by negative 2a instead of positive 2a in step 2-1 so the calculations work out correctly
- when announcing negative solutions, the more positive number should go first, but when both solutions are positive, the lower number should be announced first