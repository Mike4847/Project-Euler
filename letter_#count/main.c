#include "count.c"

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