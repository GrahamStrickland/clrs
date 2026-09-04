use std::env;
use std::time::Instant;

use rand::Rng;

use clrs_algorithms::max_subarray::{brute_force_find_maximum_subarray, find_maximum_subarray};

fn get_daily_changes(stock_prices: &Vec<i32>, num_stocks: usize) -> Vec<i32> {
    let mut daily_changes = Vec::new();
    for i in 1..num_stocks {
        daily_changes.push(stock_prices[i] - stock_prices[i - 1]);
    }
    daily_changes
}

fn benchmark_algorithm(
    stock_prices: &Vec<i32>,
    num_stocks: usize,
    max_subarray_algorithm: fn(&[i32], usize, usize) -> (usize, usize, i32),
    algorithm_name: &'static str,
) {
    let daily_changes = get_daily_changes(stock_prices, num_stocks);

    let start = Instant::now();
    max_subarray_algorithm(&daily_changes, 0, num_stocks - 2);
    let duration = start.elapsed();

    println!(
        "Execution time for algorithm \"{}\": {} ms",
        algorithm_name,
        (duration.as_nanos() as f64) / 1.0e6
    );
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!(
            "Error: Please an integer argument greater than 3 for the maximum size of array used in benchmarking."
        );
        eprintln!("Usage: {} <number>", &args[0]);
        return;
    }

    let max_array_size = match args[1].parse::<usize>() {
        Ok(number) => {
            if number < 3 {
                eprintln!("Error: Please enter an integer amount greater than 3.");
                return;
            }
            number
        }
        Err(_) => {
            eprintln!("Error: The argument provided is not a valid integer.");
            return;
        }
    };

    const ALGORITHMS_AND_NAMES: [(
        fn(&[i32], usize, usize) -> (usize, usize, i32),
        &'static str,
    ); 2] = [
        (find_maximum_subarray, "find_maximum_subarray"),
        (
            brute_force_find_maximum_subarray,
            "brute_force_find_maximum_subarray",
        ),
    ];

    let mut rng = rand::rng();
    let mut stock_prices = vec![];
    stock_prices.reserve(max_array_size);
    for num_stocks in 3..=max_array_size {
        println!("{:-<120}", "");
        println!("Results for array of size {}:", num_stocks);
        println!("{:-<120}", "");
        stock_prices.clear();
        for _ in 0..num_stocks {
            stock_prices.push(rng.random_range(i32::MIN / 2..=i32::MAX / 2));
        }

        for (func, name) in ALGORITHMS_AND_NAMES {
            benchmark_algorithm(&stock_prices, num_stocks, func, name);
        }
    }
}
