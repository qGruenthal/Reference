fn insertion_sort(seq: &mut [u8; 5]) {
    for i in 1..seq.len() {
        let mut j: usize = i;
        while j > 0 && seq[j - 1] > seq[j] {
            seq.swap(j, j - 1);
            j -= 1;
        }
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    insertion_sort(&mut seq);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
