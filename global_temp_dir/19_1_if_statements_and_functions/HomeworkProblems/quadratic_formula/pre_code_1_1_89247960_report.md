# My Algorithm (steps to solve the problem)
## Get the info
1. Ask the users for values for a, b, and c so we can plug them into the formula
2. Check if there will be no solutions, one solution or two solution 

## None Solutions
1. Check if b^2-4ac is negative 
2. If negative then conclude that there are no solutions 
3. Print no solution. 

## One Solutions
1. Check if b^2-4ac is zero
2. If it is zero then just -b/a
3. Return the value 

## Two Solutions 
1. If b^2-4ac is not zero nor negative 
2. Then just add  b^2-4ac to -b and then divide to 2a (print this first)
3. Then just subtract b^2-4ac to -b and then divide to 2a
4. Print the two values 

## Return the value(s)
1. Determine how many values there are to return 
2. Return the values or state that there are no solutions