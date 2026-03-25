n = int(input())

if n % 12 == 0:
    print((n // 12) * 15000)
elif n % 9 == 0:
    print((n // 9) * 12000)
elif n % 6 == 0:
    print((n // 6) * 9000)
elif n % 3 == 0:
    print((n // 3) * 5000)
else:
    print("Error")
