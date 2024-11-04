#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// standard calculation of sum of elements in a matrix

long long sumMatrix(vector<vector<int>> mat)
{
  long long sum(0);
  for (const auto &row : mat)
  {
    for (const auto &num : row)
    {
      sum += num;
    }
  }

  return sum;
}

// calculate sum of 100 50digit numbers

int main()
{

  return 0;
}