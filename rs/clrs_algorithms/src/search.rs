// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e
pub fn linear_search<T>(a: &[T], nu: &T) -> Option<usize>
where
    T: Copy,
    T: Ord,
{
    let mut j: usize = 0;

    while j != a.len() {
        if a[j] == *nu {
            return Some(j);
        } else {
            j += 1;
        }
    }

    None
}

// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e
pub fn binary_search<T>(a: &[T], nu: &T) -> Option<usize>
where
    T: Copy,
    T: Ord,
{
    let mut low = 0;
    let mut high = a.len() - 1;

    while low <= high {
        let mid = low + (high - low) / 2;

        if a[mid] == *nu {
            return Some(mid);
        } else if a[mid] < *nu {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    None
}
