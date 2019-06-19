#include <stdio.h>
#include <stdlib.h>

void
merge (int* seq, int low, int mid, int high)
{
  int* left = malloc (sizeof (int) * (mid - low + 2));
  int* right = malloc (sizeof (int) * (high - mid + 1));

  int i, j;

  for (i = 0; i < (mid - low + 1); ++i)
    left[i] = seq[low + i];
  left[i] = 10;

  for (i = 0; i < (high - mid); ++i)
    right[i] = seq[mid + 1 + i];
  right[i] = 10;

  i = 0;
  j = 0;
  for (int k = low; k <= high; ++k)
    {
      if (left[i] <= right[j])
        seq[k] = left[i++];
      else
        seq[k] = right[j++];
    }

  free (left);
  free (right);
}

void
merge_sort (int* seq, int low, int high)
{
  if (low < high)
    {
      int mid = (low + high) / 2;
      merge_sort (seq, low, mid);
      merge_sort (seq, mid + 1, high);
      merge (seq, low, mid, high);
    }
}


int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  merge_sort (seq, 0, n - 1);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
