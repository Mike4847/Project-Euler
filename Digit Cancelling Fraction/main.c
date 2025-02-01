#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LIMIT 100

/*
 *
 *NOTE: Problem statement:
 finding numerical values that have cancelling digits in which in return.
 in its simplest form is true.

 * */


bool isCancellingFraction(int num, int denom)
{// we are only considering (numerator and denominator) = 2  digits.
  //
  if (num > denom ):
    return false;

  char numerator[3], denominator[3];
  sprintf(numerator, "%i", num);
  sprintf(denominator, "%i", denom);
  double average = 0 ;
  average = num / denom;

  int i , j;

  for (i=0; i < 3 ; i++)
  {
    for (j = 0 ; j < 3 ; j++)
       {
      if (numerator[i] == denominator[j])
       {

      }
    }
  }


void remove_char(char *str, char ch)
{
  int i, j;
  int len = strlen(str);
  for (i =0 ; i < len - 1 ; i++)
  {
      if (str[i] == ch)
      {
        for (j = i ; j < len -1 ; j++){
          str[j] = str[j + 1];
          }
        
      }

   }
}

int main()
{

  return EXIT_SUCCESS;
}
