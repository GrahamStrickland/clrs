// Insertion-Sort algorithm from p. 18 of CLRS 3e
pub fn insertion_sort<T>(a: &mut [T])
where
    T: Copy,
    T: Ord,
{
    for j in 1..a.len() {
        let key = a[j];

        // Insert A[j] into the sorted sequence A[1..j-1]
        let mut i = j - 1;
        let mut k = i as i32;
        while a[i] > key {
            (a[i], a[i + 1]) = (a[i + 1], a[i]);
            k -= 1;
            i = i.checked_sub(1).unwrap_or(0);
        }
        if k == -1 {
            a[0] = key;
        } else {
            a[i + 1] = key;
        }
    }
}
