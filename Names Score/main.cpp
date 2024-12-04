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



std::map<int, int> NameScore(std::ifstream in)
{
  in.open("names.txt");
  std::map<int, int> resultNameScore;

}

int main(){


  std::cout << "Done" ;
  return EXIT_SUCCESS;
}
