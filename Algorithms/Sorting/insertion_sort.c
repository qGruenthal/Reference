#include <stdio.h>

void
insertion_sort (int* seq, int n)
{
  for (int i = 0; i < n; ++i)
    {
      int cur = seq[i];
      int j = i - 1;
      while (j >= 0 && seq[j] > cur)
	seq[j + 1] = seq[j--];
      seq[j + 1] = cur;
    }
}
  

int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  insertion_sort (seq, n);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
