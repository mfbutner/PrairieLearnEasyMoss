# My quad.c Algorithm 
1. Take user's a, b, and c input
2. Solve the quadratic formula with the user's input
    1. Split the quadratic formula into a positive part and a negative part
    2. Solve the positive portion first
        1. Split the positive portion into two parts, the numerator and the denominator
            1. Solve the numerator first
                1. Combine everything in the square root 
                2. Then, add the square root answer with the -b value
            2. Solve the denominator second
                1. Multiply 2 by the value of a
        2. Afterwards, put the numerator and denominator back together again
        3. Divide the numerator by the denominator 
    3. Solve the negative portion second
        1. Split the negative portion into two parts, the numerator and the denominator
            1. Solve the numerator first
                1. Combine everything in the square root 
                2. Then, subtract the square root answer by the -b value
            2. Solve the denominator second
                1. Multiply 2 by the value of a
        2. Afterwards, put the numerator and denominator back together again
        3. Divide the numerator by the denominator 
3. Display the # of real solutions to the user
    1. Afterward solving both the positive and the negative quadratic formula display the # of real solutions
    that you found
    2. If there are no real solutions, then tell the user that there are 0 real solutions