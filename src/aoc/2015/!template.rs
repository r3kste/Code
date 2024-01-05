fn main() {
    let input_file = std::fs::read_to_string(
        std::path::PathBuf::from(std::env::var("FILE_DIR").unwrap())
            .parent()
            .unwrap()
            .join(".inputs/day01.txt"),
    )
    .expect("File Not Found!");

    let _part1ans: i32 = part1(&input_file);
    let _part2ans: i32 = part2(&input_file);

    println!("Day 01\nPart 1: {}\nPart 2: {}", _part1ans, _part2ans);
}

fn part1(input_file: &String) -> i32 {
    return 0;
}

fn part2(input_file: &String) -> i32 {
    return 0;
}
