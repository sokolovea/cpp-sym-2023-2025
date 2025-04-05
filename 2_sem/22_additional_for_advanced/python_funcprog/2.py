ls = [1, 3, 5, 100, -2, 3, 6]
it = iter(ls)
print(next(it))
print(next(it))
print(next(it)) #пока не получим исключение StopIteration
print('---')
for x in it:
    print(x)

print('---')

ls_it = (i ** 2 for i in range(1_000_000_000_000) if i % 2 == 0)

for i in range(10):
    print(next(ls_it))

print('---')

def numbers():
    i = 0
    while True:
        yield i
        i += 1

# for x in numbers():
#     print(x)