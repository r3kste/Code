with open("/home/h3kste12/code/aoc/2023/20/input.txt", "r") as input_file:
    p = {}

    for line in input_file:
        words = line.split(" ")
        typ = words[0][0]
        module = words[0][1:]
        targets = []
        for word in words[2:]:
            targets.append(word[:-1])
        p[module] = (typ, targets)

for module in p:
    typ, targets = p[module]
    state = None
    if typ == "%":
        state = "off"
    elif typ == "&":
        state = {}
        for j in p:
            if module in p[j][1]:
                state[j] = "low"
    p[module] = (typ, targets, state)

feed = (module for module in p if "rx" in p[module][1])
length = {}
seen = {}


from collections import deque as q

c = 0
while True:  # button presses
    c += 1
    ops = q(())
    # (target,pulse,from)
    brodcast_targets = p["roadcaster"][1]
    for brodcast_target in brodcast_targets:
        ops.append((brodcast_target, "low", "roadcaster"))
    while ops:
        module, pulse, origin = ops.popleft()
        if module not in p:
            continue
        typ = p[module][0]
        targets = p[module][1]
        state = p[module][2]

        if module == "vd" and pulse == "high":
            if origin not in seen:
                seen[origin] = 1

            if origin not in length:
                length[origin] = c

            if all(seen.values()) and len(seen) == 4:
                print(length)
                exit(0)
        if typ == "%":
            if pulse == "low":
                if state == "off":
                    p[module] = (typ, targets, "on")
                    output = "high"
                else:
                    p[module] = (typ, targets, "off")
                    output = "low"

                for target in targets:
                    ops.append((target, output, module))

        elif typ == "&":
            p[module][2][origin] = pulse
            if all(x == "high" for x in p[module][2].values()):
                output = "low"
            else:
                output = "high"
            for target in targets:
                ops.append((target, output, module))
