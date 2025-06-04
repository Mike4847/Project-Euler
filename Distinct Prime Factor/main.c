#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//TODO:
int *prime_factorization(int number);
void sieve_of_eratosthenes(int number , int *count, int **primes);

void sieve_of_eratosthenes(int number , int *count, int **primes) {
  /*

   * The idea is calculating prime numbers up to a number
   */

  bool *is_prime = (bool *)malloc((number + 1) * sizeof(bool));
  if (!is_prime) {
    *count = 0;
    *primes = NULL;
    return;
  }

  int i;
  for (i = 0; i <= number; i++) {  // Include number itself
    is_prime[i] = true;
  }
  // 0 and 1 aren't primes 
  is_prime[0] = is_prime[1] = false;

  for (int p = 2; p * p <= number; p++) {  // Use <= for boundary case
    if (is_prime[p]) {
      // remove all multiples of p
      for (i = p * p; i <= number; i += p) {  // Include number itself
        is_prime[i] = false;
      }
    }
  }

  // Count primes
  *count = 0;
  for (i = 0; i <= number; i++) {
    if (is_prime[i]) (*count)++;
  }

  // Create an array of primes
  *primes = (int *)malloc((*count) * sizeof(int));
  if (!*primes) {
    *count = 0;
    free(is_prime);
    return;
  }

  int index = 0;
  for (i = 2; i <= number; i++) {
    if (is_prime[i]) {
      (*primes)[index++] = i;
    }
  }

  free(is_prime);
}



int main(){

  // finding all primes below 1000
  int count;
  int *primeArr = NULL;
  
  sieve_of_eratosthenes(1000, &count, &primeArr);

  printf("Count of primes below 1000: %d\n", count);  // No & here
  
  if (primeArr) {
    for (int i = 0; i < count; i++) {
      printf("%d\t", primeArr[i]);
    }
    free(primeArr);  // Free the allocated memory
  }

  printf("\n");

  return 0;

}





