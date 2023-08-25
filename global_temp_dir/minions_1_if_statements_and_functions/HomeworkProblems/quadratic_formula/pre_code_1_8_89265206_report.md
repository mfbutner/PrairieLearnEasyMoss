## Solving Quadratic Formula
1. Receieve Input from the User for values a, b, and c
    1. (Expecting rational numbers)
2. Preliminarily check the discriminant (b^2-4ac) before continuing onto any part of the equation
    1. Discrimant being greater than 0 indcates two real solutions
    2. Discriminant being equal to 0 indicates one real solution
    3. Discriminant being less than 0 indicates no real solutions
3. Let the user know how many solutions that they should expect given the numbers they input
4. Use the user's values to input into formula to calculate solutions
## Discriminant > 0
1. Let the user know that there are two solutions, giving the positive solution first
2. The returned solutions will be the values that are output with a positive b and negative b from the formula 
## Discriminant = 0
1. Let the user know that there is exactly one solution, giving the value that satisfies the equation
2. The returned solution should be same for both the positive and negative case of b
## Discriminant < 0
1. Let the user know that there is no solutions, not giving any value back 
## Finishing the Calculation
1. The calculation will finish once the solutions (if any) are given back to the user