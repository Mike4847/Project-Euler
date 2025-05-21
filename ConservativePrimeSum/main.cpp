#include <vector>
#include <bitset>
#include <iostream>
#include <cstddef>
#include <numeric>
#include <utility>


using std::size_t;

const int MAX_SIZE = 1000000;
/*
  NOTE(mickey):problem statement, 
  Finding the largest consecutive Sum of Prime below 1 million that itself is a primea

 */
std::bitset <MAX_SIZE> SieveOfErastosthene();
bool isPrime(const int Prime);

size_t ConsecutivePrimeSum(const std::vector<int>& primes) {
    size_t maxLength = 0;           // Track the maximum length of consecutive primes
    size_t maxPrimeSum = 0;         // Track the corresponding prime sum
    
    // For each starting position
    for (size_t start = 0; start < primes.size(); start++) {
        int sum = 0;
        // Try consecutive primes starting from this position
        for (size_t length = 0; start + length < primes.size(); length++) {
            sum += primes[start + length];
            
            // Break if sum exceeds our limit
            if (sum >= MAX_SIZE) break;
            
            // If sum is prime and sequence is longer than our current max
            if (isPrime(sum) && (length + 1) > maxLength) {
                maxLength = length + 1;
                maxPrimeSum = sum;
            }
        }
    }
    return maxPrimeSum;
}
//TODO(mickey):
//creating a utility function for checking if a number is prime or not

bool isPrime(const int Prime) {
    if (Prime < 2) return false;
    if (Prime == 2) return true;
    if (Prime % 2 == 0) return false;  // Check even numbers first
    for (int i = 3; i * i <= Prime; i += 2) {  // Only check odd numbers
        if (Prime % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){

  
  std::vector<int> Prime;


  std::bitset<MAX_SIZE> PrimeBits = SieveOfErastosthene();

  for(int i=0; i < MAX_SIZE ; i++ ){

    if (PrimeBits[i]){
      Prime.push_back(i);

    }
  }


  size_t ConsecutiveSumPrime =  ConsecutivePrimeSum(Prime);

  std::cout << "The largest Consecutive Sum of Prime of numbers below 1,000,000 is " << ConsecutiveSumPrime <<std::endl;

}

std::bitset <MAX_SIZE> SieveOfErastosthene(){
  /*NOTE(mickey): The calculated Primes below is dependant on the value of the MAX_SIZE

   */

  std::bitset<MAX_SIZE> PrimeAnswer;
  PrimeAnswer.set();

  // setting the resetting the 0 and 1 bits to false
  PrimeAnswer.reset(0);
  PrimeAnswer.reset(1);

  for (int i = 2; i * i < MAX_SIZE; i++){
    if(PrimeAnswer[i]){

      for (int p = i * i ; p < MAX_SIZE; p+=i ){

	PrimeAnswer.reset(p);

      }

    }

   }

  return PrimeAnswer;
  

}

