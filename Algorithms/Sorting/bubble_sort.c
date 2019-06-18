#include <stdio.h>

void
bubble_sort (int* seq, int n)
{
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - 1; ++j)
      if (seq[j] > seq[j + 1])
        {
          int tmp = seq[j];
          seq[j] = seq[j + 1];
          seq[j + 1] = tmp;
        }
}


int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  bubble_sort (seq, n);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
