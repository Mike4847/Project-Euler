#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

bool isTruncatablePrime(int number);
bool isPrime(int integer);

int main()
{
  const int LIMIT = 1000000;
  std::vector<int> truncatablePrimes;

  for (int i = 10; i < LIMIT; i++)
  {
    if (isTruncatablePrime(i))
    {
      truncatablePrimes.push_back(i);
    }
  }

  long long sum = std::accumulate(truncatablePrimes.begin(), truncatablePrimes.end(), 0LL);

  std::cout << "The sum of all Truncatable Primes under 1000000 is\n";
  std::cout << sum << std::endl;

  return EXIT_SUCCESS;
}

bool isPrime(int number)
{
  if (number < 2)
  {
    return false;
  }

  for (int i = 2; i <= std::sqrt(number); i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }

  return true;
}

bool isTruncatablePrime(int number)
{
  std::string numStr = std::to_string(number);
  int len = numStr.length();

  // Check truncations from the left
  for (int i = 1; i < len; i++)
  {
    int leftTrunc = std::stoi(numStr.substr(i));
    if (!isPrime(leftTrunc))
    {
      return false;
    }
  }

  // Check truncations from the right
  for (int i = len - 1; i > 0; i--)
  {
    int rightTrunc = std::stoi(numStr.substr(0, i));
    if (!isPrime(rightTrunc))
    {
      return false;
    }
  }

  return isPrime(number);
}