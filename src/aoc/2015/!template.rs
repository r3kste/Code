fn part1(input_file: &String) -> i32 {
    return 0;
}

fn part2(input_file: &String) -> i32 {
    return 0;
}

fn main() {
    let input_file = std::fs::read_to_string(
        std::path::PathBuf::from(std::env::var("FILE_DIR").unwrap())
            .parent()
            .unwrap()
            .join(".inputs/day0x.txt"),
    )
    .expect("File Not Found!");

    let _part1ans: i32 = part1(&input_file);
    println!("Day 0X\nPart 1: {}", _part1ans);

    let _part2ans: i32 = part2(&input_file);
    println!("Part 2: {}", _part2ans);
}
