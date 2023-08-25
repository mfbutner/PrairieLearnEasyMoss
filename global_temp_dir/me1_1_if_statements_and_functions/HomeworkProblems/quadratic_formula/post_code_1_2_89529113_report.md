# My Algorithm (steps to solve the problem)
1. Given the quadratic equation in the form a*x^2 + b * x + c.
2. Use the quadratic formula to find if there are zero real solutions, one real solutions, or two real solutions.
3. If there is one or two real solutions, compute them. 

## Determine a, b, and c variables 
1. Convert equation to the correct quadratic equation form.
2. In the correct quadratic equation form, enter the values for a, b, and c.

## Calculate the discriminant
1. The discriminant, or the product inside the square root of the quadratic formula, is b^2 - 4ac.
2. Plug in the a, b, and c variables into the equation b^2 - 4ac to find the discriminant.

## 2 real solutions
1. If the discriminant is greater than 0.

## 1 real solution
1. If the discriminant is equal to 0.

## 0 real solutions
1. If the discriminant is less than 0.

## Announce results
1. If there are 2 real solutions
    * a. Then solve for the two real solutions using the quadratic formula by plugging in the a, b, and c values.
    * b. Present the two real solutions, with one being the addition and the other being the subtraction.
2. If there is 1 real solution
    * a. Then solve for the one real solution using the quadratic formula by plugging in the a, b, and c values.
    * b. Present the one real solution.
3. If there are 0 real solutions
    * a. Then tell the user there is no real solutions.

# Differences
    + I ended up switching the order of if there are 2, 1, and 0 real solutions.
    + Made the + solution printed first.