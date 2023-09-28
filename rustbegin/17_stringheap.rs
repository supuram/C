// https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html

fn main() {
    let mut s = String::from("hello");

    s.push_str(", world!"); // push_str() appends a literal to a String

    println!("{}", s); // This will print `hello, world!`
}