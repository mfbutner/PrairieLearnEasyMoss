# My Algorithm (steps to solve the problem)
## finding roots of equation, there will be either 0, 1, or 2

## getting input
1. ask user for value of a
2. ask user for value of b
3. ask user for value of c

## assign the values to a,b,c -- a will never be 0
- store/remember that 'a' will never equal 0

## if b*b-4*a*c is non-negative, the roots of the equation can be solved with the following formulas
1. the first root would be equal to (-b + sqrt(b*b-4.*a*c) ) / (2*a))
2. the second root would be equal to (-b - sqrt(b*b-4.*a*c) ) / (2.*a))

## if b*b-4*a*c is negative, then there would be no roots

## tell the user how many solutions there are
1. give first solution, if any
2. give second solution, if any