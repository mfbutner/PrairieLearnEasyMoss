# Algorithm (steps to solve the problem)
##1 Asking user for input
        1. asking for a
        2. asking for b
        3. asking for c

##2 Determine number of solutions
        1. if discriminant = 0 
            1. there is one real solution
        2. if discriminant > 0
            1. there are 2 real solution
        3. otherwise there are no real solutions 
            
##3 Calculate real solutions
        1. if discriminant = 0
            1. real solution = (-b) /(2*a)
        2. if discriminant > 0
            1. real solution1 = (-b + sqrt(discriminant))/(2*a)
            2. real solution2 = (-b - sqrt(discriminant))/(2*a)

##4 Calculate discriminant (correlated to number of solutions)
        1. discriminant = b*b -(4*a*c)
# Differences
        My overall process is about the same, but I did change my orders a lot.
        I make a function for calculating discriminant and it helps me alot when programming
        but I didn't make a separate heading for it when I wrote down my algorithm.