# My Quadratic Formula Algorithm Solution


## Find Roots of Quadratic Formula
1) Pick values to plug into the quadratic formula

2) Determine how many real answers there will be

3) Evaluate the formula

## Pick Values
1) Determine 3 different numbers to use, a, b and c, providing ax^2 + bx + c as a reference, where a can never equal 0

## Number of Solutions
1) If the value of b^2 - 4ac is negative, there are 0 real roots for the equation

    	a) If the value is 0, there is one real root

    	b) If the value is greater than 0, there are two real roots

## Evaluate the Formula
1) If there are 0 possible real roots, stop here

2) If there is 1 real root, divide negative b by 2 multiplied by a, or -b/(2a), to find the root and stop there

3) If there are 2 real roots:  

        a) Find the square root of 4 multiplied by a and c subtracted from b squared,  or the square root of b^2 - 4ac  

        b) Negate b and add the square root. Divide by 2 multiplied by a to get the first real root.  

    	c) Negate b and subtract the square root. Divide by 2 multiplied by a to get the second real root.  

## Results of Roots
1) Record each result to two decimal places

# Changes
- Did not end up needing to evaluate the square root to determine number of possible solutions as only the inner expression mattered
- Reordered the substeps so that "Number of Solutions" is before "Evaluate the Formula" to match the order of logic