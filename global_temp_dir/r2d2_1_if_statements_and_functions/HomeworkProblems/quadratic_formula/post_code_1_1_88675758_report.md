# Algorithm (steps to solve the problem) (Quadratic Formula Solver)
##Set up the formulas
1. The first formula finds the first answer of the quadratic formula, with (-b + sqrt((b*b) - 4*a*c)) / (2*a). This may give us one of the possible values of x.
1. The second formula finds the first answer of the quadratic formula, with (-b - sqrt((b*b) - 4*a*c)) / (2*a). This may give us one of the possible values of x.
## Acquire the required values
1. Obtain the value a (in the formula ax^2 + bx + c)
2. Obtain the value b
3. Obtain the value c
##Plug the values into the Quadratic formula
1. Plug our given a, b, and c values into the formula (-b + (b ** 2 - 4 * a * c) ** 0.5) / (2 * a) for the first value of x.
2. Plug our given a, b, and c values into the formula (-b - (b ** 2 - 4 * a * c) ** 0.5) / (2 * a) for the second value of x
##Present the values
1. If there is one value then present it. 
2. If there are no values for x then state that there are no real numbers that equal x.
3. If there are two answers then present both. The positive one should go before the negative one.
##Changes I made from the original solution
1. I established the formulas before acquiring the value. This can improve clarity and the reader's idea of what we are doing.
2. I expanded "presenting the values" into its own section. This is because that presenting the value may have many differences, since it is possible that we can have two possible solutions for x, one solution, or even no solutions.