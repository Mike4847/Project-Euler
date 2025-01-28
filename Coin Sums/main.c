#include <stdio.h>
#include <stdlib.h>



/*
  NOTE:
  you are given an array of coins(different denomination)
  Problme statement is to find different combination of coming up with  200(coin , pence)
 
*/
int countRec(int coins[], int n , int sum);
int
count(int Coins[] ,int n, int sum);
int main()
{
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
  int size =  sizeof(coins)/sizeof(coins[0]);
  printf("There are %i coins to make 200p ", count(coins ,size, 200 ));

}


int 
countRec(int coins[], int n, int sum)
{

  // base case: if n=0 then it means that we have found a valid match
  if (sum == 0 ) return 1;


  // invalid cases : when sum < 0 and n= 0 
  if (sum < 0 || n == 0 ) return 0;


  // 1. include the current coin 
  // ii exclude the currect coint 
  // NOTE:
  // we could really start with any coin index
  // but note that in this case an using the end of the array as index.
  return countRec(coins , n , sum - coins[n -1]) +  countRec(coins , n - 1 , sum) ;

}

int
count(int coins[], int n,int sum)
{

  return countRec(coins, n , sum );
}
