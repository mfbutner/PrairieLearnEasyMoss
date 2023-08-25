# My Algorithm (steps to solve the problem)
This is a program used to calculate the roots of a quadratic function given in the form $$x = {-b \pm \sqrt{b^2-4ac} \over 2a} $$
We follow the following steps to achieve this goal. 

## Get Input from User
First we ask the user to put in the numbers $a$, $b$, and $c$. The user will type th enumbers which we will use to calculate the roots.
## Calculating the Discriminant
We calculate the discriminant which is given by $\sqrt{b^2-4ac}$. 
## Number of Real Roots
If discriminant is positive, we know that we have two real solutions. If it is zero, we know that we have only one real solution. If it is negative, we have no real solutions. In that case we end the program and print that there are no real solutions. Otherwise, we go to the next step. 

##Calculate Roots
In the case that there are two real solutions, we use the above formula $x = {-b \pm \sqrt{b^2-4ac} \over 2a} $ to calculate both x and we print each one. If there is only one solution we calculate the single solution which is given by  $x = {-b \over 2a} $ and we print it.