#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <array>
#include <numeric>

// todo:
bool isPanDigital(std::string number);
bool isSubstrDivisible(std::string number);
void generatePandigitals(std::string current, std::vector<bool> &used,
                         std::vector<long long> &results, int position);

int main()
{

  const long long LIMIT = 10000000000;
  long long number;

  std::vector<int> answer;

  for (number = 1000000000; number < LIMIT; number++)
  {
    if (isPanDigital(std::to_string(number)) && isSubstrDivisible(std::to_string(number)))
    {
      answer.push_back(number);
    }
  }

  std::cout << "The sum of all 0 -9 pandigital numbers that are substring divisible is"
            << std::accumulate(answer.begin(), answer.end(), 0) << std::endl;

  return EXIT_SUCCESS;
}

bool isPanDigital(std::string num)
{ // check if the number include 0-9 digits (10 total digits)
  std::set<char> number;

  for (int i = 0; i < num.size(); i++)
  {
    number.insert(num[i]);
  }

  // if (number.size() != 10)
  // {
  //   return false;
  // }
  for (int i = 0; i < 10; i++)
  {
    if (number.find(i + '0') == number.end())
    {
      return false;
    }
    else
    {
      continue;
    }
  }
  return num.size() == number.size();
}

bool isSubstrDivisible(std::string number)
{
  std::string num(number);
  int i, j;
  std::array<int, 7> divisors = {2, 3, 5, 7, 11, 13, 17};
  for (i = 1, j = 0; i < num.size() - 2 && j < divisors.size(); i++, j++)
  {
    std::string div = std::string(1, num[i]) + std::string(1, num[i + 1]) + std::string(1, num[i + 2]);
    if (std::stoi(div) % divisors[j] != 0)
    {
      return false;
    }
  }

  return true;
}

void generatePandigitals(std::string current, std::vector<bool> &used,
                         std::vector<long long> &results, int position)
{
  // Base case - we've built a 10-digit number
  if (position == 10)
  {
    results.push_back(std::stoll(current));
    return;
  }

  // Position 0: can't use 0 as first digit
  if (position == 0)
  {
    for (int i = 1; i <= 9; i++)
    {
      if (!used[i])
      {
        used[i] = true;
        generatePandigitals(current + std::to_string(i), used, results, position + 1);
        used[i] = false;
      }
    }
    return;
  }

  // For positions 3 and onward, check divisibility constraints
  if (position >= 3)
  {
    int divisor = 0;
    switch (position)
    {
    case 3:
      divisor = 2;
      break;
    case 4:
      divisor = 3;
      break;
    case 5:
      divisor = 5;
      break;
    case 6:
      divisor = 7;
      break;
    case 7:
      divisor = 11;
      break;
    case 8:
      divisor = 13;
      break;
    case 9:
      divisor = 17;
      break;
    }

    if (divisor > 0)
    {
      int val = (current[position - 2] - '0') * 100 +
                (current[position - 1] - '0') * 10;

      // Try only digits that satisfy the divisibility constraint
      for (int i = 0; i <= 9; i++)
      {
        if (!used[i] && (val + i) % divisor == 0)
        {
          used[i] = true;
          generatePandigitals(current + std::to_string(i), used, results, position + 1);
          used[i] = false;
        }
      }
      return;
    }
  }

  // For positions without constraints, try all unused digits
  for (int i = 0; i <= 9; i++)
  {
    if (!used[i])
    {
      used[i] = true;
      generatePandigitals(current + std::to_string(i), used, results, position + 1);
      used[i] = false;
    }
  }
}
