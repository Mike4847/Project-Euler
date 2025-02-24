#include <iostream>
#include <unordered_map>
#include <cmath>

int main()
{
  const int MAXIMUM = 1000;
  std::unordered_map<int, int> perimeter_solutions;

  // Initialize the map
  for (int p = 1; p <= MAXIMUM; p++)
  {
    perimeter_solutions[p] = 0;
  }

  // Find right triangles
  for (int a = 1; a <= MAXIMUM / 3; a++)
  {
    for (int b = a; b <= MAXIMUM / 2; b++)
    {
      double c = std::sqrt(a * a + b * b);
      if (c == std::floor(c))
      { // Check if c is integer
        int p = a + b + static_cast<int>(c);
        if (p <= MAXIMUM)
        {
          perimeter_solutions[p]++;
        }
      }
    }
  }

  // Find maximum solutions
  int max_solutions = 0;
  int result_p = 0;

  for (int p = 1; p <= MAXIMUM; p++)
  {
    if (perimeter_solutions[p] > max_solutions)
    {
      max_solutions = perimeter_solutions[p];
      result_p = p;
    }
  }

  std::cout << "Perimeter with most solutions: " << result_p << std::endl;
  std::cout << "Number of solutions: " << max_solutions << std::endl;

  return EXIT_SUCCESS;
}
