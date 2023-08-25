# Algorithm (steps to solve the problem)

    1. Get coefficients of polynomial 
    2. Find value of discriminant
        1. Greater than or equal to zero means to calculate roots 
        2. Less than zero means no real solutions
    3. Use coefficient values to plug into quadratic equation
        1. Multiply coefficient of x term by -1 
        2. Add and subtract it to a square root with
            1. coefficient of x, squared 
            2. minus the coefficient of x^2 
            3. times the constant coefficient
            4. times 4
        3. All of that will be divided by 2 times the coefficient of x^2
    4. Then we end up with the number of roots of polynomial and values.

# Differences

    1. Discriminant is needed to determine number of roots (either 0, 1 or 2) because it determines number of real roots of polynomial.