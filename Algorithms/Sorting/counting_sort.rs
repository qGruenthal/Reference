fn counting_sort(seq: &mut [u8; 5]) {
    let mut cnt: [u8; 256] = [0; 256];
    
    for i in 0..seq.len() {
        cnt[seq[i] as usize] += 1;
    }

    let mut k = 0;
    for i in 0..cnt.len() {
        for _j in 0..cnt[i] {
            seq[k] = i as u8;
            k += 1;
        }
    }
}

fn main() {
    let mut seq: [u8; 5] = [3, 5, 2, 4, 1];

    counting_sort(&mut seq);

    for i in &seq {
        print!("{} ", i);
    }
    print!("\n");
}
