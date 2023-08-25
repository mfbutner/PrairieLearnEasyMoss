# My Algorithm (steps to solve the problem)

##1.    Determine number of solutions 
        1.Asking for number a, number b, and number c.
        2.Calculate (b*b)
        3.Calculate (4*a*c)
        4.Calculate (b*b) - (4*a*c)
        5.Calculate (2 * a)
        6.Calculate ((b*b) - (4*a*c))
            1. if (b*b) - (4*a*c) > 0, there are two solutions
            2. if (b*b) - (4*a*c) = 0, there is one solution
            3. if (b*b) - (4*a*c) < 0, there is no solution  

##2.    Calculate solution, x.
        1.if there are two solutions
            1. solution 1 = -b + Square root of((b*b) - (4*a*c))
            2. solution 2 = -b - Square root of((b*b) - (4*a*c))
        2. else if there is one solution
            1. solution = -b / (2*a)
        3. else there is no solution
            1. there is no solution 
    
##3 Announce results
        1. Announce how many solutions of the quadratic equation have.
        2. Announce the actual real number solution of the quadratic equation.