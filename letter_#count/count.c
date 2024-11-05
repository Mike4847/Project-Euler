#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// C function to convert numbers into their specific words
void numToWords(int A, char *result);

// Function to count letters in the number's wording (excluding spaces and hyphens)
int countLetters(char *number);

int main()
{
  // Allocate memory for result string
  char *res = (char *)malloc(sizeof(char) * 200);

  int totalLetters = 0;

  // Loop through numbers from 1 to 1000
  for (int i = 1; i <= 1000; i++)
  {
    // Clear the result string for each iteration
    res[0] = '\0';

    // Convert number to words
    numToWords(i, res);

    // Count letters in the current number's wording
    totalLetters += countLetters(res);
  }

  // Print the total letter count
  printf("Total letter count: %i\n", totalLetters);

  // Free the allocated memory
  free(res);

  return 0;
}

void numToWords(int A, char *result)
{
  char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  int ten, hundred, thousand, unit;

  if (result == NULL)
  {
    printf("Memory allocation failed");
    exit(-1);
  }

  *result = '\0'; // Reset result

  if (A == 1000)
  {
    strcat(result, "one thousand");
    return;
  }

  thousand = (A / 1000) % 10;
  if (thousand > 0)
  {
    strcat(result, units[thousand]);
    strcat(result, " thousand");
  }

  hundred = (A / 100) % 10;
  if (hundred > 0)
  {
    strcat(result, units[hundred]);
    strcat(result, " hundred");
  }

  // Add "and" if there are hundreds and the last two digits aren't zero
  if ((hundred > 0 || thousand > 0) && (A % 100 != 0))
  {
    strcat(result, " and ");
  }

  ten = (A / 10) % 10;
  unit = A % 10;

  if (ten == 1) // For numbers 10 to 19
  {
    strcat(result, teens[unit]);
  }
  else
  {
    if (ten > 1)
    {
      strcat(result, tens[ten]);
      if (unit > 0)
      {
        strcat(result, "-");
      }
    }
    if (unit > 0)
    {
      strcat(result, units[unit]);
    }
  }
}

int countLetters(char *number)
{
  int count = 0;

  // Loop through the string and count letters (excluding spaces and hyphens)
  for (int i = 0; number[i] != '\0'; i++)
  {
    if (number[i] != ' ' && number[i] != '-')
    {
      count++;
    }
  }

  return count;
}
