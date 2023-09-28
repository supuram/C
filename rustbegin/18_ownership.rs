// https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html
// Check out rustc --explain EO382 in cmd

fn main() {
    let s1 = gives_ownership();   
    println!("main s1 = {}", s1);    
    let s2 = String::from("hello");  
    println!("main s2 = {}", s2);    
    let s3 = takes_and_gives_back(s2);  
    println!("main s3 = {}", s3);
    // println!("main s2 after s3 = {}", s2); will not work as s2 is dropped
} 

fn gives_ownership() -> String {             
    let some_string = String::from("yours"); 
    some_string                              
}

fn takes_and_gives_back(a_string: String) -> String { 
    println!("takes_and_gives_back = {} ", a_string);
    a_string  
}