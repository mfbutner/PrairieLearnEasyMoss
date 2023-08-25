#include<stdio.h>
#include<math.h>

//This program is used to find how much roots we have and the results of roots.

//Set up a function to ditermine that how many roots we have
int how_much_root(double numA, double numB, double numC)
{
    double Dnum;
    int condition;
    condition = 0;

    // Use the Discriminant function to find if we have roots or not.
    Dnum = pow ( numB,2 ) - 4 * numA * numC;

    //When D > 0, we have 2 roots
    if (Dnum > 0)
    {
        condition = 2;
        return condition;
        //have two solution
    }

    //When D = 0, we have 1 root.
    else if (Dnum == 0)
    {

        condition = 1;
        return condition;

    }

    //WHhen D = 0, we have no roots.
    else if (Dnum < 0)
    {

        condition = 0;
        return condition;
    }

    return 0;
}

//Set up a function to calculate the roots.

// Root1 calculation
double calculateroot1(double numA, double numB, double numC)
{
    double solution1  = ( ( (numB) * (-1) ) + ( sqrt( (pow(numB,2) - 4 * (numA*numC))))) / (2 * numA);
    return solution1;
}

// Root2 calculation
double calculateroot2(double numA, double numB, double numC)
{
    double solution2  = ( ( (numB) * (-1) ) - ( sqrt( (pow(numB,2) - 4 * (numA*numC))))) / (2 * numA);
    return solution2;
}


// The following part is used to choose and display the results.
int main()
{
    // Set up the variables
    double root_num, numA, numB, numC;
    double root1, root2;

    // Ask the questions and get all three numbers
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&numA);
    printf("Please enter b: ");
    scanf("%lf",&numB);
    printf("Please enter c: ");
    scanf("%lf",&numC);

    // Store the root number in a variable
    root_num = how_much_root(numA, numB, numC);

    // To display different cases

    // The first one is that we have two roots
    if (root_num == 2)
    {
        root1 = calculateroot1(numA, numB, numC);
        root2 = calculateroot2(numA, numB, numC);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n",root1);
        printf("Solution 2: %.2lf",root2);
        return 0;

    }

    // The second one is that we have one root.
    else if(root_num == 1)
    {
        root1 = calculateroot1(numA, numB, numC);
        printf("There is one real solution: ");
        printf("%.2lf",root1);
        return 0;

    }

    // The last one is that we don't have any roots.
    else if(root_num == 0)
    {
        printf("There are no real solutions");
        return 0;
    }
}