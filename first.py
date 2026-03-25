from collections import defaultdict

n = int(input())
mp = defaultdict(list)

for _ in range(n):
    s, r, amt, t = input().split()
    mp[(s, r, int(amt))].append(int(t))

res = set()

for key in mp:
    times = sorted(mp[key])
    for i in range(1, len(times)):
        if times[i] - times[i-1] <= 60:
            res.add((key[0], key[1], key[2], times[i-1]))
            res.add((key[0], key[1], key[2], times[i]))

for x in res:
    print(*x)