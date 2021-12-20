a = input()
cnt = 0
while len(a) >1:
    s = 1
    for i in a: s *= int(i)
    cnt += 1
    a = str(s)
print(cnt)

