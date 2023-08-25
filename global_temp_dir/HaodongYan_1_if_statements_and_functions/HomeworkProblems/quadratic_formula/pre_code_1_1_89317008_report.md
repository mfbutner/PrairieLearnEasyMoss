# My Algorithm (steps to solve the problem)

## Get numbers from users
    The form is ax^2+bx+c=0
    1. Let users type their a
    2. Let users type their b
    3. Let users type their c
    
## Use the function solve for x
    1. x1 = [-b+sqrt(b^2-4ac)]/2a
    2. x2 = [-b-sqrt(b^2-4ac)]/2a
    
## No real roots
    1. when b^2-4ac<0, there are no real roots.

## 1 real solution
    1. when b^2-4ac=0, there are 2 real roots with same value, we consider that is 1 real root.
    
## 2 real soliution
    1. when b^2-4ac>0, there are 2 real roots with different value.
    
## Announce the result
    1. if results comes up, no matter they have 0,1,2 real roots, show them on the screen.