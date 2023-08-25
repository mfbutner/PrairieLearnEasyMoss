# Algorithm (steps to solve the problem)
1. Get user input for the values of a, b, and c in the quadratic equation ax^2 + bx + c
2. Calculate discriminant from those given values for a, b, and c.
3. If the discriminant is negative
    1. Print a message saying that there are no real solutions
4. If the discriminant equals zero (or is very close to zero)
    1. Calculate the plus root
    2. Print out the one real solution, the calculated plus root
5. If the discriminant is positive
    1. Calculate the plus root
    2. Calculate the minus root
    3. Print out the calculated plus root and then the calculated minus root
    
## Calculating the discriminant
1. Raise b to the power of 2
2. Subtract the result of 1 by the product of 4, a, and c

## Calculating the plus root
1. Multiply b by -1.
2. Add the result of 1 by the square root of the discriminant.
3. Divide the result of 2 by the product of 2 and a.

## Calculating the minus root
1. Multiply b by -1.
2. Subtract the result of 1 by the square root of the discriminant.
3. Divide the result of 2 by the product of 2 and a.

# Differences