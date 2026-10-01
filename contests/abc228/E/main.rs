use std::io;

const MOD: i128 = 998244353;

fn mod_mul((a, b, m): (i128, i128, i128)) -> i128 {
    (a % m * b % m) % m
}

fn mod_pow((mut a, mut b, m): (i128, i128, i128)) -> i128 {
    let mut res = 1;
    a %= m;

    while b != 0 {
        if (b & 1) == 1 {
            res = mod_mul((res, a, m));
        }
        a = mod_mul((a, a, m));
        b >>= 1;
    }
    res
}

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).expect("Invalid input");

    let mut iter = input.split_whitespace();
    let n: i128 = iter.next().unwrap().parse().expect("Not a valid number");
    let k: i128 = iter.next().unwrap().parse().expect("Not a valid number");
    let m: i128 = iter.next().unwrap().parse().expect("Not a valid number");

    if m % MOD == 0 {
        println!("0");
        return;
    }

    let r: i128 = mod_pow((k, n, MOD - 1));
    let res: i128 = mod_pow((m, r, MOD));

    println!("{}", res);
}
