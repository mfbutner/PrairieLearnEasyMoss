# My Algorithm (steps to solve the problem)

## Define the Formula
1. The quadratic equation is (ax^2 + bx + c).
2. The formula needed to find the solutions of the equation is x = (-b +- sqrt(b^2-4*a*c)) / (2*a).
3. The formula requires 3 numbers to substitute for the variables.
4. In order to solve the equation, we first need number inputs for each variable of the formula.

## State the Form of the Quadratic Equation
1. State how the quadratic equation is in the form a*x^2 + b*x + c.

## Get Number Inputs
1. The user will enter 3 numbers when prompted and press enter after each variable.
2. We need 3 numbers to substitute for each variable 'a', 'b', and 'c'.
3. The number can be any real value, including values with decimal points.
4. The number will never be 0 for the variable 'a' as it will make the denominator 0, which would cause the solution to be undefined.

## What Determines the Number of Solutions
1. The discriminant determines the number of solutions.

## Define the Discriminant
1. The discriminant is the part of the equation that has the square root of (b^2-4*a*c)".
2. This is the main part of the program that will determine the number of real solutions.

## How the Discrimnant Determines the Number of Solutions
1. If the discriminant is negative, then there are no real solutions.
2. This is because we cannot take the square root of a negative number, so it would cause there to be imaginary solutions, and we are not finding imaginary solutions.
3. If the discriminant is positive, then there will be 2 real solutions. 
4. We can find both solutions by solving the plus and minus roots.
5. If the discriminant is 0, then there is only one solution.
6. We can solve this by dividing (-b / (2*a)).