# Algorithm (steps to solve the problem)
## Return the real roots of a quadratic equation
    1. Derive the quadratic equation from the user
    2. Determine the real roots of the quadratic function they entered
    
## Derive the quadratic equation from the user
    1. Ask the user to enter a from the equation format ax^2 + bx + c
    2. Ask the user to enter b from the equation format ax^2 + bx + c
    3. Ask the user to enter c from the equation format ax^2 + bx + c

## Determine the real roots of the quadratic function they entered
    1. Calculate the discriminant
    2. Calculate the roots through the quadratic formula
    3. Determine the number of roots and display them
    
## Calculate the discriminant
    1. Pass the a, b, and c coefficients
    2. Get the discriminant by putting them through the formula b^2 - 4ac
    
## Calculate the roots through the quadratic formula
    1. Calculate the root with the + sign from the quadratic formula
    1. Calculate the root with the - sign from the quadratic formula
    
## Calculate the root with the + sign from the quadratic formula
    1. Pass the a, b, and c coefficients entered by the user 
    2. Put them through the formula (-b + squareroot(b^2 - 4ac)) / 2a
    
## Calculate the root with the - sign from the quadratic formula
    1. Pass the a, b, and c coefficients entered by the user
    2. Put them through the formula (-b - squareroot(b^2 - 4ac)) / 2a
    
## Determine the number of roots and display them
    1. Test if there are 2 real solutions
    2. Test if there is 1 real solution
    3. Test if there are no real solutions
    
## 2 real solutions
    1. If the call to the discriminant function is greater than 0
        1. There are 2 real solutions
        2. Display the roots associated with both the + sign and - sign from the quadratic formula

## 1 real solution 
    1. If the call to the discriminant function is equal to 0
        1. There is one real solution
        2. Display a root associated with either sign from the quadratic formula 
        
## 0 real solutions
    1. If the call to the discriminant function is less than 0
        1. There are no real solutions

# Differences
- I didn't need to put the variables together and assemble the function 
- Didn't opttimize the discriminant to determine how many roots there were
    - Was really vague about(just plug in and see if non-imaginary)
- Overall, didn't think through any of minute steps it would take to actually determine how many solutions and what they solutions were