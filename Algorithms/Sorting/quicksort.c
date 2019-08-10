#include <stdio.h>

void
swap (int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int
partition (int* seq, int low, int high)
{
  int pivot = seq[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; ++j)
    if (seq[j] <= pivot)
      {
	++i;
	swap (&seq[i], &seq[j]);
      }
  
  swap (&seq[i + 1], &seq[high]);
  return i + 1;
}

void
quicksort (int* seq, int low, int high)
{
  if (low < high)
    {
      int pivot = partition (seq, low, high);

      quicksort (seq, low, pivot - 1);
      quicksort (seq, pivot + 1, high);
    }
}

int
main ()
{
  int seq[] = {3, 5, 2, 4, 1};
  int n = 5;

  quicksort (seq, 0, n - 1);

  for (int i = 0; i < n; ++i)
    printf ("%d ", seq[i]);
  printf ("\n");
}
