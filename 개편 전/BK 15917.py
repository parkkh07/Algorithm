import sys
for i in range(int(input())):
    a = int(sys.stdin.readline())
    if(a&(-a)) == a:
        print(1)
    else:
        print(0)
