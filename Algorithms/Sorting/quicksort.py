#!/usr/bin/python3

def partition(seq, low, high):
    pivot = seq[high]
    i = low

    for j in range(low, high):
        if seq[j] <= pivot:
            seq[i], seq[j] = seq[j], seq[i]
            i += 1

    seq[i], seq[high] = seq[high], seq[i]
    return seq, i

def quicksort(seq, low, high):
    if low < high:
        seq, pivot = partition(seq, low, high)

        seq = quicksort(seq, low, pivot - 1)
        seq = quicksort(seq, pivot + 1, high)

    return seq

seq = [3, 5, 2, 4, 1]
print(quicksort(seq, 0, 4))
