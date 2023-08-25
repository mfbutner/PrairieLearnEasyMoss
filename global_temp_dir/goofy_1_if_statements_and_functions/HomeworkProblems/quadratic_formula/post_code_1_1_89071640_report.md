# Algorithm (steps to solve the problem)
# Differences
1. A little mistake with the ordering of my original plan in terms of formatting. Under "Set up", after setting up calculation, I went straight to "Announce results", but of course, did the calculations first.
2. When there are existing root(s) (at least one real solution), the root is given to two decimal places following after the decimal point as stated in prompt. In real life, it'd be arbitrary for the person calculating the roots, to know how many places after the decimal is wanted/needed.

## Start quadratic calculation
1. Set up calculation
2. Announce results
    * Calculate first

## Set up calculation
1. Ask user for values through variables a, b, and c in the form of a quadratic equation: (ax^2 + bx +x).
2. Set up/write out the quadratic equation for the first root (plus): (-b+sqrt(b^2-4*a*c))/(2*a).
3. Set up/write out the quadratic equation for the second root (minus): (-b-sqrt(b^2-4*a*c))/(2*a).

## Calculate
1. Use the user's values for a, b, and c into the quadratic equation for the first root.
     * Evaluate for first root.
     * Set aside the first root.
2. Use in the user's values for a, b, and c into the quadratic equation for the second root.
     * Evaluate for second root.
     * Set aside the second root.

## Announce results
1. Calculate roots.
2. If the first root equals to the second root,
    * Say there's only one real solution and give either first or second root. Include in root two decimal places after the decimal point.
3. But if their values in (b^2) is less than (4*a*c),
    * Say there are no real solutions.
4. Otherwise,
    * Say there are two real solutions and give the first and second root. Include in each root two decimal places after the decimal point.