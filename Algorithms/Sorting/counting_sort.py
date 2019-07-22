#!/usr/bin/python3

def counting_sort(seq):
    cnt = [0] * 256

    for i in range(len(seq)):
        cnt[seq[i]] += 1

    k = 0
    for i in range(256):
        j = cnt[i]
        while j > 0:
            seq[k] = i
            k += 1
            j -= 1

    return seq

seq = [3, 5, 2, 4, 1]
print(counting_sort(seq))
