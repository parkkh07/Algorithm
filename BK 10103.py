a,b = 100, 100
for i in range(int(input())):
    n,k = map(int, input().split(' '))
    if n > k:
        b -= n
    elif n < k:
        a -= k
print(a,b)