import sys

n,k = map(int, input().split(' '))
list = []
count = 0

for i in range(n):
    list.append(int(sys.stdin.readline().rstrip()))

for i in range(n-1,-1,-1):
    if list[i] <= k:
        count += (k //list[i])
        k -= list[i] * (k // list[i])

print(count)
