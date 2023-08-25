# Algorithm (steps to solve the problem)
##Solve the quadratic equation
1. Ask the user for the quadratic equation
2. Solve the quadratic equation
3. Show the results

##Ask the user for the quadratic equation
1. Ask user for a, b, c for the equation form $ax^2 + bx + c$
##Solve the quadratic equation
1. Calculate the discriminant by plugging a, b, and c into $b^2 - 4ac$
2. Use the discriminant to determine how many real solution does the problem has:
    1. if the discriminant is equal to 0, then there is only one real solution
    2. if the discriminant is larger than 0, then there is 2 real solutions
    3. if the discriminant is smaller than 0, then there is no real solution
3. Calculate the real solution based on the discriminant:
    + If there is only one real solution, then simply plug a, b, and c into $x = \frac{-b - \sqrt{b^2 - 4ac}}{2a}$  or $x = \frac{-b + \sqrt{b^2 - 4ac}}{2a}$. Both equations should give the same answer
    + If there is 2 real solutions, plug a, b, c into $x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$ and reduce the equation to find 2 roots
    + If there is no solution, then there is no calculation at all
  
##Show the results
 1. If there are 2 real solutions, then states that there are 2 real solutions and show them
 2. If there is 1 real solution, then state there is one real solution and show the result
 3. If there is no real solution, inform the user that there is no real solution
# Differences
1. I didn't need to set up the equation $ax^2 + bx + c$, which doesn't help much in figuring out the solution to the problem. Rather, I just need to get a, b, and c for the quadratic equation $x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$.
2. I needed to calculate the discriminant to figure out how many solution will the problem have