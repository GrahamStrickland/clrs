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

    println!("Comparison of running times for the largest problem size n of a problem that can be solved in time t, assuming that the algorithm to 
solve the problem takes f(n) microseconds:");
    println!("{:-<136}", "");
    println!("f(n)\t\t1 s\t\t1m\t\t1h\t\t1d\t\t1w\t\t1m\t\t1y\t\t1c");
    println!("{:-<136}", "");

    for header in headers.iter() {
        print!("{:<8}", header);

        for &time in &runtimes {
            let msecs = time.num_microseconds().unwrap() as f64;

            let smallest_n = match *header {
                "lg(n)" => (2f64).powf(msecs),
                "sqrt(n)" => (msecs).powi(2),
                "n" => msecs,
                "nlg(n)" => inverse_nlogn(msecs),
                "n^2" => (msecs).sqrt(),
                "n^3" => (msecs).powf(1.0 / 3.0),
                "2^n" => msecs.ln() / LN_2,
                "n!" => inverse_factorial(msecs),
                _ => 0.0,
            };

            print!("{}", fmt_f64(smallest_n, 16, 8, 2));
        }
        println!();
    }
    println!("{:-<136}", "");
}
