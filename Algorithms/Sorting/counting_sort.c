#include <stdio.h>

void
counting_sort (int* seq, int n)
{
  int cnt[256] = {0};

  for (int i = 0; i < n; ++i)
    cnt[seq[i]] += 1;

  int k = 0;
  for (int i = 0; i < 256; ++i)
    for (int j = cnt[i]; j > 0; --j)
      seq[k++] = i;
}


int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  counting_sort (seq, n);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
