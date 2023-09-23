fn main(){
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of x is: {x}");
    println!("The value of y is: {y}");
    println!("The value of z is: {z}");
    println!("The value of 1st tuple is: {}", tup.0);
    println!("The value of 2nd tuple is: {}", tup.1);
    println!("The value of 3rd tuple is: {}", tup.2);
}