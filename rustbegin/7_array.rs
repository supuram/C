// Number of elements in an array cannot change

fn main() {
    let a = [1, 2, 3, 4, 5];
    println!("{:?}", a);  
    println!("{}", a[0]);
    let a: [i32; 5] = [14, 22, 31, 48, 55];
    println!("{:?}", a);  
}