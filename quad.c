/* This program will identify and print the real roots of any quadratic equation in the form ax^2 + bx + c */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/* QuadraticForumula will take 3 doubles (a,b,c) for the 3 numeric values in the quadratic equation and bool sign: true for + and false for -. The function then will use the quadratic formula to calculate the roots of the equation, and will return the real root found as a double.*/

double QuadraticFormula(double a, double b, double c, bool sign) {

  double underSqrRoot = (pow(b, 2)) - (4 * a * c);
  double numerator;

  if (sign) {
    numerator = (-1 * b) + sqrt(underSqrRoot);
  } else {
    numerator = (-1 * b) - sqrt(underSqrRoot);
  }

  double denominator = 2 * a;

  return numerator / denominator;
}

/* IsReal will take 3 double parameters a,b, and c (the 3 numeric values of the quadratic equation) and plug them in under the square root and into the denominator to check if the root is real. If the root is real, it will return true, if not, it will return false.*/

bool IsReal(double a, double b, double c) {
  double underSqrRoot = (pow(b, 2)) - (4 * a * c);

  if (underSqrRoot < 0) {
    return false;
  }

  if (2 * a == 0) {
    return false;
  }
  return true;
}

int main(void) {
  double a;
  double b;
  double c;
  double root1;
  double root2;
  int numSolutions;

  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
  printf("Please enter a: ");
  scanf("%lf", &a);
  printf("Please enter b: ");
  scanf("%lf", &b);
  printf("Please enter c: ");
  scanf("%lf", &c);

  if (IsReal(a, b, c) == true) {
    root1 = QuadraticFormula(a, b, c, true);
    root2 = QuadraticFormula(a, b, c, false);
    if (root1 == root2) {
      numSolutions = 1;
    } else {
      numSolutions = 2;
    }
  } else {
    numSolutions = 0;
  }

  if (numSolutions == 0) {
    printf("There are no real solutions");
  } else if (numSolutions == 1) {
    printf("There is one real solution: %.2lf", root1);
  } else {
    printf("There are %d real solutions\n", numSolutions);
    printf("Solution 1: %.2lf\n", root1);
    printf("Solution 2: %.2lf\n", root2);
  }
  return 0;
}