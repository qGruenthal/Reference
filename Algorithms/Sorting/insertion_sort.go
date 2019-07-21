package main

import "fmt"

func insertion_sort(seq []int) {
  for i := 0; i < len(seq); i++ {
    cur := seq[i]
    j := i - 1
    for j >= 0 && seq[j] > cur {
      seq[j + 1] = seq[j];
      j--
    }
    seq[j + 1] = cur
  }
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  insertion_sort(seq)
  fmt.Println(seq)
}
