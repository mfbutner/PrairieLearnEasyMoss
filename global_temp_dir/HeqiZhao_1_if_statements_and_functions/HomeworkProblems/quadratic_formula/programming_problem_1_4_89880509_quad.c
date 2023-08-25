#include<stdio.h>
#include<math.h>


int main() {
	
	/*get three inputs. the a,b,and c. Then set two solutions*/
	double a;
	double b;
	double c;
	double sol1;
	double sol2;

	/*print the needed texts, and at the same time, scan the three inputs*/
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);

	/*Realizing there would be three different results by doing the quadratic equation. When the b^2-4ac is smaller than zero, there would be no solution. Equal to zero, one solution. Greater than zero, two different solution*/
	/*so what I am doing here is using the if loop to print the corresponding text and get the corresponding results*/
	if (pow(b, 2) - 4 * a * c  < 0) {
		printf("There are no real solutions");
	}else if (pow(b, 2) - 4 * a * c == 0) {
		sol1 = ((0-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2*a);
		printf("There is one real solution: %.2lf", sol1);
	}else {
		sol1 = ((0-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2*a);
		sol2 = ((0-b) - sqrt(pow(b, 2) - 4 * a * c)) / (2*a);
		printf("There are 2 real solutions\n");
		printf("Solution1: %.2lf\n", sol1);
		printf("Solution2: %.2lf\n", sol2);
	}
	
	/*The end.*/


	return 0;
}
