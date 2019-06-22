fn bubble_sort(seq: &mut [u8; 5]) {
    for i in 0..seq.len() - 1 {
        for j in 0..seq.len() - 1 {
            if seq[j] > seq[j + 1] {
                seq.swap(j, j + 1);
            }
        }
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    bubble_sort(&mut seq);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
