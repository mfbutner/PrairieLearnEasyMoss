# Quadratic Formula(steps to solve the problem)

# Differences

##Determine all the real of the quadratic formula
- Instead of using the term "solutions", I decided to use "real solutions", as it was more accurate to what the prompt was looking for
1. Ask the user for values for letters a, b, and c of the quadratic equation 
2. Determine how many real solutions there are to the quadratic formula
3. Announce the solutions and what they are

##Determine the number of solutions to the quadratic formula 
- I decided to put the different checks of whether the discriminant was negative, 0, or any other value in accessing order, as it is more efficient, as the computer no longer has to look through each possible condition separately, and instead only check the given conditions until it finds one that is True.
1. Calculate the discriminant 
    1. If the discriminant is negative
        1. The quadratic equation has 0 real solutions
    2. But if the discriminant is equal to 0
        1. The quadratic formula has one real solution
    3. Any another value for the discriminant 
		- Instead of checking to see if the discriminant is positive, I decided to make the condition so that if the discriminant is anything other than negative or zero, as this would mean the discriminant would have to be positive and the quadratic equation could only have two real solutions
        1. The quadratic equation has two real solutions  

2. Based on the number of real solutions, announce them 

##Calculate the real solutions/ real roots of x 
	
- I decided to add a function to calculate the real solutions/ real roots of x separately,
	so that my code wouldn't look as repetitive 

	1. If the first solution of the equation is being calculated
		1. Calculate the positive value first
	2. If there is any other solution that isn't the first that is being calculated
		2. Calculate the negative value 

##Announce real solutions

- I decided to but the different checks of whether the equation had no solutions, 1, or two in ascending order, as it is more efficient when the computer is looking to see what condition is true
1. If there were no real solutions
    1. Say there were no real solutions
2. But If there was one solution
    1. Say there was one real solution
    2.  Calculate the value of the one solution, and say what it was
3. If there are any other number of real solutions
	- I decided to set the condition to if there is any other number of real solutions, as the only other possible number of real solutions possible that aren't zero or one, is two
	- I also decided to calculate the first and/or second real solutions of the equations separately, as not every equation is going to have a second real solution.  

    1. Say there were two real solutions
    2. Calculate the value of the first real solution and say what it is
    3. Calculate the value of the second real solution and say what it is