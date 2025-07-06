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
