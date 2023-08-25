# Calculate the roots of a quadratic equation
1. Get user input for a, b, and c
2. Find the roots of the quadratic equation
3. Display the results
## Get user input
1. Ask user for a, b, and c
## Find the roots of the quadratic equation
1. First find b^2 -4ac. If the result is negative there is no real roots and you can move on to display the results
2. Add -b to the square root result of step 2. Then divide that result by 2 * a. This will be the first possible root
3. Subtract -b from the square root result of step 2. Then divide that result by 2 * a This will be the second possible root. 
4. If both possible roots are the same number, there is only one root. Otherwise there are 2 roots. Move on to display the results
## Display the ressults
1. Say if there are 0, 1, or 2 roots
2. Display all possible roots if neccesary
# Differences
- Consolidated the steps of square rooting, adding or subtracting b, and dividing by 2a into one step
- Clarified the logical structure, so that it is more clear that if you get a negative result, you know that there are no roots, so you can just move on to displaying the result