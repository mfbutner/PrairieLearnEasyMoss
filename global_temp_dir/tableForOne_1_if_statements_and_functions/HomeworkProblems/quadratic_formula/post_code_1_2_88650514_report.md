# Algorithm (steps to solve the problem)

##Get a, b, and c from user
-User enters what values they want for a, b, and c

##Find the number of solutions
-If the discriminant was less than 0, then there are no solutions

-If both of the calculations are the same, there is one solution, otherwise there are 2


##Calculate the real roots using quadratic formula

-Calculate the positive version of the formula

-Calculate the negative version of the formula


##Print the real roots of x
-Print how many solutions there were

-Print the value of the solutions

# Differences
-I wrote the first algorithm thinking the user would enter the form ax^2+bx+c, but I was just supposed to prompt the user 3 different times for a, b, and c.

-Did not properly think through how to find out if there were 1 or 2 solutions so I did: if the positive formula equals the negative formula, then there is one solution; otherwise, it is 2 solutions.

-Did not properly think about how to put the positive solution first, so had to do: if the negative calculation is greater than 0 and the positive calculation is less than zero, print the negative one first; otherwise, print the positive solution then the negative solution.