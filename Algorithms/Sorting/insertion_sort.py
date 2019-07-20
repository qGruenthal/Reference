#!/usr/bin/python3

def insertion_sort(seq):
    for i in range(len(seq)):
        cur = seq[i]
        j = i - 1
        while j >= 0 and seq[j] > cur:
            seq[j + 1] = seq[j]
            j -= 1

        seq[j + 1] = cur

    return seq

seq = [3, 5, 2, 4, 1]
print(insertion_sort(seq))
