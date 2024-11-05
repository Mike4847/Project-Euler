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
  numToWords(10, res);

  int cntFinal = 0;
  int cnt;

  for (size_t i = 0; i < 1000; i++)
  {
    cnt = countWords(res);
    cntFinal += cnt;
  }

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
{
  char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *teens[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  char *scale[] = {"", "thousand", "million", "billion"};
  int ten, hundred, thousand, million, billion, unit;

  if (result == NULL)
  {
    printf("Memory allocation failed");
    exit(-1);
  }

  if (A < 0)
  {
    strcpy(result, "Negative ");
    A = -A;
  }
  else
  {
    *result = '\0';
  }

  if (A == 0)
  {
    strcat(result, "zero");
    return;
  }

  billion = (A / 1000000000) % 1000;
  if (billion > 0)
  {
    numToWords(billion, result);
    strcat(result, " billion");
  }

  million = (A / 1000000) % 1000;
  if (million > 0)
  {
    numToWords(million, result);
    strcat(result, " million");
  }

  thousand = (A / 1000) % 1000;
  if (thousand > 0)
  {
    numToWords(thousand, result);
    strcat(result, " thousand");
  }

  hundred = (A / 100) % 10;
  if (hundred > 0)
  {
    strcat(result, units[hundred]);
    strcat(result, " hundred");
  }

  if (hundred > 0 || thousand > 0 || million > 0 || billion > 0)
  {
    strcat(result, " and ");
  }

  ten = (A / 10) % 10;
  unit = A % 10;

  if (ten == 1 && unit != 0)
  {
    strcat(result, teens[unit]);
  }
  else
  {
    if (ten > 0)
    {
      strcat(result, tens[ten]);
    }
    if (unit > 0)
    {
      if (ten > 0)
      {
        strcat(result, "-");
      }
      strcat(result, units[unit]);
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