# My Algorithm (steps to solve the problem)
1. Get numbers from users
2. Check the delta value
3. Calculate
4. Show users the result

##Get numbers from users
1. Tell them what numbers we want from them
2. Ask for numbers

##Check the delta value
1. Calculate the delta using equation: b^2-4*a*c
2. Check whether the delta is less than or equal to or greater than 0

##Calculate
1. While delta is less than 0

    a. Calculate the first result using equation: (-b + square root of delta) / (2 * a)
    b. Calculate the first result using equation: (-b - square root of delta) / (2 * a)

2. While delta is equal to 0

    a. Calculate the first result using equation: (-b + square root of delta) / (2 * a)
    
3. While delta is greater than 0
    
    a. No calculation since delta is less than 0
    
##Show users the result
1. Show users how many results there are
2. Show them all the results