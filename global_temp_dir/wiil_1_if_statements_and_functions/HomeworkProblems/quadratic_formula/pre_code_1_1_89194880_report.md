# My Algorithm (steps to solve the problem)
##Solve quadratic formula
1. Transform the formula to the form: $ ax^{2}+bx+c=0 $.
1. Check if the equation is a quadratic formula.
2. Check if the equation has a solution.
3. Calculate the solution by its coefficients.
##Transform the formula
1. Move everything on the right side of the equation to left side by subtracting them.
##Check if the equation is a quadratic formula
1. If the equation has something like $ x^{3},x^{-1},x^{4},... $ other than $ x^{2},x,Constant $ , then it is not a quadratic formula.
2. If the coefficients of $ x^{2} $ , which is $ a $ in the equation , is 0 , then it is not a quadratic formula.
##If the equation is not a quadratic formula
1. Output the error information and the program can not solve it.
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