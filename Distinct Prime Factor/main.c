#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



//TODO:
//calculate prime factorization of a number
// the idea is using Sieve or Eratosthenes



//TODO:
int *prime_factorization(int number);

//TODO:
//calculate list of primes upto a number

int *sieve_of_eratosthenes(int number , int *count){

  /*
   * The idea is calculating prime upto a number
   * for the sieve of erastosthene we need a boolean array upto number.
   *  
   * */
  bool *is_prime = (bool *)malloc((number + 1) * sizeof(bool));

  int i ;

  for (i = 0 ; i <= number ; i++)
  {
    is_prime[i] = true;
  }

  // 0 and 1 arent primes 
  is_prime[0] = is_prime[1] = false;

  for(int p =2 ; p * p <= number ; p++)
  {
    if(is_prime[p])
    {
      // remove all multiples of p
      for ( i = p * p  ; i <=number ; i += p )
      {
        is_prime[i] = false;

      }

    }

  }

  *count = 0 ;
  for(i =0 ; i <= number ; i++)
  {
    if(is_prime[i]) (*count)++;

  }

  // create an array of primes
  int *primes = (int *)malloc((*count) * sizeof(int));
  int index = 0 ;
  for (i = 2 ; i <= number ; i++)
  {
    if(is_prime[i])
    {
      primes[index++] = i ;
    }
  }

  free(is_prime);
  return primes;


}



int main(){


 

  printf("\n");

  

  return(0);
}


int *prime_factorization(int number)
{
  if (number <= 2) return NULL;
  int count = 0;
  int *prime =sieve_of_eratosthenes( number, &count);
 
  
}




