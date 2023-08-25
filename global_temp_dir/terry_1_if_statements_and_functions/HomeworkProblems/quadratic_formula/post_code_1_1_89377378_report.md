# Algorithm (steps to solve the problem)

1)	Solve Quadratic Equation

* Ask user for input.

* Solve problem.

2)	Ask user for input

* Let the user input A,B,C which represent the coefficients of the polynomial Ax^2 + Bx + C. 

3)	Solve the problem

* Solve the discriminant first (part under the square root)

* Solve the numerator with a positive square root of the discriminant

* Solve the numerator and denominator

* Solve the numerator with a negative square root of the discriminant

* Solve the numerator and denominator

* Give back the real values

4)	Solve the discriminant.

* Take the value B and square it

* The 4 times A times C from the squared value of B

* Check to see if discriminat is positive or equal to zero

5)	Solve the numerator with a positive square root. 

* If the discriminant is greater zero, take the negative of B and add the value received in part 4

6)	Solve the numerator and the denominator

* Take the value received in part 5 and divide it by 2 times A

7)	Solve the numerator with a negative square root. 

* If the discriminant is greater than zero, take the negative of B and subtract the value received in part 4

Solve the numerator and the denominator

* Take the value received in part 5 and divide it by 2 times A

8)	Check if discriminant is zero

* If the discriminant is zero, then calculated the negative of B divided by 2 times A. 

9)	Give back real values

* if discrimant is negative, give back no values

* if discriminant is zero, give back the one value calculated in step 8)

* if discriminant is positive, give back both values calculated in step 5) and 7). 

# Differences

* I forgot to consider that we only return the real values, I have adjusted the code to take this into account based on whether the discriminant is negative, zero, or positive.