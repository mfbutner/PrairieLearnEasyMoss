# Algorithm (steps to solve the problem)
## H2: Get the values for a, b, and c
    1. ask user the values of a, b, and c
## Calculate for the discriminant
    1. given a, b, and c
    2. solve b*b
    3. solve 4*a*c
    4. obtain answer for step 2 - step 3
##Determine how many solutions there are from the discriminant 
    1. there will be no solution if disciminant is less than 0
    2. there will be 2 solutions if discriminant is greater than 0
    3. there will be one solution if discriminant is equal to 0
##Calculate for one solution
    1. evaluate -b
    2. evaluate 2*a
    3. (step 1 / step 2) to get the solution
##Calculate for 2 solutions
    1. evalaute for the postive solution
        1. evalaute -b
        2. evalaute square root of b*b - 4*a*c
        3. evaluate 2*a
        4. step 1 + step 2 / step 3 to get positive solution
    2. evalauate for the negative solution
        1. evalaute -b
        2. evalaute square root of b*b - 4*a*c
        3. evaluate 2*a
        4. step 1 - step 2 / step 3 to get negative solution

# Differences
    - I didn't use the discriminant to determine how many solutions there will be in my original instructions. I changed it because I found it easier to determine the solutions by using the discriminant.
    - I also forgot to mention how to solve for x when there is only one solution in my original instruction