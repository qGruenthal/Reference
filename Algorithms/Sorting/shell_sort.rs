fn shell_sort(seq: &mut [u8; 5]) {
    let mut gap: usize = seq.len() / 2;
    while gap > 0 {
        for i in gap..seq.len() {
            let cur: u8 = seq[i];
            let mut j: usize = i;
            while j >= gap && seq[j - gap] > cur {
                seq[j] = seq[j - gap];
                j -= gap;
            }
            seq[j] = cur;
        }

        gap /= 2;
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    shell_sort(&mut seq);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
