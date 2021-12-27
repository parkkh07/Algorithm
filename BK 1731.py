a = []
for i in range(int(input())):
    a.append(int(input()))
st = a[1] - a[0]

for i in range(len(a) - 1):
    if a[i+1] - a[i] != st:
        print( (a[1] // a[0]) * a[-1] )
        exit()
print(a[-1] + (a[1] - a[0]))
