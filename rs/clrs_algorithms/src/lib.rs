pub mod big_o;
pub mod binary;
pub mod search;
pub mod sorting;

use chrono::{Duration, TimeDelta};

#[allow(dead_code)]
const RUNTIMES: [TimeDelta; 7] = [
    Duration::seconds(1),
    Duration::minutes(1),
    Duration::hours(1),
    Duration::days(1),
    Duration::days(30),
    Duration::days(365),
    Duration::days(36500),
];

#[allow(dead_code)]
const SORTING_VECS: [[i32; 8]; 5] = [
    [5, 2, 7, 4, 6, 1, 3, 8],
    [31, 41, 59, 26, 41, 58, 59, 45],
    [8, 7, 6, 5, 4, 3, 2, 1],
    [5, 2, 4, 7, 1, 3, 2, 6],
    [3, 41, 52, 26, 38, 57, 9, 49],
];

#[allow(dead_code)]
const SEARCHING_VECS: [[i32; 8]; 4] = [
    [26, 31, 41, 41, 58, 59, 101, 104],
    [26, 31, 41, 41, 58, 59, 101, 104],
    [1, 4, 5, 7, 19, 28, 45, 92],
    [1, 4, 5, 7, 19, 28, 45, 92],
];
#[allow(dead_code)]
const SEARCHING_VALS: [i32; 4] = [31, 32, 92, 101];
#[allow(dead_code)]
const EXPECTED_SEARCHES: [Option<usize>; 4] = [Some(1), None, Some(7), None];

#[allow(dead_code)]
fn test_sort_i32(sorting_algorithm: fn(&mut [i32])) {
    for vec in SORTING_VECS.iter() {
        let mut obs = Vec::new();
        let mut actual = Vec::new();
        for elem in vec {
            obs.push(*elem);
            actual.push(*elem);
        }
        actual.sort();
        sorting_algorithm(&mut obs);
        assert_eq!(obs, actual);
    }
}

#[cfg(test)]
mod tests {
    // Big O algorithm tests
    use super::big_o::{inverse_factorial, inverse_nlogn};
    use super::{RUNTIMES, SORTING_VECS, SEARCHING_VECS, SEARCHING_VALS, EXPECTED_SEARCHES};

    #[test]
    fn test_inverse_nlogn() {
        let exps = vec![
            62746.0,
            2801417.0,
            133378058.0,
            2755147513.0,
            71870856404.0,
            797633893349.0,
            68654697441062.0,
        ];

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_nlogn(time_in_microseconds);
            let tol = 1e-3;

            assert!((res - exp).abs() / exp < tol);
        }
    }

    #[test]
    fn test_inverse_factorial() {
        let exps = vec![10.0, 12.0, 13.0, 14.0, 16.0, 17.0, 18.0];

        for (t, exp) in RUNTIMES.iter().zip(exps.iter()) {
            let time_in_microseconds = t.num_microseconds().unwrap_or(0) as f64;
            let res = inverse_factorial(time_in_microseconds);
            assert_eq!(res, *exp);
        }
    }

    // Sorting algorithm tests
    use super::sorting::insertion_sort;
    use super::test_sort_i32;
    #[test]
    fn test_insertion_sort() {
        test_sort_i32(insertion_sort::<i32>);
    }

    use super::sorting::selection_sort;
    #[test]
    fn test_selection_sort() {
        test_sort_i32(selection_sort::<i32>);
    }

    use super::sorting::merge_sort;
    #[test]
    fn test_merge_sort() {
        for vec in SORTING_VECS.iter() {
            let mut obs = Vec::new();
            let mut actual = Vec::new();
            for elem in vec {
                obs.push(*elem);
                actual.push(*elem);
            }
            let len = obs.len() - 1;
            actual.sort();
            merge_sort(&mut obs, 0, len, i32::MAX);
            assert_eq!(obs, actual);
        }
    }

    use super::sorting::merge_sort_no_sentinel;
    #[test]
    fn test_merge_sort_no_sentinel() {
        for vec in SORTING_VECS.iter() {
            let mut obs = Vec::new();
            let mut actual = Vec::new();
            for elem in vec {
                obs.push(*elem);
                actual.push(*elem);
            }
            let len = obs.len() - 1;
            actual.sort();
            merge_sort_no_sentinel(&mut obs, 0, len);
            assert_eq!(obs, actual);
        }
    }

    use super::sorting::bubble_sort;
    #[test]
    fn test_bubble_sort() {
        test_sort_i32(bubble_sort::<i32>);
    }

    // Search algorithm tests
    use super::search::{binary_search, linear_search};

    #[test]
    fn test_linear_search() {
        for (i, vec) in SEARCHING_VECS.iter().enumerate() {
            let res = linear_search::<i32>(vec, &SEARCHING_VALS[i]);
            assert_eq!(res, EXPECTED_SEARCHES[i]);
        }
    }

    #[test]
    fn test_binary_search() {
        for (i, vec) in SEARCHING_VECS.iter().enumerate() {
            let res = binary_search::<i32>(vec, &SEARCHING_VALS[i]);
            assert_eq!(res, EXPECTED_SEARCHES[i]);
        }
    }

    // Binary algorithm tests
    use super::binary::binary_addition;

    #[test]
    fn test_binary_addition() {
        let inp_bits_vec: Vec<Vec<u8>> = vec![
            vec![0, 0, 0, 0, 0, 0, 0],
            vec![1, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 1],
            vec![1, 0, 0, 0, 0, 0, 1],
        ];
        let exp_bits_vec: Vec<Vec<u8>> = vec![
            vec![1, 1, 1, 1, 1, 1, 1, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 1],
            vec![1, 1, 1, 1, 1, 1, 0, 1],
            vec![0, 0, 0, 0, 0, 0, 1, 1],
        ];
        let rhs: Vec<u8> = vec![1, 1, 1, 1, 1, 1, 1];

        for (inp_bits, exp_bits) in inp_bits_vec.iter().zip(exp_bits_vec.iter()) {
            let output_bits = binary_addition(&inp_bits, &rhs);
            assert_eq!(output_bits, *exp_bits);
        }
    }
}
