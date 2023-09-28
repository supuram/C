// https://doc.rust-lang.org/book/ch08-01-vectors.html

fn main() {
    let mut v = vec![1, 2, 3, 4, 5];
    let first = &v[0];
    println!("{}", first);
    v.push(6); 
    println!("The vector is {:?}", v);

    let mut s = String::from("Hmmmmm");
    let first = s.chars().next();
    println!("{:?}", first);
    s.push_str("Good");
    println!("{} ", s);

}