/*
 given a list of names(5000) sort the names lexiographically.
 After sorting the names get the individual elements(position) sum
 and  then multiply the position by the  previous aquired sum
*/

// data is recorded from a text file  named (names.txt)
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

// Read the entire file into a string and separatey read the delimetered names into a vector
std::vector<std::string> readNames(const std::string &filename)
{

  std::vector<std::string> names(5000);
  try
    {
      // checking if the machine has enough memory for holding 5000 names
      
      names.reserve(5000);
      std::fstream file(filename);

      if (file.is_open())
      {

        // variable(string) where the content of the whole string will be emptied into.
        // read the fileContent into a stringstream classes
        std::string fileContent;
        std::getline(file, fileContent, '\0'); // read until the  end of the file
        
        std::stringstream ss(fileContent);

        std::string name;
        while(std::getline(ss,name , ','))
        {
          names.push_back(name);
        }
      

        
      }
      else
      {
        std::cerr << "Unable to open the file";
        std::exit(1);
      }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory allocation failed.\n"
              << e.what() << '\n';
  }

  return names;
  
}

int main()
{



  // file name(names.txt)
  const std::string FILENAME = "names.txt";

  std::vector<std::string> names =readNames(FILENAME);

  // Print the names of the  vector.





  std::cout << "Done";
  return EXIT_SUCCESS;
}
