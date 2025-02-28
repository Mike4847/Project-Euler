#include <iostream>
#include <string>
#include <vector>
#include <set>

// todo:
bool isPanDigital(std::string number);
int main()
{

  const long long LIMIT = 10000000000;
  long long number;

  for (number = 1000000000; number < LIMIT; number++)
  {
  }

  return EXIT_SUCCESS;
}

bool isPanDigital(std::string num)
{// check if the number include 0-9 digits (10 total digits)
  std::set<std::string> number;

  for(int i =0 ; i < num.size() ; i++)
  {
    number.insert(num[i]);
  }

  if (number.size() != 10)
  {
    return false;
  }

  return True;

}
