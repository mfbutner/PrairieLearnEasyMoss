# Algorithm (steps to solve the problem)

## Get values for a, b, and c
1. a is the lead coefficient, coming before the variable x^2
2. b is the coefficient in front of the variable x
3. c is the constant value not attached to any x

## Find the number of roots
1. Find the value of b^2 - 4ac

 If negative, there are no real roots
 
 If zero, there is one real root
 
 If positive, there are two real roots
 
## Determine what the real roots are
1. If there are no real roots

 say that there aren't any real roots

2. If there is one real root

  divide -b by 2a to get the root
3. If there are two real roots

  divide -b by 2a to get the base value
 
  add sqrt(b^2 - 4ac) / 2a to the base value to get one of the real roots
 
  subtract sqrt(b^2 - 4ac) / 2a from the base value to get the other real root

# Differences

* I didn't plug in values for a, b, or c into the entire formula before determining the number or value of roots because I didn't have to use this value in any calculations
* I didn't use the square root around b^2 - 4ac in determining how many real roots there are because it doesn't change the sign of positive or zero values and isn't able to use negative values anyway
* I added a case for when there aren't any real roots to let the user know because it's a requirement