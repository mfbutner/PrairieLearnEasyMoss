# Find The Roots of a Quadratic
#### 1. Ask the user to type in the values of the quadratic equation
#### 2. Calculate the Discriminant
#### 3. Check how many solutions the quadratic has


# Ask the user to type in the values of the quadratic eqution
#### 1.  User enters in the values for "a", "b", and "c" for the general equation ax^2 + bx + c

# Calculate the Discriminant (determines how many solutions there are)
#### 1. calculate the discriminant given the user input values for a, b, and c
##### - Formula: b^2 - 4ac

# Check how many solutions the quadratic has
#### 1. If the discriminant is less than 0, there are no real solutions
##### - Tell the user there are no real solutions

#### 2. But if the discriminant is equal to 0, there is one solution
##### - Calculate the solution
###### Formula: -b/2a
##### - Tell the user there is one solution

#### 3. Otherwise, if the above two conditions fail, then there are two real solutions
##### - Calculate the two real solutions

# Calculate the two real solutions
#### 1. Positive solution
##### (-b + sqrt(discriminant)) / (2 * a)

#### 2. Negative solution
##### (-b - sqrt(discriminant)) / (2 * a)

#### 3. Tell the user the solutions