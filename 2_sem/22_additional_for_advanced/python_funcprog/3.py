def check(x):
    return x ** 0.5 == int(x ** 0.5)

result = filter(check, range(100, 10_000))
print(list(result))

# ---

temp = list(range(1, 10))
temp2 = list(filter(check, range(100, 10_000)))
print(*zip(temp, temp2))