#include <stdio.h>

void
shell_sort (int* seq, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
    {
      for (int i = gap; i < n; ++i)
        {
          int cur = seq[i];
          int j;
          for (j = i; j >= gap && seq[j - gap] > cur; j -= gap)
            seq[j] = seq[j - gap];
          seq[j] = cur;
        }
    }
}

int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  shell_sort (seq, n);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
