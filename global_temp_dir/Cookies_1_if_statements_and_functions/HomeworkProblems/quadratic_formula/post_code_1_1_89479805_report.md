# Find the Roots / How Many
 1. Get inputs 
 2. Solve Formula to get solutions
 3. Use Discriminant to know how many roots

# Get inputs
 1. Ask for 3 inputs (a), (b), and (c) that correspond to the quadratic equation Ax^2+Bx+C

# Solve Formula to get solutions
 1. Plug in the inputs to the equations x = (-(b)+ sqrt((b)^2 - 4(a)(c))) / 2(a) and x' =(-(b) - sqrt((b)^2 - 4(a)(c))) / 2(a)

# Use the Discriminant to know how many roots
 1. Find the discriminant which is the part of the equation inside the sqrt so: (b^2 - (4*a*c))
    2. If the discriminant is > 0, there are 2 roots
    3. If the discriminant is = 0, there is 1 root
    4. If the discriminant is < 0, there are no roots
 
#Findings 
  1. If there was 2 roots, the solutions are x and x' found in the previous steps 
  2. If there was 1 root, the solution is x (x and x') are the same in this case
  3. If there were no roots, x and x' are not real numbers, meaning the inputs yielded no solutions

# Differences
- Different approach to solving the main quadratic equation by Simplified it to solving for x and x' to differentiate between the additive and subtractive equations. 
    - I thought the original solution was messy and confusing and because the equation solutions were not a huge part of my code (in comparison  to the discriminant), it would be ok to mostly focus on the discriminant instead of more steps on solving the formula.
- Used the discriminant to find the amount of roots instead of the whole formula solutions
    - Using the solutions of the whole formula to find out how many roots there was as used in the originally proposed solution was not very explanitory, as it assumed the reader knew what a imaginary number is and how to distinguish it from real numbers. 
    - In the originally proposed solution, it was written that one solution could be imaginary, and the other could be real simultaneously. This is wrong, and using the discriminant resolves this error. 
- Added a findings heading to sumarize and hopefully add to the cohesion of what the previous steps had accomplished.
    - I though the original solution smashed a couple different steps under 1 heading, so this is separating the calculations from the findings.