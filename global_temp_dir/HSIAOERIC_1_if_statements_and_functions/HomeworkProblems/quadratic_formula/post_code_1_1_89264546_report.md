# Algorithm(steps to solve the problem)

## 1. Build the quadratic equation
    i.   Build the quadratic equation first with coefficients a, b, and c. 
    ii.  This quadratic equation will be equal to zero.
    iii. Then the equation will be a*x^2+b*x+c = 0
    iv.  Ask the user to input a, b,and c.

## 2. Determine the number of real solutions 
    i.  We need to determine whether (b^2 - 4*a*c) is bigger, equal, or smaller than zero.
    ii. Let the "Determinant" equals to "b^2 - 4*a*c"
     
    Determinant > 0 , there are two real solutions
    Determinant = 0 , there is one real solutions
    Determinant < 0 , there are no real solutions

    
### 2.1 There are two real solutions.
    i.  Solution 1 = (-b + sqrt(b^2-4*a*c))/(2a) 
        Solution 2 = (-b - sqrt(b^2-4*a*c))/(2a) 
    ii. Output the Solution 1 first and then Solution 2.
### 2.2 There is one real solution.
    i.  Only one solution = -b/2a
    ii. Output the solution.
### 2.3 There are no real solutions.
    i.  Output "There are no real solutions."
    
# Differences
The difference is that we let the "Determinant" to express "b^2 - 4*a*c",
because it is more clear and understandable to use "Determinant" when comparing the value to 0.