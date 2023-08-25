# My Algorithm (steps to solve the problem)
##Purpose
This program calculate the roots of a quadaratic equation are values of that cause the equation to evaluate to 0.
##Steps
    1. Get number of roots of quadratic equation
    2. Set the quadratic formula
    3. Consider possibility to get number of solution
    4. Considering possibility of number of solution, get the solutions
    
##  1. Get number of roots of quadratic equation

        - Get roots of quadratic equation
            - Ask value of a,b, and c in quadratic equation ax^2+bx+c
            - a,b,c should be a real number
        
##  2. Set the quadratic formula

         - Set the quadratic formula which is x = (-b+-[?](b2-4ac))/(2a)
            - Put the a,b,c value you asked to this formula
            - Calculate the equation then get value of x
##  3. Consider possibility to get number of solution

        - consider that x can have one real number solution, two real number solutions, and no real number solution.
            - What condition make just one real number solution
                - 1st condition: After caculating, if number is a real number + or - real number,
                - 2nd condition: After you calculate +-, the results of + and - is are same real number then there are two real number solution
            - What conditions make two real number solutions
                -  1st condition: After caculating, if number is a real number + or - real number
                -  2nd condition: After you calculate +-, the results of + and - are different real number, then there are two real number solution
            - What conditions make no real number solutions
                -  1st condition: After caculating if the number in squrt or b^2-4ac is negative number, then there is no solution
##  4. Considering possibility of number of solution, get the solutions
        - If there is one real number solution, then just say one real number solution and tell what it is
        - If there is two real number solution, then just say two real number solution and tell what are they
        - If there is no real number solution, then just say there is no solution.