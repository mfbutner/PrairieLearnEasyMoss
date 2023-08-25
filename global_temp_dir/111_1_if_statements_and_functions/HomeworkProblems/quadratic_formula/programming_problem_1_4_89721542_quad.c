#include<stdio.h>
#include<math.h>
double getNumofroots(double a, double b,double c){
	int Numofroots;
	if((b*b-a*c*4)==0){
		Numofroots=1;	
	}
	else if((b*b-a*c*4)>0){
		Numofroots=2;
	}
	else{
		Numofroots=0;
	}
	return Numofroots;
}
double getposroots(double a,double b, double c){
	double x;
	x=(-b+sqrt(b*b-a*c*4))/2/a;
	return x;
}
double getnegroots(double a,double b, double c){
	double x;
	x=(-b-sqrt(b*b-a*c*4))/2/a;
	return x;
}
int main(void){
	double a;
	double b;
	double c;
	int num;
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);
	num=getNumofroots(a,b,c);
	switch(num){
		case 0:
			printf("There are no real solutions\n");
			break;
		case 1:
			printf("There is one real solution: %.2lf\n", getnegroots(a,b,c));
			break;
		case 2:
			printf("There are 2 real solutions\n");
			printf("Solution 1: %.2lf\n", getposroots(a,b,c));
			printf("Solution 2: %.2lf\n", getnegroots(a,b,c));
			break;
		default:
			printf("11");
	} 
	return 0;
	
	

}