t = int(input())
for __ in range(t):
    s = input()
    words = s.split(" ")
    words = [x.lower() for x in words]
    o = ""
    for _ in words:
        o += _[1:2] + _[2:] + _[0] + "ay "
    print(o.capitalize())
