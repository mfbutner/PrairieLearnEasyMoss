#include <stdio.h>
#include <math.h>

// solve a quadratic problem

int calc(double ax, double bx, double c){
  double neg_bx, under_sqr_root, sqr_bx, divide_by, sqr_root;
  sqr_bx = pow(bx, 2);
  neg_bx = (-1) * bx;
  under_sqr_root = sqr_bx - (4*ax*c);
  divide_by = 2 * ax;
  sqr_root = sqrtf(under_sqr_root);


  if (ax == 0.00 || under_sqr_root < 0.00){
    printf(" There are no real solutions");
  }
  else if (under_sqr_root == 0.00){
    double one_sol = neg_bx / divide_by;
    printf(" There is one real solution: %.2lf", one_sol);

  }
  else {

    double pos_sol, neg_sol;
    pos_sol = (neg_bx + sqr_root) / divide_by;
    neg_sol = (neg_bx - sqr_root) / divide_by;
    printf(" There are 2 real solutions");

    printf("\nSolution 1: %.2lf", pos_sol);

    printf("\nSolution 2: %.2lf", neg_sol );
  }


  
  return 0;
}

int main(){

  double ax, bx, c;
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");

  printf("Please enter a:");
  scanf("%lf", &ax);

  printf(" Please enter b:");
  scanf("%lf", &bx);

  printf(" Please enter c:");
  scanf("%lf", &c);

  calc(ax, bx, c);
}
