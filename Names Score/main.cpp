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
// create a fucntion that will sort the elements in the vector inplace
// merge function which uses a very naive and clean approach
//when merging "two sorted halves into a single sorted auxillary storage sequence before copying back to the original."
std::vector<std::string> readNames(const std::string &filename);

void mergeSort(std::vector<std::string> &names, int left, int  right);


int main()
{



  // file name(names.txt)
  const std::string FILENAME = "names.txt";

  std::vector<std::string> names = readNames(FILENAME);

  //(NOTE): sort the elements in vector(names) the order should be lexiographically



  // std::cout << names[0] << std::endl;
  std::cout << "The length of the vector is\n" << names.size() <<std::endl;
  // Print the names of the  vector.
  // for (auto const name: names){
  //   std::cout << name << std::endl;
  // }

  // printitn gthe first and last element 

  std::cout << "Firstname:\t"<<names.at(0) << "\nLastElement:\t" <<names.at(names.size()-1);

  // std::cout << "Done";
  return EXIT_SUCCESS;
}

// Read the entire file into a string and separatey read the delimetered names into a vector
std::vector<std::string> readNames(const std::string &filename)
{

  std::vector<std::string> names;
  try
    {
      // checking if the machine has enough memory for holding 5000 names
      
      names.reserve(5000);
      std::fstream file(filename);

      if (file.is_open() && names.capacity() >=5000)
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
        std::cerr << "Unable to open the file\n.Closing ...\n";
        std::exit(1);
      }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory allocation failed.\n"
              << e.what() << '\n';
  }

  std::cout << "Read Operation complete.\n";

  return names;
  
}


// void lexiSort(std::vector<std::string> &names){
//   size_t vecSize = names.size();

// }
// sorting using mergesort

void mergeSort(std::vector<std::string> &names,int left, int right){

}