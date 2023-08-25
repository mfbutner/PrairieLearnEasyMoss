# Algorithm (steps to solve the problem)
## Start of Program
1. Ask for the a, b, c values of the quadratic equation
2. Calculate the roots and display results

### Ask for the a, b, c values of the quadratic equation
1. Ask the user for the a, b, c values of the given quadratic equation in the form ax^2 + bx + c
and remember those values

### Calculate the roots and display results
1. if expression inside the square root is a negative value, then display that there are no real roots
2. otherwise calculate the + and - roots and display results

#### calculate the + and - roots and display results
1. calculate the + root by using the quadratic formula and using the + operator for the (+/-)
2. calculate the - root by using the quadratic formula and using the - operator for the (+/-)
3. display the results of the real roots using the + root and the - root

##### display the results of the real roots using the + root and the - root
1. if the + root is equal to the - root, there is only one root and display that result
2. otherwise display both roots


# Differences
1. for my original solution, I asked the user for the values, did all the calculations, and then displayed the results HOWEVER for my current solution I did the calculation for the expression inside the square root first and then if that value was negative, I displayed that there were no roots and then after I did more calculations and displays the solutions if there were any real roots