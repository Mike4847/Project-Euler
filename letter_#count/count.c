#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// C function to convert numbers into their specific words i.e
// 1 -> one
// 300 -> three hundreds
void numToWords(int A, char *result);

// func to count the number of words in a Numbers wording.
int countWords(char *number);

int main()
{
  // call the num to words
  // declare a variable that can hld string
  char *res = (char *)malloc(sizeof(char) * 200);
  numToWords(145, res);

  int cnt;
  cnt = countWords(res);

  // print cnt number
  printf("%i", cnt);

  // forloop

  // for (int i=0; i<200 ; i++)
  // {

  // }
  // free the memory
  free(res);

  return (0);
}

void numToWords(int A, char *result)
{ // converting a number into its word equivalent.
  char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *teens[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char *tens[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  char *scale[] = {"", "thousand", "million", "billion"};
  int ten, hundred, thousand, unit;

  // check if the memory allocation was sucessfull
  // after which the program will exit
  if (result == NULL)
  {
    printf("Memory allocation failed");
    exit(-1);
  }

  if (A == 0)
  { // when the value is 0
    strcpy(result, "zero");
  }
  else
  { // we need a way of handling teens and logically start from the largest 'number group' to the minute one.

    thousand = (A / 1000) % 10;
    if (thousand > 0)
    {
      strcpy(result, units[thousand]);
      strcpy(result, "thousand");
    }

    hundred = (A / 100) % 10;
    if (hundred > 0)
    {
      strcpy(result, units[hundred]);
      strcpy(result, "hundred");
    }

    strcpy(result, "and");

    ten = (A / 10) % 10;
    // TODO (micky)
    unit = A % 10;
    if (ten > 0)
    {
      strcpy(result, tens[ten]);
      strcpy(result, units[unit]);
    }
    else if (ten == 1 && unit != 0)
    {
      strcpy(result, teens[unit]);
    }
  }
}

int countWords(char *number)
{
  int count = 0;
  size_t size = strlen(number);
  // loop through the string and count characters
  for (int i = 0; i < size; i++)
  {
    if (number[i] != '-' && number[i] != ' ')
    {
      count++;
    }
  }

  return count;
}