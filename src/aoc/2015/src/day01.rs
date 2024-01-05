use std::{env, fs};

fn main() {
    let input_file = fs::read_to_string(
        env::current_dir()
            .unwrap()
            .parent()
            .unwrap()
            .join(".inputs/day01.txt"),
    )
    .expect("File Not Found!");
    let mut oc = 0;
    let mut cc = 0;
    let mut _part1: bool = false;
    let mut _part2: bool = false;
    let mut _part1ans: i32 = 0;
    let mut _part2ans: i32 = 0;
    for char in input_file.chars() {
        if char == ')' {
            cc += 1;
        } else {
            oc += 1;
        }
        if cc > oc && !_part2 {
            _part2ans = cc + oc;
            _part2 = true;
        }
    }
    _part1ans = (oc - cc).abs();
    println!("Day 01\nPart 1: {}\nPart 2: {}", _part1ans, _part2ans);
}
