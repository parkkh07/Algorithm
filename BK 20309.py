 n=int(input())
a=list(map(int,input().split()))

for i in range(n):
    if(i+1)%2!=a[i]%2:
        print("NO")
        exit()
print("YES")

