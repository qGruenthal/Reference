fn gnome_sort(seq: &mut [u8; 5]) {
    let mut i: usize = 0;
    while i < seq.len() {
        if i == 0 || seq[i] >= seq[i - 1] {
            i += 1;
        } else {
            seq.swap(i, i - 1);
            i -= 1;
        }
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    gnome_sort(&mut seq);
    
    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}

    
