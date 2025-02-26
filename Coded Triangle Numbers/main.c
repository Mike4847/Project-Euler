#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define WORD_MAX_LEN 100
#define MAX_NO_WORDS 2000

/*
  the nth term of a tringle number is given by:
  n_th = 1/2*n (n + 1)
*/

void seqtrinumbers(int *list);

int main()
{
  const char *words = "words.txt";
  int i; // counter

  FILE *file = fopen(words, "r");

  if (!file)
  {
    perror("Opening file failed.....\nExiting.....\n");
    return EXIT_FAILURE;
  }

  int seq_tri_number[MAX_NO_WORDS]; // CONTAINS 2000 entries

  // calculating the sequence of coded triangular number
  seqtrinumbers(seq_tri_number);

  printf("%d", seq_tri_number[9]);
  char word[WORD_MAX_LEN];

  int codedtriangularnumber = 0;

  while (fscanf(file, "%99[^,],", word) != EOF) // read word by word
  {
    // printf("%s\n", word);
    size_t wordlen = strlen(word);
    if (wordlen > 0 && word[0] == '"')
    {
      // Remove opening quote
      memmove(word, word + 1, wordlen - 1);
      wordlen--;
      // Remove closing quote if present
      if (wordlen > 0 && word[wordlen - 1] == '"')
      {
        word[wordlen - 1] = '\0';
        wordlen--;
      }
    }
    int wordvalue = 0;
    for (i = 0; i < wordlen; i++)
    {
      wordvalue += word[i] - 'A' + 1;
    }

    for (i = 0; i < MAX_NO_WORDS; i++)
    {
      if (seq_tri_number[i] == wordvalue)
      {
        codedtriangularnumber += 1;
      }
    }
  }

  printf("\nThe number of coded triangular number contained in the file is\t\n%d", codedtriangularnumber);

  return EXIT_SUCCESS;
}

void seqtrinumbers(int *list)
{
  list[0] = 0; // First triangular number is 0
  for (int i = 1; i < MAX_NO_WORDS; i++)
  {
    list[i] = (i * (i + 1)) / 2; // Integer division is safer than 0.5 * float
  }
}