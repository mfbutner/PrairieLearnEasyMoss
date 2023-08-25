# Algorithm (steps to solve the problem)
## Get the Variable Values
1. Ask the user for value of a
2. Ask the user for value of b
3. Ask the user for value of c

## Find the Discriminant
1. Multiply b by b
2. Multiply a by c by 4
3. Subtract 4ac from b^2

## Find the Number of Real Solutions
1. If the discriminant is greater than zero, there are two solutions
2. If the discriminant is equal to zero, there is one solution
3. If the discriminant is less than zero, say there are no real solutions

## Find the Radical Part of the Numerator
1. Take the square root of the discriminant

## Find the Numerator(s)
1. Find the first numerator
* Multiply b by -1, then add the radical part
2. If there are two solutions
* Multiply b by -1, then subtract the radical part (add the negative version of the radical part)

## Find the Denominator
1. Multiply a by 2

## Find the Solutions
1. If there are two solutions
* Say there are two real solutions
* Divide the first numerator by the denominator
* Divide the second numerator by the denominator
2. If there is one solution
* Say there is one real solution
* Divide the first numerator by the denominator

# Differences

* I changed the way the numerators are found. One numerator will automatically be found and the second will be found if there are two real solutions, whereas previously a completely different action would have been taken depending on if there were one or two solutions. This was done to decrease the amount of code I needed to write.
* In the actual code, the functions for finding the discriminant and numerator(s) come first so they can be used in the main method, but my proposed solution lists them at the bottom.
* I changed the way the solutions are found to accomodate for the difference in the output wording depending on the number of solutions. I check for two solutions or one solution before finding the answers and printing them. In my proposed plan, the first solution would have been automatically printed, and the second would be printed if there were two solutions.
* I added a separate line to find the radical part of the numerator. This allowed finding the numerators to be easier, since all that needs to change (if there are two solutions) is the sign of the radical.