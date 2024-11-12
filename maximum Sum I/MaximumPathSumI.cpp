#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

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

  // check if the file is open
  if (!in.is_open())
  {
    std::cerr << "OOOOpss File Could not Open.\n Exiting ...\n";
  }
  // read the entire file into a string object.

  std::string FileContent((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

  // manipulate the content usng the istring object
  std::istringstream iss(FileContent);

  std::string row;

  while(std::getline(iss,row)){

    static int index = 0;

    

  }

  return EXIT_SUCCESS;
}