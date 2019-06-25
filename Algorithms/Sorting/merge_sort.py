#!/usr/bin/python3

def merge (seq, low, mid, high):
    left = []
    right = []

    for i in range(mid - low + 1):
        left.append(seq[low + i])
    left.append(10)

    for i in range(high - mid):
        right.append(seq[mid + 1 + i])
    right.append(10)

    i, j = 0, 0
    for k in range(low, high + 1):
        if (left[i] <= right[j]):
            seq[k] = left[i]
            i += 1
        else:
            seq[k] = right[j]
            j += 1

    return seq

def merge_sort(seq, low, high):
    if low < high:
        mid = (low + high) // 2
        seq = merge_sort(seq, low, mid)
        seq = merge_sort(seq, mid + 1, high)
        seq = merge(seq, low, mid, high)

    return seq

seq = [3, 5, 2, 4, 1]
print(merge_sort(seq, 0, 4))
