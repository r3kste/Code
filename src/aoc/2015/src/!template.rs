use std::{env, fs};

fn main() {
    let _input_file = fs::read_to_string(
        env::current_dir()
            .unwrap()
            .parent()
            .unwrap()
            .join(".inputs/day0X.txt"),
    )
    .expect("File Not Found!");
    let mut _part1: bool = false;
    let mut _part2: bool = false;
    let mut _part1ans: i32 = 0;
    let mut _part2ans: i32 = 0;
    println!("Day 0X\nPart 1: {}\nPart 2: {}", _part1ans, _part2ans);
}
