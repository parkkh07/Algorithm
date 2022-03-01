sum = 0
a,b = input().split(' ')
for i in range(len(a)):
    for j in range(len(b)):
        sum += int(a[i]) * int(b[j])
print(sum)
