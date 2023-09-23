// https://doc.rust-lang.org/book/ch03-02-data-types.html

fn main() {
    let guess: u32 = "42".parse().expect("Not a number!");
    println!("{}", guess);
}