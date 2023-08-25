#include <stdio.h>
#include <math.h>

double calculateDeterminant(double a, double b, double c);

int main(void) {

	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

	double a, b, c;
	printf("Please enter a : ");
	scanf("%lf", &a);
	printf("Please enter b : ");
	scanf("%lf", &b);
	printf("Please enter c : ");
	scanf("%lf", &c);

    double solution1;
    double solution2;
    double solution3;

    if( ( (b * b) - (4 * a * c) ) > 0){
        printf("There are 2 real solutions \n");
        solution1 = (-b + sqrt ( (b * b) - (4 * a * c) ) ) / (2*a);
        solution2 = (-b - sqrt ( (b * b) - (4 * a * c) ) ) / (2*a);
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
    }
    else if ( ( (b * b) - (4 * a * c) ) == 0){
        solution3 = (-b) / (2 * a);
        printf("There is one real solution: %.2lf", solution3);

    }
    else if ( ( (b * b) - (4 * a * c) ) < 0){
        printf("There are no real solutions\n");
    }
    return 0;
}
