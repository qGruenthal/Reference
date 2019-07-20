package main

import "fmt"

func bubble_sort(seq []int) {
  for i := 0; i < len(seq) - 1; i++ {
    for j := 0; j < len(seq) - 1; j++ {
      if seq[j] > seq[j + 1] {
        seq[j], seq[j + 1] = seq[j + 1], seq[j]
      }
    }
  }
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  bubble_sort(seq)
  fmt.Println(seq)
}
