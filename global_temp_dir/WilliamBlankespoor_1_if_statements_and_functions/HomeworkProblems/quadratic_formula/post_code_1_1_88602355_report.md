# Algorithm (steps to solve the problem)
##Get the inputs from the user
1. Request a value for a and write it down
2. Request b value for b and write it down
3. Request c value for a and write it down
##Calculate the discriminant
1. Calculate and store the discriminant using the formula b^2 - 4ac
##If the discriminant is less than 0 there are no real solutions
1. Say there are no real solutions
##Otherwise, if the discriminant equals 0 there will be one solution
1. Output the one solution calculated using (-b + square root of the discriminant) / (2a)
##Otherwise, there are two solutions
1. Output the first solution calculated using (-b + square root of the discriminant) / (2a)
2. Output the second solution calculated using (-b - square root of the discriminant) / (2a)
# Differences
* Restructered the process after the discriminant calculation
* This is a more logical flow, with the discriminant being calculated and then things happening 
based on that
* My first explanation was more chaotic with things happening in different places rather than all just being based on the discriminant calculation