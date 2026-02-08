// Find-Maximum-Subarray algorithm from p.71-72 of CLRS 3e
fn find_max_crossing_subarray(
    a: &Vec<i32>,
    low: usize,
    mid: usize,
    high: usize,
) -> (usize, usize, i32) {
    let mut left_sum = i32::MIN;
    let mut sum = 0;
    let mut max_crossing_subarray = (0, 0, 0);

    for i in (low..=mid).rev() {
        sum += a[i];
        if sum > left_sum {
            left_sum = sum;
            max_crossing_subarray.0 = i;
        }
    }

    let mut right_sum = i32::MIN;
    sum = 0;

    for j in (mid + 1)..=high {
        sum += a[j];
        if sum > right_sum {
            right_sum = sum;
            max_crossing_subarray.1 = j;
        }
    }

    max_crossing_subarray.2 = left_sum + right_sum;

    max_crossing_subarray
}

pub fn find_maximum_subarray(a: &Vec<i32>, low: usize, high: usize) -> (usize, usize, i32) {
    if high == low {
        return (low, high, a[low]); // Base case: only one element
    }

    let mid = (low + high) / 2;

    let left_subarray = find_maximum_subarray(a, low, mid);
    let right_subarray = find_maximum_subarray(a, mid + 1, high);
    let cross_subarray = find_max_crossing_subarray(a, low, mid, high);

    if left_subarray.2 >= right_subarray.2 && left_subarray.2 >= cross_subarray.2 {
        return left_subarray;
    } else if right_subarray.2 >= left_subarray.2 && right_subarray.2 >= cross_subarray.2 {
        return right_subarray;
    } else {
        return cross_subarray;
    }
}

// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e
pub fn brute_force_find_maximum_subarray(
    a: &Vec<i32>,
    _low: usize,
    _high: usize,
) -> (usize, usize, i32) {
    let mut max_low = 0;
    let mut max_high = 0;
    let mut max_sum = a[0];

    for i in 0..a.len() {
        let mut current_sum = 0;
        for j in i..a.len() {
            current_sum += a[j];
            if current_sum > max_sum {
                max_sum = current_sum;
                max_low = i;
                max_high = j;
            }
        }
    }

    (max_low, max_high, max_sum)
}

// Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS 3e
pub fn find_maximum_subarray_non_recursive(
    a: &Vec<i32>,
    low: usize,
    high: usize,
) -> (usize, usize, i32) {
    let mut j = low + 1;
    let mut max_subarray = (low, high, a[low] + a[j]);
    let mut current_val;

    while j < high {
        current_val = a[j + 1];
        for i in (low..=j).rev() {
            current_val += a[i];
            if max_subarray.2 < current_val {
                max_subarray = (i, j + 1, current_val);
            }
        }
        j += 1;
    }

    max_subarray
}
