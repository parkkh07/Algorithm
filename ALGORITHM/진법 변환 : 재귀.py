n = int(input())
a = int(input())
t = 1
while 1:
    t *= a
    if t * a > n:
        break
    

def binary(t,n):
    if t == 0:
        return    
    print(n // t ,end=' ')
    n -= (n // t) * t
    t //= a
    binary(t,n)
    
binary(t,n)


