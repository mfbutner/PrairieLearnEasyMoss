# Algorithm (steps to solve the problem)
## 1. Ask the user for values of a, b, and c
1. Store each of these numbers so we can refer to them later
## 2. Calculate the roots
1. Calculate the discriminate (the part of the quadratic formula that is under the square root)
    1. Check if the discriminant is negative, equal to 0, or positive. Whichever it is, calculate the root(s).
        1. If it is negative, there is no solution.
            - which means there's nothing else to do. Just print that there are 0 solutions.
        2. If it is equal to 0, there is only one solution.
            - plug the values of a, b, and c into the equation: (-b+(b^2-4*a*c))/(2a) to calculate the one solution
        3. If it is positive, then there are two solutions.
            - Get the positive root of the equation by plugging the values of a, b, and c into the equation: (-b+(b^2-4*a*c))/(2a). Save the answer.
            - Get the negative root of the equation by plugging the values of a, b, and c into the equation: (-b-(b^2-4*a*c))/(2a). Save the answer.
##Print how many solutions there are and what those solutions are

# Differences
1. My original solution would see how many roots, and save the number of roots, before calculating the roots. In contrast, my current solution doesn't save the number of roots. After it determines how many solutions there are, it just calculates and prints the number of solutions and the roots.