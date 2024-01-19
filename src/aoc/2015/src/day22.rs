use std::{cmp::min, collections::HashMap, i32::MAX};

fn f(
    spells: &HashMap<&str, HashMap<&str, i32>>,
    mut boss_stats: (i32, i32),
    mut player_stats: (i32, i32),
    shield_tick: i32,
    poison_tick: i32,
    recharge_tick: i32,
    turn: i32,
    remaining_moves: i32,
) -> i32 {
    boss_stats.0 -= if poison_tick > 0 {
        spells["Poison"]["Damage"]
    } else {
        0
    };
    let armor = if shield_tick > 0 {
        spells["Shield"]["Armor"]
    } else {
        0
    };
    player_stats.1 += if recharge_tick > 0 {
        spells["Recharge"]["Recharge"]
    } else {
        0
    };
    if turn == 1 {
        if boss_stats.0 <= 0 {
            return 0;
        } else {
            let mut new_player_stats = player_stats;
            new_player_stats.0 -= min(1, boss_stats.1 - armor);
            return f(
                spells,
                boss_stats,
                new_player_stats,
                shield_tick - 1,
                poison_tick - 1,
                recharge_tick - 1,
                turn ^ 1,
                remaining_moves - 1,
            );
        }
    } else {
        let mut min_cost = MAX;
        let mana = player_stats.1;
        if mana < 53 {
            return MAX;
        }
        if mana >= 53 {
            let mut new_boss_stats = boss_stats;
            new_boss_stats.0 -= spells["Magic Missile"]["Damage"];
            min_cost = min_cost.min(f(
                spells,
                new_boss_stats,
                player_stats,
                shield_tick - 1,
                poison_tick - 1,
                recharge_tick - 1,
                turn ^ 1,
                remaining_moves - 1,
            ));
        }
        if mana >= 73 {
            let mut new_boss_stats = boss_stats;
            new_boss_stats.0 -= spells["Drain"]["Damage"];
            let mut new_player_stats = player_stats;
            new_player_stats.0 += spells["Drain"]["Health"];
            min_cost = min_cost.min(f(
                spells,
                new_boss_stats,
                player_stats,
                shield_tick - 1,
                poison_tick - 1,
                recharge_tick - 1,
                turn ^ 1,
                remaining_moves - 1,
            ));
        }
        return min_cost;
    }
}
fn part1(input_file: &String) -> i32 {
    let mut spells: HashMap<&str, HashMap<&str, i32>> = HashMap::new();

    spells.insert("Magic Missile", HashMap::new());
    let temp = spells.get_mut("Magic Missile").unwrap();
    temp.insert("Cost", 53);
    temp.insert("Damage", 4);

    spells.insert("Drain", HashMap::new());
    let temp = spells.get_mut("Drain").unwrap();
    temp.insert("Cost", 73);
    temp.insert("Damage", 2);
    temp.insert("Health", 2);

    spells.insert("Shield", HashMap::new());
    let temp = spells.get_mut("Shield").unwrap();
    temp.insert("Cost", 113);
    temp.insert("Armor", 7);
    temp.insert("Ticks", 6);

    spells.insert("Poison", HashMap::new());
    let temp = spells.get_mut("Drain").unwrap();
    temp.insert("Cost", 173);
    temp.insert("Damage", 3);
    temp.insert("Ticks", 6);

    spells.insert("Recharge", HashMap::new());
    let temp = spells.get_mut("Recharge").unwrap();
    temp.insert("Cost", 229);
    temp.insert("Recharge", 101);
    temp.insert("Ticks", 5);

    return 0;
}

fn part2(input_file: &String) -> i32 {
    return 0;
}

fn part1n2(input_file: &String) -> (i32, i32) {
    return (0, 0);
}

fn main() {
    let input_file = std::fs::read_to_string(
        std::path::PathBuf::from(std::env::var("FILE_DIR").unwrap())
            .parent()
            .unwrap()
            .join(".inputs/day22.txt"),
    )
    .expect("File Not Found!");

    let _part1ans: i32 = part1(&input_file);
    println!("Day 22\nPart 1: {}", _part1ans);

    let _part2ans: i32 = part2(&input_file);
    println!("Part 2: {}", _part2ans);

    let (_part1ans, _part2ans): (i32, i32) = part1n2(&input_file);
    println!("Day X\nPart 1: {}\nPart 2: {}", _part1ans, _part2ans);
}
