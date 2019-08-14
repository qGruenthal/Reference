fn partition(seq: &mut [u8; 5], low: usize, high: usize) -> usize {
    let pivot = seq[high];
    let mut i: usize = low;

    for j in low..high {
        if seq[j] <= pivot {
            seq.swap(i, j);
            i += 1;
        }
    }

    seq.swap(i, high);
    return i;
}

fn quicksort(seq: &mut [u8; 5], low: usize, high: usize) {
    if low < high {
        let pivot: usize = partition(seq, low, high);

        if pivot > 1 { quicksort(seq, low, pivot - 1) };
        quicksort(seq, pivot + 1, high);
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    quicksort(&mut seq, 0, 4);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
