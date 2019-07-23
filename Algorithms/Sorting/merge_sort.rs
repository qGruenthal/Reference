fn merge(seq: &mut [u8; 5], low: usize, mid: usize, high: usize) {
    let mut left: Vec<u8> = seq[low..mid + 1].to_vec();
    let mut right: Vec<u8> = seq[mid + 1..high + 1].to_vec();

    left.push(10);
    right.push(10);
    
    let mut i: usize = 0;
    let mut j: usize = 0;
    for k in low..high + 1 {
        if left[i] <= right[j] {
            seq[k] = left[i];
            i += 1;
        } else {
            seq[k] = right[j];
            j += 1;
        }
    }
}

fn merge_sort(seq: &mut [u8; 5], low: usize, high: usize) {
    if low < high {
        let mid: usize = (low + high) / 2;
        merge_sort (seq, low, mid);
        merge_sort (seq, mid + 1, high);
        merge (seq, low, mid, high);
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    merge_sort(&mut seq, 0, 4);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
