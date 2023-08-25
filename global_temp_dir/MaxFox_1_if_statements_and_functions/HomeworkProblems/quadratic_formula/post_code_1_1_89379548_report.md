# Algorithm (steps to solve the problem)

## Find the Roots of a Quadratic Equation
1. Get the Equation
2. Determine the Roots
3. State the Roots

##Get the Equation
1. Ask the person for the equation they want solved in standard form

##Determine the Roots
1. Determine if the roots will be real 
2. If there will not be real roots, do as follows:  
*Tell the person that there aren't any real roots and call it a day
3. Otherwise:  
*Calculate the Roots

##Determine if the Roots will Be Real
1. Solve this equation with the associated values: b^2 - 4(a)(c)
2. If the result of that equation is negative:  
*there will be no real roots
3. Otherwise,  
*there will be real roots 

##Calculate the Roots
1. Multiply the value of "b" by -1 and save that value for later in the calculation
2. Take the square root of the equation b^2 - 4(a)(c) and save that for later on 
3. Multiply the value of "a" by 2 and save that value
4. Add the value from step 1 to the value in step 2, then divide by the value in step 3, storing this as one of your roots
5. Subtract the value from step 2 from the value from step 1, then divide by the value in step 3; storing this as your second root

##State the Roots
1. See if the two roots are the same so you don't give a repetive answer
2. If they are the same:  
*give only one of them as the answer 
3. Otherwise:  
*Give both roots as an answer 

# Differences

-The first difference comes in the "Determine the Roots" header. Here, I created a conditional statement that has two steps instead of just one: if the roots are not real then tell the person and stop, otherwise, calculate the roots. Before, my algorithm said to only do something if the roots were real and not if they weren't real (which I had planned to handle later in the algorithm). However, in the actual solution, it made no sense to continue going through the alogorithm when it was obvious that there would be no real solutions, so in this part of the algorithm, I changed it to have it tell the person that there are simply no answers. 

-The second difference comes in the header "State the Roots." Related to the previous point, I removed the part about telling the person if the roots weren't real since I handled that earlier in the algorithm. I then also added some behavior: instead of just telling the user what the roots are, I now have the reader of the algorithm check if the roots are the same thing before giving back a response to make sure there is no repition. Only after this can the root or roots be given back to the person.