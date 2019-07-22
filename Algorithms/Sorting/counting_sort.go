package main

import "fmt"

func counting_sort(seq []int) {
  cnt := [256]int{0}

  for i := 0; i < len(seq); i++ {
    cnt[seq[i]] += 1
  }

  k := 0
  for i := 0; i < 256; i++ {
    for j := cnt[i]; j > 0; j-- {
      seq[k] = i
      k++
    }
  }
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  counting_sort(seq)
  fmt.Println(seq)
}
