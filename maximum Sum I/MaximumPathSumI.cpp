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

    int number;
    // read into a vector then reading the whole line into the matrix
    std::vector<int> temp;
    temp.clear();
    while (row >> number)
    {

      temp.push_back(number);
    }
    Triangular2D.push_back(temp);
  }

  return EXIT_SUCCESS;
}