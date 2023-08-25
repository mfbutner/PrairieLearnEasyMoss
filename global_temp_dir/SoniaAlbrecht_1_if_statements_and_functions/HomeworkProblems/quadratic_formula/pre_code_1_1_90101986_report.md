# My Algorithm (steps to solve the problem)
1. Obtain the constants from the quadratic equation
2. Plug the constants into the quadratic formula
3. List the roots

## Obtain the constants fron the quadratic equation 
1. Note the constant that is not multiplying a variable, call it c
2. Note the constant multiplying the variable raised to the first power, call it b
3. Note the constant multiplying the variable raised to the second power, call it a

## Plug the constants into the quadratic formula
1. Raise b to the second power
2. Multiply 4 times a times c
3. Subtract the result from step 2 from the result from step 1
4. If the result from step 3 is negative, skip the rest of this section and go directly to the "List the roots" section
5. Take the square root of the result from step 3
6. Add the result from step 4 from -b
7. Multiply a by 2
8. Divide the result from step 5 by the result from step 6
9. If the result from step 3 is not 0
    1. Subtract the result from step 4 from -b
    2. Divide the result from the previous step by the result from step 6

## List the Roots
1. If the result from step 3 of the second section is negative, inform the user that there are no real solutions
2. If the result from step 3 of the second section is zero, inform the user that there is one real root and that it is 
the result from step 7 of the second section
3. If the result from tep 3 of the second section is greater than zero, inform the user that there are 2 real solutions 
    1. Solution 1 is the result from step 7 of the second section
    2. Solution 2 is the result from the second step in step 8 of the second section