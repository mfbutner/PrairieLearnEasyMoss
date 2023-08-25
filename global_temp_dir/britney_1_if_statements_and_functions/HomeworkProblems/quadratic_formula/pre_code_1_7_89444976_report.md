# My Algorithm (steps to solve the problem)

## 1. Ask the user for values of a, b, and c
1. Store each of these numbers so we can refer to them later
## 2. See how many solutions exist
#### Calculate the discriminate (the part of the quadratic formula that is under the square root)
1. Check if the discriminant is negative, equal to 0, or positive.
    1. If it is negative, there is no solution.
    2. If it is equal to 0, there is only one solution.
    3. If it is positive, then there are two solutions.
## 3. Get the roots of the quadratic equation
1. If there are 0 solutions, there's nothing else to do. Just print that there are 0 solutions.
2. If there is one solution plug the values of a, b, and c into the equation: (-b+(b^2-4*a*c))/(2a) to calculate the solution
3. If there are two solutions
    1. Get the positive root of the equation by plugging the values of a, b, and c into the equation: (-b+(b^2-4*a*c))/(2a). Save the answer.
    2. Get the negative root of the equation by plugging the values of a, b, and c into the equation: (-b-(b^2-4*a*c))/(2a). Save the answer.

## 4. Print how many solutions there are and what those solutions are