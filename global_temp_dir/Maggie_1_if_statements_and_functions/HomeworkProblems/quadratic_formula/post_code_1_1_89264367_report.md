# My Algorithm (steps to solve the problem)
## Solve for the quadratic equation
1. Show the user what the quadratic equation form looks like (ax^x + bx + c)
2. Ask the user to enter values for a, b, and c.
3. Find whether there are one, two, or no real solutions.
4. Tell the user the solutions, if any.

## Find whether there are one, two, or no real solutions
1. Check whether an imaginary number or nonreal answer is formed.
    * An imaginary number is formed when there is a negative in the square root.
2. If there are no imaginary numbers 
    * plug in the values of a, b, and c that the user sent into the quadratic formula x = (-b +/- sqrt(b^2 -4ac)) / (2a)
    * note that +/- makes two separate solutions.
        * When the solutions are not the same
            * Tell the user there are two solutions and give them the two solutions, positive formula first.
        * When the solutions are the same
            * Tell the user there is one solution and give one of the numbers.
3. When there is an imaginary number
    * It is not counted as a solution, so if there are two nonreal answers tell the user there are no solutions.
        * if there is one nonreal answer, tell the user there is one real answer and give the solution.

# Differences
1. The main difference is that I had to factor in an imaginary number checker to make the program flow better. From this checker, I was able to form the different circumstances with the solutions being real or nonreal.
    * I also had to make another statement when two solutions equaled each other.