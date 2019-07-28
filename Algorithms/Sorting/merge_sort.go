package main

import "fmt"

func merge(seq []int, low int, mid int, high int) {
	l_len := mid - low
	r_len := high - mid

	i := 0
	
	left := make([]int, l_len + 2)
	right := make([]int, r_len + 2)

	for i = 0; i < l_len + 1; i++ {
		left[i] = seq[low + i]
	}
	left[i] = 10

	for i = 0; i < r_len; i++ {
		right[i] = seq[mid + 1 + i]
	}
	right[i] = 10

	i = 0
	j := 0
	for k := low; k <= high; k++ {
		if left[i] <= right[j] {
			seq[k] = left[i]
			i++
		} else {
			seq[k] = right[j]
			j++
		}
	}
}

func merge_sort(seq []int, low int, high int) {
	if low < high {
		mid := (low + high) / 2;
		merge_sort(seq, low, mid);
		merge_sort(seq, mid + 1, high);
		merge(seq, low, mid, high);
	}
}

func main() {
  seq := []int{3, 5, 2, 4, 1}

  merge_sort(seq, 0, 4)
  fmt.Println(seq)
}
