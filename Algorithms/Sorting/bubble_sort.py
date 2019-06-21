#!/usr/bin/python3

def bubble_sort(seq):
    n = len(seq) - 1
    for i in range(n):
        for j in range(n):
            if seq[j] > seq[j + 1]:
                seq[j], seq[j + 1] = seq[j + 1], seq[j]
                
    return seq

seq = [3, 5, 2, 4, 1]
print(bubble_sort(seq))
