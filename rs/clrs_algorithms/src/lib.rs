pub mod big_o;
pub mod binary;
pub mod search;
pub mod sorting;

#[cfg(test)]
mod tests {
    use super::big_o::{inverse_factorial, inverse_nlogn};
    use chrono::{Duration, TimeDelta};

    const RUNTIMES: [TimeDelta; 7] = [
        Duration::seconds(1),
        Duration::minutes(1),
        Duration::hours(1),
        Duration::days(1),
        Duration::days(30),
        Duration::days(365),
        Duration::days(36500),
    ];

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

    use super::sorting::insertion_sort;

    #[test]
    fn test_insertion_sort() {
        let input_vecs = vec![
            vec![5, 2, 7, 4, 6, 1, 3, 8],
            vec![31, 41, 59, 26, 41, 58, 59, 45],
            vec![8, 7, 6, 5, 4, 3, 2, 1],
            vec![5, 2, 4, 7, 1, 3, 2, 6],
            vec![3, 41, 52, 26, 38, 57, 9, 49],
        ];

        for vec in input_vecs.iter() {
            let mut obs = Vec::new();
            let mut actual = Vec::new();
            for elem in vec {
                obs.push(*elem);
                actual.push(*elem);
            }
            actual.sort();
            insertion_sort::<i32>(&mut obs);
            assert_eq!(obs, actual);
        }
    }

    use super::search::linear_search;

    #[test]
    fn test_linear_search() {
        let input_vecs = vec![
            vec![26, 31, 41, 41, 58, 59, 101, 104],
            vec![26, 31, 41, 41, 58, 59, 101, 104],
            vec![1, 4, 5, 7, 19, 28, 45, 92],
            vec![1, 4, 5, 7, 19, 28, 45, 92],
        ];
        let input_vals = vec![31, 32, 92, 101];
        let expected_vals = vec![Some(1), None, Some(7), None];

        for (i, vec) in input_vecs.iter().enumerate() {
            let res = linear_search::<i32>(&vec, &input_vals[i]);
            assert_eq!(res, expected_vals[i]);
        }
    }

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
