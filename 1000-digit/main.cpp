#include <iostream>
#include <cmath>

/*
  ! Problem definition:
  1. Calculate the n-th fibonacci number(F_n) using Binets closed-form formula.
    F_n = ((1 + 5**0.5)^n - (1 - 5**0.5)^n )/2^n * 5**0.5
  2. find the # of digits d(x) of the number (F_n) by usng the formula = |__log_10 F_n __|(floor) + 1
  3. if (d(x) != 1000) return to 1.

*/

// * function to calculate the n-th Fibonnacci

int main()
{
  // function to find the number of digits of a number

  double nThFibonacci(int n);
  size_t numOfDigits(double fibonacci);

  return 0;
}

double
nThFibonacci(int n)
{

  /*
  ((1 + sqrt(5))**n - (1 - 5**0.5)**n )/(2**n * 5**0.5)
  */
  // double fibonacci = (pow((1 + sqrt(5)), n) - pow((1 + sqrt(5)), n)) / (pow(2, n) * sqrt(5));

  return (pow((1 + sqrt(5)), n) - pow((1 + sqrt(5)), n)) / (pow(2, n) * sqrt(5));
}

size_t
numOfDigits(double fibonacci)
{ // the idea of getting the individual digit length of a number n found by
  // floor(log10(n)) + 1

  return static_cast<size_t>(floor(log10(fibonacci)) + 1);
}