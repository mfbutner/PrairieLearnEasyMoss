# My Algorithm (steps to solve the problem)

Maxim Saschin

For: quad.c

## 1. Prompt the user
- Tell the user: "The quadratic equation is in the form ax^2 + bx + c"

## 2. Ask the user for three numbers
- These numbers can be decimal numbers or whole numbers (positive or negative)
1. Ask the user to enter the first number (this number will be "a").
2. Ask them to enter a second number (this number will be "b").
3. Ask them to enter a third and final number (this number will be "c").

## 3. Create the calculation (write out the quadratic formula)
- Based on the user's number choices, we must now find x in the quadratic equation. We can use the quadratic formula to find these x values. 
1. Write out the quadratic formula using letters "a", "b", and "c". In this formula, keep the square root portion positive. 
2. Re-write the quadratic formula again with the three letter variables but this time, put a negative infront of the square root portion. 
3. We now have two quadratic formulas (one with positive square root and one with negative square root).

## 4. Plug in user chosen numbers into the formulas
- First, we are going to use the first (positive square root) quadratic formula we wrote in part 3. 
1. Replace the "a" variable in the formula with the first number the user chose. 
2. Plug in the second number the user chose in place for "b". 
3. Plug in the last number the user chose for variable "c". 
4. After all the user numbers are substituted, calculate the answer (round to 2 decimal places).
    5. Repeat steps 1-4 but with the second (negative square root) quadratic formula we created in part 3. 
    
## 5. Validate and check the answers
- For both solutions we got in part 4, we must check if they are real numbers. 
1. Check if the solution for the first formula is a real number. 
2. Check if the solution for the second formula is a real number. 
3. If both solution one and two are real numbers, check if solution one is the same as solution two. If they are equal we can just combine both as: "solution one". 

## 7. Show the answers
1. If neither of the solutions are real numbers, we can say "there are no real solutions".
2. If one of the two solutions is a real number, we can say "there is one real solution:", then we show the solution.
3. If both of the solutions are real numbers, we can say "there are two real solutions:", then we show solution one, followed by solution two.
4. If both of the solutions are the same, we can say "there is one real solution:", then we show solution one.