# My Algorithm (steps to solve the problem)

## Solve Quadratic Formula
       1. Setup Problem
       2. Solve Numerator
       3. Solve Denominator
       4. Divide Numerator and Denominator

## Setup Problem
       1. Take input from user for the quadratic equation
            1.Repeat step until valid input is given from user
       2. Store User-Inputted values for a, b, and c
       
## Solve Numerator
       1. Use the equation -b+sqrt(b^2-4ac)
            1. Determine whether number inside sqrt is imaginary or not
            2. If not imaginary:
                1. Store the value in the variable 'Numerator Positive'
       1. Use the equation -b-sqrt(b^2-4ac)
            1. Determine whether number inside sqrt is imaginary or not
            2. If not imaginary:
                1. Store the value in the variable 'Numerator Negative'
                
## Determine if sqrt(b^2-4ac) is imaginary
       1. If b^2-4ac < 0:
            1. It is imaginary
            
## Solve Demoninator
       1. Store the resulting value of 2*a in the variable 'Denominator'
       
## Divide Numerator and Denominator
       1. Divide Numerator Positive by Denominator and output the value
       2. Divide Numerator Negative by Denominator and output the value