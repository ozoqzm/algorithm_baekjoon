def find_min(a, b):
    return a if a < b else b

N = int(input())

num = [0] * (N + 1)
num[0], num[1] = 0, 0

for i in range(2, N + 1):
    minimum = num[i - 1] + 1
    if i % 3 == 0:
        minimum = find_min(minimum, num[i // 3] + 1)
    if i % 2 == 0:
        minimum = find_min(minimum, num[i // 2] + 1)
    num[i] = minimum

print(num[N])
