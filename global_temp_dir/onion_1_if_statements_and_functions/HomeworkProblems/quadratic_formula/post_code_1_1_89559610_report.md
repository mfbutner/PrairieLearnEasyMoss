# Algorithm (steps to solve the problem)

*1.decide the a,b,c value  of equation ax**2 + bx +c

 there is a math equation with the format ax**2 + bx +c. a b c can be any real numbur.
   
   eg 5x**2 + 3x +8    a = 5 b = 3 c = 8
   eg -7** -9x -111    a = -7 b = -9 c = -111
   
   you can use whatever value you like in a b c, the input of a,b,c are doubles
   
   
*2.bring a b c value into the Quadratic equation x**2 = (-b +- (b**2 -4ac)**0.5)/2a
     
     
     Quadratic equation will tell us the possible value of x. There are three posible result for x
     
     ***1 there are two possible different x value
     ***2 there is only one x value
     ***3 thre is two x value but they are not real nunber
   
   for each situation, I create a double called  discriminant = b^2 - 4ac
   
   There are three possible output for solving quadratic equation.
                        two real solutions; if discriminant > 0
                        one real solution, if discriminant == 0
                        and two non-real solutions. if iscriminant < 0
                        
                        
    they I write the if statement coodring to what discriminant is.
    
    
    
*3. print out the solution.

  
   





# Differences

for*1: at first I defined a,b,c as integrals , but I change it to double in the final test. Becasye we know that the result will be priented with decimal point, double will be bertter.
    
    Also, the input cheking system will not put a = 0, which makes situations much easier. I don't need to woory about the error when a = 0



for*2: the settibg up of discriminant makes thing much easier. I search the Quadratic equation in math website, fiding that discriminant could use to write condistional statement. in my original thought, I didnt know how to detect which the result could be, and i decided to let program figure all solution out at first, then write the statement to see :

     if x1 is not to equal to x2, they we print two x
     
     if x1 and x2 are smae, they we just print x
     
     if x has "i" in it, they we do not print the solution.
     
     
     in my original thought, the crtical condition is to see whether the solution of equation are same different or have "i" in it. They i realize that would be complex, and I am not confident about let ccomputer to figure out "i" in math libary. After the revision I use 
     discriminant to see the solution outcome. If discriminant < 0, we can let the computer skip caculating the solution becasue we don't accept the non-real solution afterall.


for*3:There were no differences between my original and current solutions