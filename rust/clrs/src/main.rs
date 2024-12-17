use chrono::Duration;

use clrs::fmt_f64;
use clrs::inverse_factorial;
use clrs::inverse_nlogn;

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

    println!("Comparison of running times for the largest problem size n of a problem that can be solved in time t:");
    println!("Assuming that the algorithm to solve the problem takes f(n) microseconds:\n");
    println!("{:-<140}", "");
    println!("f(n)\t\t1s\t\t1m\t\t1h\t\t1d\t\t1w\t\t1m\t\t1y\t\t1c");
    println!("{:-<140}", "");

    for header in headers.iter() {
        print!("{:<8}", header);

        for &time in &runtimes {
            let time_in_microseconds = time.num_microseconds().unwrap_or(0) as f64;

            let smallest_n = match *header {
                "lg(n)" => (2f64).powf(time_in_microseconds / 1E6),
                "sqrt(n)" => (time_in_microseconds / 1E6).powi(2),
                "n" => time_in_microseconds / 1E6,
                "nlg(n)" => inverse_nlogn(time_in_microseconds),
                "n^2" => (time_in_microseconds / 1E6).sqrt(),
                "n^3" => (time_in_microseconds / 1E6).powf(1.0 / 3.0),
                "2^n" => time_in_microseconds.ln() / 2f64.ln(),
                "n!" => inverse_factorial(time_in_microseconds),
                _ => 0.0,
            };

            print!("{}", fmt_f64(smallest_n, 12, 3, 2));
        }
        println!();
    }
    println!("{:-<120}", "");
}
