# My Algorithm (steps to solve the problem)

## Set Up Questions 

1. Declare variables at the top make a,b,c a double and declare the roots and discriminant
2. Make the variable discriminant equal to 0.0
3. Show user the quadratic formula 
4. Ask user to input a number for a,b,c then read the inputs

## Solving the problem 
1. Use calculation method for the discriminant
2. If the the discriminant is less than 0 then program will print and say that there are no real solutions
3. If the discriminate is equal to to zero then it will calculate the root (refer to math solving section) and then print out that there is one solution
4. If there is anything else different then we will calculate the first root and second root (refer to math solving section) then print out that there are two real solutions 

## Math problem solving 

1. If the discriminant is 0 and there's only one solution do this step but if not do steps 2-6, create a variable called root and convert it into a double; this will equal negative (B input) divided by 2 times A
2. For the first root we will get a negative 1 and multiply it by the (B) input. 
3. Then we will add this to the squareroot of the discriminant.
4. Lastly, we will divide these two equations by 2 times by (A) input
5. Repeat these steps for the second root but instead of adding we will subtract in the beginning instead
6. When this runs the output of the program will say there are two real solutions and print those two solutions out 

# Differences 
1. Added the rest of the variable at the top of the program instead of only one to make variable clearer
2. Made the discriminant equal to 0.0 to avoid any errors