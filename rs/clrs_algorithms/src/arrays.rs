// Count-Inversions algorithm from problem 2-4 p.42 of CLRS 3e
fn find_inversions<T>(a: &mut [T], p: usize, q: usize, r: usize, infinity: T) -> usize
where
    T: Copy,
    T: Ord,
{
    let n1 = q - p + 1;
    let n2 = r - q;

    let mut larr = vec![a[0]; n1 + 1];
    let mut rarr = vec![a[0]; n2 + 1];

    for i in 0..n1 {
        larr[i] = a[p + i];
    }
    for j in 0..n2 {
        rarr[j] = a[q + j + 1];
    }

    larr[n1] = infinity;
    rarr[n2] = infinity;

    let mut i = 0;
    let mut j = 0;
    let mut inversions = 0;
    let mut counted = false;

    for k in p..=r {
        if counted == false && rarr[j] < larr[i] {
            inversions += n1 - i + 1;
            counted = true;
        }

        if larr[i] <= rarr[j] {
            a[k] = larr[i];
            i += 1;
        } else {
            j += 1;
            counted = false;
        }
    }

    inversions
}

pub fn count_inversions<T>(a: &mut [T], p: usize, r: usize, infinity: T) -> usize
where
    T: Copy,
    T: Ord,
{
    let mut inversions = 0;

    if p < r {
        let q = (p + r) / 2;
        inversions += count_inversions(a, p, q, infinity);
        inversions += count_inversions(a, q + 1, r, infinity);
        inversions += find_inversions(a, p, q, r, infinity);
    }

    inversions
}
