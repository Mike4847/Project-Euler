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
#include <algorithm>
#include <iterator>

// Read the entire file into a string and separatey read the delimetered names into a vector
// create a fucntion that will sort the elements in the vector inplace
// merge function which uses a very naive and clean approach
// when merging "two sorted halves into a single sorted auxillary storage sequence before copying back to the original."
std::vector<std::string> readNames(const std::string &filename);

void mergeSort(std::vector<std::string> &names, int left, int right);

void merge(std::vector<std::string> &names, int left, int middle, int right);

std::map<int, int> asciiSumOfNames(std::vector<std::string> &names);

int main()
{

  // file name(names.txt)
  const std::string FILENAME = "names.txt";
  std::vector<std::string> names = readNames(FILENAME);

  // printing the elements before sorting
  std::cout << "Before sorting:\n\n";
  std::cout << "The length of the vector is\n"
            << names.size() << std::endl;
  std::cout << "Firstname:\t" << names.at(0) << "\nLastElement:\t" << names.at(names.size() - 1);
  // for(const auto name:names)
  // {
  //   std::cout << name << std::endl;
  // }

  //(NOTE): sort the elements in vector(names) the order should be lexiographically
  mergeSort(names, 0, names.size() - 1);

  // std::vector<std::string> vec = {"hello", "world"};

  std::map<int, int> indexAndSumOfNames;
  indexAndSumOfNames= asciiSumOfNames(names);
  // After sorting
  // printing the elements After sorting
  std::cout << "\nAfter sorting:\n\n";
  std::cout << "The length of the vector is\n"
            << names.size() << std::endl;
  std::cout << "Firstname:\t" << names.at(0) << "LastElement:\t\n"
            << names.at(names.size() - 1)<<std::endl;
  std::cout << "\nSumOfAscci is\t" << indexAndSumOfNames[names.size() - 1] << std::endl;
  // for(const auto name:names)
  // {
  //   std::cout << name << std::endl;
  // }

  // std::cout << names[0] << std::endl;
  // std::cout << "The length of the vector is\n" << names.size() <<std::endl;
  // std::cout << "Firstname:\t"<<names.at(0) << "\nLastElement:\t" <<names.at(names.size()-1);

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

    if (file.is_open() && names.capacity() >= 5000)
    {

      // variable(string) where the content of the whole string will be emptied into.
      // read the fileContent into a stringstream classes
      std::string fileContent;
      std::getline(file, fileContent, '\0'); // read until the  end of the file

      std::stringstream ss(fileContent);

      std::string name;
      while (std::getline(ss, name, ','))
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

void mergeSort(std::vector<std::string> &names, int left, int right)
{
  if (left >= right)
  {
    return;
  }
  int middle = (left + right) / 2;
  mergeSort(names, left, middle);
  mergeSort(names, middle + 1, right);
  merge(names, left, middle, right);
}

void merge(std::vector<std::string> &names, int left, int middle, int right)
{ // auxillary storage

  std::vector<std::string> auxilaryVector;
  int j, i, k;
  k = left;
  j = middle + 1;
  while (k <= middle && j <= right)
  {
    if (names[k] < names[j])
    {
      auxilaryVector.push_back(names[k]);
      k++;
    }
    else
    {
      auxilaryVector.push_back(names[j]);
      j++;
    }
  }
  while (k <= middle)
  {
    auxilaryVector.push_back(names[k]);
    k++;
  }

  while (j <= right)
  {
    auxilaryVector.push_back(names[j]);
    j++;
  }

  // The left argument in thbe  below function is used to
  // offset the write distance to ensure correctness of the copy operation on the origininal containner(names)
  std::copy(auxilaryVector.begin(), auxilaryVector.end(), names.begin() + left);
}

std::map<int, int> asciiSumOfNames(std::vector<std::string> &names)
{ /*
   The general idea is to record the index of the name in the vector container
   and the value to be the sum of the individual Ascii values of the chracter in the names(items of vector)

 */
  std::map<int, int> asciiSumOfNames;

  for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it)
  {

    int SumOfAscii = 0;
    std::string name;
    name = *it;

    for (size_t i = 0; i < it->length(); i++)
    {

      SumOfAscii += (name[i] - 'A' + 1);
    }
    // index of the name in the names vector container
    int index = std::distance(names.begin(), it);
    asciiSumOfNames[index] = SumOfAscii;
  }

  return asciiSumOfNames;
}