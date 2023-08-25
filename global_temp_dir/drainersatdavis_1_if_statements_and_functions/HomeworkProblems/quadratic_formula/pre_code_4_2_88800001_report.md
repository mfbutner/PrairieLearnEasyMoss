# My Algorithm (steps to solve the problem)

## Determine the real roots of a quadratic equation
1. Get user input for the values of a, b, and c.
2. Determine the number of real roots from the values of a, b, and c.
3. If there is at least one real root
    1. Calculate the root(s).
    2. Display the root(s).
4. Else 
    1. Let the user know that there are no real roots.

## Determining the number of real roots from a, b, and c
1. To determine the number of real roots, calculate the discriminant from
a, b, and c.
2. If the discriminant is less than 0, then there are no real roots. 
3. Else, if the discriminant is equal to 0, then there is one real root. 
4. Else, if the discriminant is greater than 0, then there are two real roots.

## Calculating the discriminant
1. Square b.
2. Subtract b^2 by the product of 4, a, and c.

## Calculating the real roots
1. If there is one real root 
    1. Calculate the root by first multiplying b by -1.
    2. Add the discriminant (see calculating the discriminant) to b times -1.
    3. Divide the sum from step 2 by 2 times a.
2. If there are two real roots
    1. Calculate one of the roots by first multiplying b by -1.
    2. Add the discriminant (see calculating the discriminant) to b times -1.
    3. Divide the sum from step 2 by 2 times a. You now have one of the real roots.
    4. Calculate the other root by first multiplying b by -1.
    5. Subtract the discriminant (see calculating the discriminant) to b times -1.
    6. Divide the sum from step 5 by 2 times a. You now have the other root.

## Displaying the root(s)
1. If there is one real root
    1. Display the root.
2. If there are two real roots
    1. Display the root calculated by adding the discriminant first.
    2. Display the other root.