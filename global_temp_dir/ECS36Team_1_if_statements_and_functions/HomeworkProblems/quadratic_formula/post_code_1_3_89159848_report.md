# HW 3.3: Quadratic Formula

## Ask the user for a quadratic equation

1. Ask the user for the numbers a, b, c given the format of a quadratic equation

## Solve the quadratic equation and announce results

1. Check if there is a real solution by checking if the number inside the square root of the quadratic formula is negative
    1. If it is negative there are no real solutions
    2. Announce to user that "There are no real solutions"

2. If the number is not negative there is one or two real solutions, calculate the two solutions by plugging in the user's input to the following equations:
    1. First calculate (-b + (b^2 - 4ac)) / 2a
    2. Then calculate (-b - (b^2 -4ac)) / 2a

## Announce the results
1. Check if two answers are equal
    1. If the two solutions are equal, tell the user "There is one real solution" and tell them the first solution
    2. If the solutions are not equal, tell the user "There are two real solutions" and tell them the first and second solutions

## Difference in solutions
1. We told the user there is no solution right after checking if there are real solutions since there is no need to calculate the answers if there are no real solutions.