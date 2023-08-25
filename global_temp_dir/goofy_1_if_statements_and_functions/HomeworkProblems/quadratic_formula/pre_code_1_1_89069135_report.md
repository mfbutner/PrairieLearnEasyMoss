# My Algorithm (steps to solve the problem)
## Start quadratic calculation
1. Set up calculation
2. Calculate

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
3. Annouce root results to user.

## Announce results
1. If the first root equals to the second root,
    * Say there's only one real solution and give either first or second root.
2. But if their values in (b^2) is less than (4*a*c),
    * Say there are no real solutions.
3. Otherwise,
    * Say there are two real solutions and give the first and second root.