# My algorithm (steps to solve the problem)

## Assigning values to a b and c
1. the given polynomial expression will be in the format ax^2 + bx + c where a is the coefficient of the x^2, b is the coefficient of x and c is the remaining constant 
2. these values must be defined before you can proceed 

## Setting up the quadratic formula
1. divide the formula into its smaller parts: -b, +/- square root of b^2 -4ac, and dividing by 2a

## what is "-b"?
1. in the original polynomial, the b value will have a corresponding sign
2. plug in the opposite signed b as what was originally in the polynomial in the spot occupied by "-b" in the quadratic formula

## +/- square root of b^2 -4ac
1. multiply the original b value from the polynomial by itself, also known as squaring it. consider this result as "value 1"
2. multiply the a value by the c value, then multiply that result by 4. consider this result as "value 2"
3. subtract value 2 from value 1 and call that result "value 3"
4. take the square root of value 3
5. split your one quadratic formula into two separate formulas, calling them "formula 1" and "formula 2"
6. in formula 1, add value 3 to the "-b" from the previous section in order to form the numerator of the quadratic formula
7. in formula 2, subtract value 3 from the "-b" from the previous section in order to form the numerator of the quadratic formula

## 2a, the denomenator 
1. multiply the a value by 2
2. set that result as the denomenator for both formula 1 and formula two
3. solve each formula independently of the other by dividing the numerator by the denomenator
4. you should now have two different results, both are correct and will evaluate the original polynomial to 0 when plugged in for x