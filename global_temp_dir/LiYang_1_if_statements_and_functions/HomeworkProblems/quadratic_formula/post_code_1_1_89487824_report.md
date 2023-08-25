# Algorithm (steps to solve the problem)
## Calculate the discriminant (line 5-11)
    1. Using the formula of discriminant(b^2-4ac) to calculate the number of discriminant
## Ask for the value of a,b and c (line 22-31)
    1. Asking user typing the value of a,b and c
    2. if a is equal to 0, ask user to typing another value of a
## Calcualte the output of the quadratic formula (line 36-51)
    1. If the number of discriminant is greater than one, which means there are 2 real solutions.
        a. Using the formula of quadratic:(-b+-[?](b2-4ac))/(2a) to calculate the solutions
    2. If the number of discriminant is equal to 0, which means there are 1 real solution.
        a. Using the formula -b/2a to calculate the solution
    3. if the number of discriminant is less than 0, which means there are no real solutions.
        a. Just tell the user there are no real solution
# Differences
    We create a new function the main funtion to calculate the discriminant, and just scan the input not print the number of a,b and c.