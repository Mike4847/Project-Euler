#include <vector>
#include <string>
#include <bitset>
#include <cmath>


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

std::bitset <MAX_SIZE> SieveOfErastosthene(){
  /*NOTE(mickey): The calculated Primes below is dependant on the value of the MAX_SIZE

   */

  std::bitset<MAX_SIZE> PrimeAnswer;
  PrimeAnswer.set();

  // setting the resetting the 0 and 1 bits to false
  PrimeAnswer.set(0);
  PrimeAnswer.set(1);

  for (int i = 2; i < sqrt(MAX_SIZE); i++){
    if(PrimeAnswer[i]){

      for (int p = i * i ; i < MAX_SIZE; p+=i ){

	PrimeAnswer.reset(p);

      }

    }

    }
  

}

