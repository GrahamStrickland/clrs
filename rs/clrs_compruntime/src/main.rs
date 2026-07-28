use std::f64::consts::LN_2;

use chrono::Duration;

use clrs_algorithms::big_o::{inverse_factorial, inverse_nlogn};
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

    let column_headers = [
        "1 second", "1 minute", "1 hour", "1 day", "1 month", "1 year", "1 century",
    ];

    println!(
        "Comparison of running times for the largest problem size n of a problem that can be \
        solved in time t, assuming that the\nalgorithm to solve the problem takes f(n) microseconds:"
    );
    println!("{:-<120}", "");
    print!("{:<8}", "f(n)");
    for column_header in column_headers.iter() {
        print!("{:>16}", column_header);
    }
    println!();
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
                "n^3" => (msecs).cbrt(),
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
