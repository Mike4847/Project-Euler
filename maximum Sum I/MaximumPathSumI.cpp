#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*
 Idea is getting each line from the file
 Data is in triangular matrix.
 will be a resultvector for storing the maximum path(were using greedy algorithm)
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

  static int index = 0;
  // Sum for the maximumpath
  std::vector<int> Maxpath;
  int Maxnum;

  // previous index

  while (std::getline(in, line))
  {

    std::istringstream row(line);
    std::vector<int> Row;

    int number;
    while (row >> number)
    {
      Row.push_back(number);
    }
    //
    for (int i = 0; i < Row.size(); i++)
    {
      if (Row[index] > Row[index + 1])
      {
        Maxnum = Row[index];
      }
      else
      {
        Maxnum = Row[index + 1];
      }
    }

    index++;
    Maxpath.push_back(Maxnum);
  }

  std::cout << "The maximum sum of the path is:\n";
  int sum = 0;
  for (int n : Maxpath)
  {
    sum += n;
  }
  std::cout << sum << std::endl;

  return EXIT_SUCCESS;
}