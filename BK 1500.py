n, k = map(int, input().split(' '))
arr = [0 for _ in range(k)]
sum = 1
for i in range(k):
    arr[i] += n // k

for i in range(n%k):
    arr[i] += 1

for i in range(k):
    sum *= arr[i]

print(sum)