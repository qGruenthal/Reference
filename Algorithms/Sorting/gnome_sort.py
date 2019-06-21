#!/usr/bin/python3

def gnome_sort(seq):
    i = 0
    while i < len(seq):
        if i == 0 or seq[i] >= seq[i - 1]:
            i += 1
        else:
            seq[i], seq[i - 1] = seq[i - 1], seq[i]
            i -= 1

    return seq

seq = [3, 5, 2, 4, 1]
print(gnome_sort(seq))
