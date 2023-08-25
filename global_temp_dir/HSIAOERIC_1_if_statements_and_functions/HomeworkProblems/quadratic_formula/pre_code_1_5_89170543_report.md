# Algorithm(steps to solve the problem)

## Procedure Guide

- Build the quadratic equation
- Determine and solve the number of real solutions.

## 1. Build the quadratic equation
    i.   Build the quadratic equation first with coefficients a, b, and c. 
    ii.  This quadratic equation will be equal to zero.
    iii. Then the equation will be a*x^2+b*x+c = 0
    iv.  Ask the user to input a, b,and c.

## 2. Determine the number of real solutions 
    i.  We need to determine whether (b^2 - 4*a*c) is bigger, equal, or smaller than zero.
     
    b^2 - 4*a*c > 0 , there are two real solutions
    b^2 - 4*a*c = 0 , there is one real solutions
    b^2 - 4*a*c < 0 , there are no real solutions

    
### 2.1 There are two real solutions.
    i.  Solution 1 = (-b + sqrt(b^2-4*a*c))/(2a) 
        Solution 2 = (-b - sqrt(b^2-4*a*c))/(2a) 
    ii. Output the Solution 1 first and then Solution 2.
### 2.2 There is one real solution.
    i.  Only one solution = -b/2a
    ii. Output the solution.
### 2.3 There are no real solutions.
    i.  Output "There are no real solutions."