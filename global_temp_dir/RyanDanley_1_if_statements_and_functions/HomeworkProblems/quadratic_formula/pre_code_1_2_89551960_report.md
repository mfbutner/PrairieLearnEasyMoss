##Introduction

This problem involves writing a program that finds the roots of the quadratic equation. The equation has the form ax^2 + bx + c = 0, where a, b, and c are variables entered by the user. Depending on the values of a, b, and c, there may be 0, 1, or 2 real solutions. The program should print out the real roots of x if there are any.

##Approach To Problem

The program will ask the user for the values of variables a, b, and c. Then, it will use these values to calculate the roots of the equation. Finally, it will display the real roots of x if any exist.

###Steps:

1. Prompt the user for the values of a, b, and c
2. Calculate the discriminant, which is given by the formula b^2 - 4ac
3. Check the value of the squared part of the numerator
4. If the sqaured part of the numerator is positive, there are two real roots
5. If the sqaured part of the numerator is zero, there is one real root
6. If the sqaured part of the numerator is negative, there are no real roots
7. Calculate the real roots of x
8. Display the real roots of x