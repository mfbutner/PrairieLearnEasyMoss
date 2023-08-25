# Finding Solutions for x using the quadratic formula
## Set up
1. get three numbers form the user
2. set the first number to a
3. set the second number to b
4. set the third number to c
5. write the expression in the form ax^2 + bx + c
6. get the equation x = (-b +- (b^2 - 4ac)^(1/2))/2a
## Solve
1. split the equation in step 6 in Set up into two differnt equations
    1. x1 = (-b + (b^2 - 4ac)^(1/2))/2a
    2. x2 = (-b - (b^2 - 4ac)^(1/2))/2a
2. plug in a for a, b for b, and c for c in both x1 and x2
3. simplify the expression within one of the square roots
    1. square b
    2. multiply 4 by a and c
    3. subtract (4*a*c) from b^2, then call this value simplifiedRoot
4. check to see if the simplified expression is negative
    1. if it is, then there is no solution, solution = no solution, and skip to step 2 in Get Solutions
    2. if not, continue
5. simplify both expression by simplifying the numerators, then dividing by two
    1. for x1, add b(-1) to simplifiedRoot, then divide by 2*a
    2. for x2, subtract simplifiedRoot from b(-1), then divide by 2*a
## Get Solutions
1. check if x1 is the same as x2
    1. if the same, then solution = 1 solution
    2. if not, then solution = 2 solutions
2. read out the value from solution