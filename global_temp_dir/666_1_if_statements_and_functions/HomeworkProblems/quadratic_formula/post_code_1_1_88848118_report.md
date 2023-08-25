# My Algorithm (steps to solve the problem)
1. Get numbers from users
2. Check the delta value
3. Calculate and Show users the result based on the delta value

##Get numbers from users
1. Tell them what numbers we want from them
2. Ask for numbers

##Check the delta value
1. Calculate the delta using equation: b^2-4*a*c
2. Check whether the delta is less than or equal to or greater than 0

##Calculate and Show users the result based on the delta value

1. While delta is equal to 0

    a. Calculate the first result using equation: (-b + square root of delta) / (2 * a)
    b. Show that there is only 1 result and print the result
    
2. While delta is greater than 0

    a. Calculate the first result using equation: (-b + square root of delta) / (2 * a)
    b. Calculate the first result using equation: (-b - square root of delta) / (2 * a)
    c. Show that there are 2 results and print all the results
    
3. While delta is less than 0
    
    a. No calculation since delta is less than 0
    

# Differences
Combine the calculate part and show the result part since every calculation have different output result.

ALso the mathematic logic is wrong. The correct version is: 2 result when delta is greater than 0 and no result when delta is less than 0.