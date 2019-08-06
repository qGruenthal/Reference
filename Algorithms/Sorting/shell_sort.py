#!/usr/bin/python3

def shell_sort(seq):
    n = len(seq)
    gap = n // 2
    while gap > 0:
        i = gap
        while i < n:
            cur = seq[i]
            j = i
            while j >= gap and seq[j - gap] > cur:
                seq[j] = seq[j - gap]
                j -= gap
                
            seq[j] = cur
            i += 1

        gap //= 2

    return seq

seq = [3, 5, 2, 4, 1]
print(shell_sort(seq))
