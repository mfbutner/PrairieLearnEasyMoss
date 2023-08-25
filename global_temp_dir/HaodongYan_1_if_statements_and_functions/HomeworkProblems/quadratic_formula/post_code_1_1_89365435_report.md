# Algorithm (steps to solve the problem)

## Define a function
    1. by the requirement, I defined a function of find the discriminant
    
##Get numbers from users
    The form is ax^2+bx+c=0
    1. Let users type their a
    2. Let users type their b
    3. Let users type their c

## ensure the root formula
    1. x1 = [-b+sqrt(b^2-4ac)]/2a
    2. x2 = [-b-sqrt(b^2-4ac)]/2a

## 2 real soliution
    1. when b^2-4ac>0, there are 2 real roots with different
    
## 1 real solution
    1. when b^2-4ac=0, there are 2 real roots with same value, we consider that is 1 real root.

## No real roots
1. when b^2-4ac<0, there are no real roots.

# Differences

1. I realize we should have more than 1 function in the program so I defined a new function called Calcdiscriminant
2. The order of roots finding are changed.