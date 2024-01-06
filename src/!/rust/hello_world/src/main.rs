fn main() {
    println!("Hello, world!");
    for (key, value) in std::env::vars() {
        println!("{}: {}", key, value);
    }
}
