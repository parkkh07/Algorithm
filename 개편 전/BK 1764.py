import sys
a,b = map(int, input().split(' '))
arr = []
v = []
for i in range(a+b):
    arr.append(sys.stdin.readline().rstrip())
arr.sort()
for i in range(a+b-1):
    if arr[i] == arr[i+1]:
        v.append(arr[i])
print(len(v))
for i in v:
    print(i)
