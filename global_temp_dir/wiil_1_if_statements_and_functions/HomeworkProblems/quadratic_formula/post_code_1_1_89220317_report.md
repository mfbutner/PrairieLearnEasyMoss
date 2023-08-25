# Algorithm (steps to solve the problem)
##Solve quadratic formula
2. Check if the equation has a solution.
3. Calculate the solution by its coefficients.
##Check if the equation has a solution
1. Using the coefficients of the equation. 
2. Calculate $ b^{2} - 4ac $ .
3. If $ b^{2} - 4ac < 0 $ , then the equation does not have a solution.
##If the equation does not have a solution
1. Output "There is no solution to the equation."
##Calculate the solution
1. Make sure $ b^{2} - 4ac >= 0 $.
2. If $ b^{2} - 4ac = 0 $ , the equation has only one solution.
3. If $ b^{2} - 4ac > 0 $ , the equation has two solutions.
##The equation has only one solution
1. Calculate $ -\frac{b}{2a} $.
2. The solution is $ -\frac{b}{2a} $.
##The equation has two solutions
1. Calculate $ \frac{-b+\sqrt{b^{2}-4ac}}{2a} $.
1. Calculate $ \frac{-b-\sqrt{b^{2}-4ac}}{2a} $.
2. The solutions are $ \frac{-b+\sqrt{b^{2}-4ac}}{2a} $ and $ \frac{-b-\sqrt{b^{2}-4ac}}{2a} $.
# Differences
Without the first two steps to confirm it is a legal quadratic formula.
Because the input here is legal and don't have to consider the situation of "a=0"