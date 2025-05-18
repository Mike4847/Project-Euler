#include <vector>
#include <string>
#include <bitset>


const int MAX_SIZE = 1000000;
/*
  NOTE(mickey):problem statement, 
  Finding the largest consecutive Sum of Prime below 1 million that itself is a primea

 */
std::bitset <MAX_SIZE> SieveOfErastosthene();


int main(){

  
  std::vector<int> Prime;


  std::bitset<MAX_SIZE> PrimeBits = SieveOfErastosthene();

  for(int i=0; i <= MAX_SIZE ; i++ ){

    if (PrimeBits[i]){
      Prime.push_back(i);

    }
  }

  
  

}
