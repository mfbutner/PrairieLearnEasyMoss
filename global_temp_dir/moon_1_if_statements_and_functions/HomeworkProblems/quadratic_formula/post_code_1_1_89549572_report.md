# Algorithm (steps to solve the problem)

#Steps to start the equation
1. Get input from the user
2. Calculate the values
    1. Check how many solutions there are
4. announce the results

#Get the input from the user
    1. ask for the a value
    2. ask for the b value
    3. ask for the c value
    
#Calculate the values
    1. get the denominator value by multiplying 2.0 and the a value
    2. **calculate the values inside of the square root**
        1. square the b value (multiply the b value by itself)
        2. multiply the a value, the c value, and 4.0
        3. subtract the squared b value with the multiplied value (4.0*a*c)
    3. **check if the resulting value is negative or not**
        1. if the value is negative
            1. say that there are no real solutions
        2. otherwise, the value is positive
            1. check if the value is zero
                1. if the value is zero
                    1. divide the negative b value by the denominator value
                    2. there is only one real solution
                    3. say the one real solution
                2. otherwise, if the value is not zero
                    1. square root the value inside of the root.
                    2. separate the square rooted value into a negative and a positive of that value
                    3. **calculate the numerator for both the negative and positive value**
                        1. add the negative b value to the negative square rooted number
                        2. add the negative b value to the positive square rooted number
                    4. divide each of the values by the denominator
    
#announce the two solution results
    2. if the two solutions are positive
        1. announce then in the waay they were found
    2. otherwise they are negative or two separate signs
        1. check which of the two values is bigger
        2. say that there are two solutions and say what the two solutions are, with the bigger number first

# Differences
- i decided how to announce the result differently
- rather than announcing the one real solution with the announce results step, I announced it affter finding the one real solution