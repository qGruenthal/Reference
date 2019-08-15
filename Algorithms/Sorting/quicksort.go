package main

import "fmt"

func partition(seq []int, low int, high int) int {
	pivot := seq[high]
	i := low

	for j := low; j < high; j++ {
		if seq[j] <= pivot {
			seq[i], seq[j] = seq[j], seq[i]
			i++
		}
	}

	seq[i], seq[high] = seq[high], seq[i]
	return i
}

func quicksort(seq []int, low int, high int) {
	if low < high {
		pivot := partition(seq, low, high)

		quicksort(seq, low, pivot - 1)
		quicksort(seq, pivot + 1, high)
	}
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  quicksort(seq, 0, 4)
  fmt.Println(seq)
}
