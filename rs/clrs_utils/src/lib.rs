pub fn fmt_f64(num: f64, width: usize, precision: usize, exp_pad: usize) -> String {
    let mut numstr = format!("{:.precision$e}", num, precision = precision);
    if numstr == "inf" {
        return format!("{:>width$}", numstr, width = width);
    } else if num.fract() == 0.0 && (num as i32) < i32::MAX {
        return format!("{:>width$}", num as i64, width = width);
    }
    let idx = match numstr.find('e') {
        Some(idx) => idx,
        None => return numstr,
    };

    let exp = numstr.split_off(idx);

    let (sign, exp) = if exp.starts_with("e-") {
        ('-', &exp[2..])
    } else {
        ('+', &exp[1..])
    };
    numstr.push_str(&format!("e{}{:0>pad$}", sign, exp, pad = exp_pad));

    format!("{:>width$}", numstr, width = width)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_fmt_f64() {
        let nums = vec![
            62746.0,
            2801417.0,
            133378058.0,
            2755147513.0,
            71870856404.0,
            797633893349.0,
            68654697441062.0,
        ];
        let exps = vec![
            "      62746",
            "    2801417",
            "  133378058",
            "2.75515e+09",
            "7.18709e+10",
            "7.97634e+11",
            "6.86547e+13",
        ];

        for (num, exp) in nums.iter().zip(exps.iter()) {
            let res = fmt_f64(*num, 11, 5, 2);
            assert_eq!(res, String::from(*exp),);
        }
    }

}
