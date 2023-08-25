# Algorithm (steps to solve the problem)
## Find roots of quadratic 
1. Get quadratic equation from user
2. Find real roots of quadratic equation
3. Output real roots of quadratic equation

## Get quadratic equation from user
1. Ask for coefficient of quadratic term
2. Ask for coefficient of linear term
3. Ask for coefficient of constant term

## Find real roots of quadratic equation
1. Apply the quadratic formula to the coefficients of the quadratic equation

## Output roots of quadratic equation
1. If there are no real roots to the quadratic equation, then print that no real roots exist.
        
        Otherwise, print the positive real roots of the quadratic equation first if there are any. 
        Then, print the other real roots of the quadratic equation

# Differences
* In the original solution description, I stated solving for and printing "roots," instead of "real roots." Every quadratic equation has two roots, but this program will specifically print the real roots of a program if they exist, which is what the program actually computes.
* In the new solution description, I state that real roots are only output if they exist. In the original problem description, it was states that real roots were output, regardless of if they actually existed or not.
* I added an extra step at the beginning of the procedure titled "Output roots of quadratic equation." The extra step is to print that there are no real roots if none are computed, because that is what the program actually does.
* Although my program uses some cruft - an "Option" struct to manage the possibility of roots not existing, I still do not mention that in this updated solution description because it is strictly a programming construct and is implementation specific. As per the guidelines of the assignment, mentioning such programming constructs would result in grade penalties.