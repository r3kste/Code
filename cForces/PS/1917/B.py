dp = {}
seen = set()


def f(s):
    print('',end='')


t = int(input())

ans = []
for _ in range(t):
    dp = {}
    n = int(input())
    s = input()
    ans.append(f(s))

for _ in ans:
    print(_)
