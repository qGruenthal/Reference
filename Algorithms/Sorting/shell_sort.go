package main

import "fmt"

func shell_sort(seq []int) {
	for gap := len(seq) / 2; gap > 0; gap /= 2 {
		for i := gap; i < len(seq); i++ {
			cur := seq[i]
			j := i
			for j >= gap && seq[j - gap] > cur {
				seq[j] = seq[j - gap]
				j -= gap
			}
			seq[j] = cur
		}
	}
}

func main() {
	seq := []int{3, 5, 2, 4, 1}

	shell_sort(seq)
	fmt.Println(seq)
}
