use std::f64::consts::LN_2;

use chrono::Duration;

use clrs_big_oh::{inverse_factorial, inverse_nlogn};
use clrs_utils::fmt_f64;

fn main() {
    let runtimes = [
        Duration::seconds(1),
        Duration::minutes(1),
        Duration::hours(1),
        Duration::days(1),
        Duration::days(30),
        Duration::days(365),
        Duration::days(36500),
    ];

    let headers = ["lg(n)", "sqrt(n)", "n", "nlg(n)", "n^2", "n^3", "2^n", "n!"];

    println!(
        "Comparison of running times for the largest problem size n of a problem that can be \
        solved in time t, assuming that the\nalgorithm to solve the problem takes f(n) microseconds:"
    );
    println!("{:-<120}", "");
    println!("f(n)\t\t1 s\t\t1m\t\t1h\t\t1d\t\t1m\t\t1y\t\t1c");
    println!("{:-<120}", "");

    for header in headers.iter() {
        print!("{:<8}", header);

        for &time in &runtimes {
            let msecs = time.num_microseconds().unwrap_or(0) as f64;

            let smallest_n = match *header {
                "lg(n)" => (2f64).powf(msecs),
                "sqrt(n)" => (msecs).powf(2f64),
                "n" => msecs,
                "nlg(n)" => inverse_nlogn(msecs),
                "n^2" => (msecs).sqrt(),
                "n^3" => (msecs).powf(1f64 / 3f64),
                "2^n" => msecs.ln() / LN_2,
                "n!" => inverse_factorial(msecs),
                _ => 0f64,
            };

            print!("{}", fmt_f64(smallest_n.floor(), 16, 8, 2));
        }
        println!();
    }
    println!("{:-<120}", "");
}
