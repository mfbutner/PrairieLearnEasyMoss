# Algorithm (steps to solve the problem)
## User input
1. Ask user for a, b, and c values from quadratic equation in the form ax^2 + bx + c

## Calculate discriminant
1. Plug a, b, c values into discriminant: b^2 - 4ac

## Determine how many solutions exist
1. If the discriminant is less than 0:
    1. There are no real solutions
2. If the discriminant equals 0:
    1. There is one real solution
3. If the discriminant is greater than 0:
    1. There are two real solutions
    
## Solve for roots
1. Plug a, b, c into two versions of the quadratic formula (one that adds and one that subtracts):
    1. x = (-b + (sqrt (b^2 - 4ac)) / 2a
    2. x = (-b - (sqrt (b^2 - 4ac)) / 2a

## Announce solutions
1. If there are solutions
    1. Tell user how many solutions there are
        1. if there is one solution:
            1. show the user the one answer
        2. if there are two solutions:
            1. show the user the answer from the quadratic formula that adds first, then from the one that subtracts
    2. Tell user the roots / answers to the quadratic equation
2. Otherwise
    1. Tell user there are no solutions

# Differences
There were no differences between my original and current solutions