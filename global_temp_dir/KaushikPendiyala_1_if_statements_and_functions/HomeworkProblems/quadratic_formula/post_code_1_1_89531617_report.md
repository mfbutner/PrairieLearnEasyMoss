# Algorithm (steps to solve the problem)

## Solve Quadratic Formula
       1. Setup Problem
       2. Determine How Many Solutions There Are
       3. If There Are Solutions
            4. Solve Numerator
            5. Solve Denominator
            6. Divide Numerator and Denominator
       4. Print solutions To The User

## Setup Problem
       1. Take input from user for the quadratic equation
       2. Store User-Inputted values for a, b, and c
       
## Determine How Many Solutions There Are 
       1. If b^2<4ac
            2. No Solutions
       2. If b^2=4ac
            2. One Solution
       3. Else
            2. Two Solutions
       
## Solve Numerator
       1. Use the equation -b+sqrt(b^2-4ac)
            1. Store the value in the variable 'Numerator'/'Numerator Positive'
       1. Use the equation -b-sqrt(b^2-4ac) (IF APPLICABLE)
            1. Store the value in the variable 'Numerator Negative'
            
## Solve Demoninator
       1. Store the resulting value of 2*a in the variable 'Denominator'
       
## Divide Numerator and Denominator
       1. Divide Numerator Positive by Denominator and output the value
       2. Divide Numerator Negative by Denominator and output the value

# Differences
    1. I was able to find a more effient way of coding the problem which led to some changes
        1. Instead of determining if the value inside the square root was imaginary, I could 
            first find how many solutions there were to remove that step
        3. Based on how many solutions there were, I could just run a different function
            instead of doing uncessary calculations