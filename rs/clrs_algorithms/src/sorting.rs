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

// Insertion-Sort algorithm in non-increasing order from ex2.1-2 on p.22 of CLRS
pub fn insertion_sort_reverse<T>(a: &mut [T])
where
    T: Copy,
    T: Ord,
{
    for j in 1..a.len() {
        let key = a[j];

        // Insert A[j] into the sorted sequence A[1..j-1]
        let mut i = j - 1;
        while a[i] < key {
            (a[i], a[i + 1]) = (a[i + 1], a[i]);
            i = i.checked_sub(1).unwrap_or(0);
        }
    }
}

// Selection-Sort algorithm from ex2.2-2 p.29 of CLRS 3e
pub fn selection_sort<T>(a: &mut [T])
where
    T: Copy,
    T: Ord,
{
    for i in 0..a.len() - 1 {
        let mut smallest = i;

        for j in i..a.len() {
            if a[j] < a[smallest] {
                smallest = j;
            }
        }

        (a[i], a[smallest]) = (a[smallest], a[i])
    }
}

// Merge-Sort algorithm from p.31-34 of CLRS 3e
fn merge<T>(a: &mut [T], p: usize, q: usize, r: usize, infinity: T)
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

    for k in p..=r {
        if larr[i] <= rarr[j] {
            a[k] = larr[i];
            i += 1;
        } else {
            a[k] = rarr[j];
            j += 1;
        }
    }
}

pub fn merge_sort<T>(a: &mut [T], p: usize, r: usize, infinity: T)
where
    T: Copy,
    T: Ord,
{
    if p < r {
        let q = (p + r) / 2;
        merge_sort(a, p, q, infinity);
        merge_sort(a, q + 1, r, infinity);
        merge(a, p, q, r, infinity);
    }
}

// Merge-Sort algorithm without sentinel values from ex. 2.3-2 p.37 of CLRS 3e
fn merge_no_sentinel<T>(a: &mut [T], p: usize, q: usize, r: usize)
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

    let mut i = 0;
    let mut j = 0;

    for k in p..=r {
        if i < n1 && j < n2 {
            if larr[i] <= rarr[j] {
                a[k] = larr[i];
                i += 1;
            } else {
                a[k] = rarr[j];
                j += 1;
            }
        } else {
            if i < n1 {
                a[k] = larr[i];
                i += 1;
            } else if j < n2 {
                a[k] = rarr[j];
                j += 1;
            }
        }
    }
}

pub fn merge_sort_no_sentinel<T>(a: &mut [T], p: usize, r: usize)
where
    T: Copy,
    T: Ord,
{
    if p < r {
        let q = (p + r) / 2;
        merge_sort_no_sentinel(a, p, q);
        merge_sort_no_sentinel(a, q + 1, r);
        merge_no_sentinel(a, p, q, r);
    }
}

// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e
pub fn bubble_sort<T>(a: &mut [T])
where
    T: Copy,
    T: Ord,
{
    for i in 0..a.len() - 1 {
        for j in (i + 1..=a.len() - 1).rev() {
            if a[j] < a[j - 1] {
                (a[j], a[j - 1]) = (a[j - 1], a[j]);
            }
        }
    }
}

// Count-Inversions and Merge-Inversion algorithms from problem 2-4 p.42 of CLRS 3e
fn merge_inversions<T>(a: &mut [T], p: usize, q: usize, r: usize, infinity: T) -> usize
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
            inversions += n1 - i;
            counted = true;
        }

        if larr[i] <= rarr[j] {
            a[k] = larr[i];
            i += 1;
        } else {
            a[k] = rarr[j];
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
        inversions += merge_inversions(a, p, q, r, infinity);
    }

    inversions
}
