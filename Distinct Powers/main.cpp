#include <iostream>
#include <set>
#include <cmath>
#include <string>








std::string pow(int a, int b);
int main()
{
  //  TODO:
  //note that log(a^b) = b log a
  std::string product;
  std::set< std::string > uniqueSequence ;

  //THE idea is a^b in which both the [2<=a=b<=100] 
  

  
  for (int a= 2 ; a < 101 ; a++)
  {
    for (int b= 2 ; b < 101 ; b++)
    {
      product = "";
      
    }

  }
  
  // return the size of the set
  std::cout << "The size of unique elements of a^ b is\n"
            << uniqueSequence.size() << std::endl;



}





std::string 
pow(std::string a,std::string b)
{//function that takes in two integers base and powers and returns the equivalence answer but in string type
  std::string product = "0";
  for (int i = a.size()-1  ; i >=0 ; i++ )
  {
      for (int j = b.size()-1  ; j >=0 ; j++ )
  {
      int digitProduct = std::stoi(a[i]) *  std::stoi(b[j]);
      std::string answer = std::to_string(digitProduct);

    
  }
    
  }
}

