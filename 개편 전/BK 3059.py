import sys
for _ in range(int(input())):
    sum = 2015
    t = list(' '.join(sys.stdin.readline().rstrip()).split(' '))
    t = list(set(t))
    for i in t:
        sum -= ord(i)
    print(sum)