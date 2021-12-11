l = []
a,b = map(int, input().split(' '))
for i in range(1,46):
    for k in range(1,i+1):
        l.append(i)

print(sum(l[a-1:b]))