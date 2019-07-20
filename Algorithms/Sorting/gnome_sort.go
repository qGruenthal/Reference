package main

import "fmt"

func gnome_sort(seq []int) {
  i := 0
  for i < len(seq) {
    if i == 0 || seq[i] >= seq[i -1] {
      i++
    } else {
      seq[i], seq[i - 1] = seq[i - 1], seq[i]
      i--
    }
  }
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  gnome_sort(seq)
  fmt.Println(seq)
}
