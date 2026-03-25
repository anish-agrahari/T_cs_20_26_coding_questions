n = int(input())
line = input().split(',')

pairs = [(int(x[0]), int(x[1])) for x in line]

pairs.sort()

print(','.join(f"{a}{b}" for a, b in pairs))