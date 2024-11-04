#include "count.c"

int main()
{
  // call the num to words
  // declare a variable that can hld string
  char *res[200 + 1] = NULL;
  numToWords(145, &res);

  int cnt = countWords(res);

  // print cnt number
  printf("%i", cnt);

  // forloop

  // for (int i=0; i<200 ; i++)
  // {

  // }

  return (0);
}