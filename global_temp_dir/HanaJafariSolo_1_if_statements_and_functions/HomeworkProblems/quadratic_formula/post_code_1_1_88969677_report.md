# Algorithm (steps to solve the problem)

## part 1: figure out a, b, and c values 
1. assign a value to a
2. assign a value to b
3. assign a value to c

## part 2: evaluate the -b portion of the formula
1. multiply the given b value by -1 to switch its sign to become the "opposite of b"

## part 3: solve the b^2 - 4ac under the square root
1. multiply the given b value by itself and subtract 4 * a * c from that 
2. take note of the resulting value, it is called the discriminant 

## part 4: take the square root of the discriminant 

## part 5: evaluate the denomenator 
1. multiply the given a value by 2, this will be the bottom portion of the full quadratic formula 

## part 6: find how many solutions the formula will yield using the discriminant
1. look at the value of the result from part 3
2. if it is negative, your quadratic has no solutions and no further action needs to be taken 
3. if it is positive, your quadratic has 2 solutions. proceed to part 7. 
4. if it is 0, your quadratic has one solution. proceed to part 7.

## part 7: solve the formula to find the solutions 
1. since the quadratic formula contains a +/- element, split the formula into two separate formulas, one with the + and one with the -
2. for your first solution, add the result from part 2 to the result from part 4 and divide all that by the result from part 5
3. for your second solution, subtract the result from part 2 and the result from part 4 and divide all that by the result from part 5

## part 8: reporting solutions
1. if you had two solutions, report both solutions one and two
2. if you only had one solution, both evalutations in part 7 will yield the same result and you only need to yield that one result

# Differences 
- i forgot to define and explain the concept of the discriminant and how that affects the number of solutions in my original explanation
- this time I more clearly explained how to "flip the sign" of b, which is done by multiplying by -1
- breaking down the explanation further and separating out the different parts of the formula helped to explain the parts in a way that a stupid machine would understand