
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isPrime(int number)
{
  if (number < 2)
  {
    return false;
  }
  for (int i = 2; i < number; i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  return true;
}

bool isCircularPrime(int number)
{
  std::string numberInString = std::to_string(number);

  for (int i = 0; i < numberInString.length(); i++)
  {
    std::string rotatedString = numberInString.substr(i) + numberInString.substr(0, i);

    int rotatedNumber = std::stoi(rotatedString);

    if (!isPrime(rotatedNumber))
    {
      return false;
    }
  }
  return true;
}

int main()
{
  const int MAX = 1000000;

  int count = 0;

  for (int i = 0; i < MAX; i++)
  {
    if (isCircularPrime(i))
    {
      count++;
    }
  }

  std::cout << "The number of circular Primes below \t" << MAX << "is\n"
            << count;
}