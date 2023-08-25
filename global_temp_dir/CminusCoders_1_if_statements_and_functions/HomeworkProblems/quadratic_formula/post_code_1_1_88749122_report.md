# Algorithm (steps to solve the problem)

# Differences

Maxim Saschin

For: quad.c

## 1. Prompt the user
- Tell the user: "The quadratic equation is in the form a*x^2 + b * x + c"

## 2. Ask the user for three numbers
- These numbers can be decimal numbers or whole numbers (positive or negative)
1. Ask the user to enter the first number (this number will be "a").
2. Ask them to enter a second number (this number will be "b").
3. Ask them to enter a third and final number (this number will be "c").

## 3. Calculate and check the inside of the square root
1. Using the numbers the user provided, plug in those numbers to calculate only the portion of the quadratic formula that is inside the square root.
2. Check if that calculation is greater than zero. If it is, move onto part 4. 
3. If the calculation is not greater than zero, check if it is equal to zero. If it is, we can move onto part 5. 
4. If the calculation is not greater than or equal to zero, we can move onto part 6.  

## 4. If the calcuation from part 3 is greater than zero
1. Solve the quadratic formula but with a "+" outside the square root portion of the forumla. We will call this "solution one". 
2. Solve the quadratic formula again, but with a "-" outside the square root portion of the formula. We will call this "solution two". 
2. There are now two distinct real solutions. 
3. We can finish by saying: "There are two real solutions", and then we show "solution one" and "solution two". 

## 5. If the calculation from part 3 is equal to zero
1. Remove the entire square root portion of the quadratic formula (It is equal to zero so we no longer need it in our equation).
2. Solve this new version of the formula. 
2. There should be one real solution.
3. We can finish by saying: "There is one real solution", and then show "solution one". 

## 6. If the calcuation from part 3 is not greater than or equal to zero
1. We can conclude by saying "there are no real solutions"