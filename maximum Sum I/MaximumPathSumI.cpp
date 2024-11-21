#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*
 Idea is getting each line from the file
 Data is in triangular matrix.
 The data will be written into vector of vectors
 We are gonna utilise dynamic programming
 break the problem into chunks of "overlaps"

 I need to track index of previous line
 get the max of the adjacent +1 or -1
*/

int main()
{

  std::ifstream in("text.txt");
  std::string line;

  // check if the file is open
  if (!in.is_open())
  {
    std::cerr << "OOOOpss File Could not Open.\n Exiting ...\n";
  }

  std::vector<std::vector<int>> Triangular2D;
  while (std::getline(in, line))
  {

    std::istringstream row(line);

    // debug line read
    std::cout << line << std::endl;

    int number;
    // read into a vector then reading the whole line into the matrix
    std::vector<int> temp;

    while (row >> number)
    {

      temp.push_back(number);
    }

    Triangular2D.push_back(temp);
    temp.clear();
  }
  // check if the matrix is empty
  if (Triangular2D.empty())
  {
    std::cout << " Data read was not successful...\n exiting...\n";
    return 1;
  }

  // Debug: print the entire matrix
  std::cout << "Matrix read:\n";
  for (const auto &row : Triangular2D)
  {
    for (int num : row)
    {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  // LOOP through the arrayfrom the second-row to the top and add the number plus the maximu of the two adjacent elements before
  for (int i = Triangular2D.size() - 2; i >= 0; i--)
  {
    for (size_t j = 0; j < Triangular2D[i].size(); j++)
    {
      Triangular2D[i][j] += std::max(Triangular2D[i + 1][j], Triangular2D[i + 1][j + 1]);
    }
  }

  // Debug: print the entire matrix
  std::cout << "Matrix read:\n";
  for (const auto &row : Triangular2D)
  {
    for (int num : row)
    {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  // In principle after iteration to the last row, from the bottom second-row the top element
  // the top element will be the maximum path from the root to the base
  // Find maximum in the last row
  

  std::cout << "Maximum Path Sum: " << Triangular2D[0][0]<< std::endl;

  return EXIT_SUCCESS;
}