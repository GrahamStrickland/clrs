use std::f64::consts::LN_2;

use chrono::Duration;

use compruntime::fmt_f64;
use compruntime::inverse_factorial;
use compruntime::inverse_nlogn;

fn main() {
    let runtimes = [
        Duration::seconds(1),
        Duration::minutes(1),
        Duration::hours(1),
        Duration::days(1),
        Duration::days(30),
        Duration::days(365),
        Duration::days(36500),
        Duration::days(3650000),
    ];

    let headers = ["lg(n)", "sqrt(n)", "n", "nlg(n)", "n^2", "n^3", "2^n", "n!"];

    println!(
        "Comparison of running times for the largest problem size n of a problem that can be solved in time t,"
    );
    println!("assuming that the algorithm to solve the problem takes f(n) microseconds:\n");
    println!("{:-<136}", "");
    println!("f(n)\t\t1 s\t\t1m\t\t1h\t\t1d\t\t1w\t\t1m\t\t1y\t\t1c");
    println!("{:-<136}", "");

    for header in headers.iter() {
        print!("{:<8}", header);

        for &time in &runtimes {
            let secs = time.num_seconds() as f64;

            let smallest_n = match *header {
                "lg(n)" => (2f64).powf(secs),
                "sqrt(n)" => (secs).powi(2),
                "n" => secs,
                "nlg(n)" => inverse_nlogn(secs),
                "n^2" => (secs).sqrt(),
                "n^3" => (secs).powf(1.0 / 3.0),
                "2^n" => secs.ln() / LN_2,
                "n!" => inverse_factorial(secs),
                _ => 0.0,
            };

            print!("{}", fmt_f64(smallest_n, 16, 8, 2));
        }
        println!();
    }
    println!("{:-<136}", "");
}
