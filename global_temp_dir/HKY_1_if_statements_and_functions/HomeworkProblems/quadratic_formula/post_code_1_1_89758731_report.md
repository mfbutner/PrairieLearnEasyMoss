# Algorithm (steps to solve the problem)
## Ask for User Input
    1. Ask the user to input the a, b, and c values
## Check Number of Results
    1. Check if there are zero results
    2. Check if there is only one result
    3. Otherwise, assume there are two results
## Calculate and Print Results
1. Check how many solutions there are
    1. If there are no solutions, tell the user that 
    2. If there's only one solution, just calculate that single solution and tell the user
    3. If there's more than one solution, calculate both solutions and tell the user (making sure to have the greater solution printed first)
    
# Differences
I changed the code regarding printing the solution. Initially, I planned to print the solution separate from the solution-calculating if-statements. However, I realized the number of variable(s) needed to store the solution changed based on how many solutions existed. So, it made more sense to initialize the variable inside the if-statement, then print the result inside the same statement.