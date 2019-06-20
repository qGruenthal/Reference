#include <stdio.h>

void
gnome_sort (int* seq, int n)
{
  int i = 0;
  while (i < n)
    {
      if (i == 0 || seq[i] >= seq[i - 1])
        i++;
      else
        {
          int tmp = seq[i];
          seq[i] = seq[i - 1];
          seq[i - 1] = tmp;
          i--;
        }
    }
}


int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  gnome_sort (seq, n);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
