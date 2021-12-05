def fast_mpow(x,y,z):
    tmp = 1
    x %= z
    while(y):
        if y %2 == 1:
            tmp = ((tmp % z) * (x % z)) % z
        y >>= 1
        x = (x%z) ** 2 % z
    return tmp
    
def miller_rabin(n):
    if n == 1 or n == 0:return 0
    a = [2,3,5,7,11,13,17,19,23,29,31,37,61,83,2**64]
    i = 0
    while a[i] < n:
        s = n-1
        while 1:
            r = fast_mpow(a[i],s,n)
            if r == 1:break
            if s%2:
                if r == n-1:break
                else: return 0
            s >>= 1
        i += 1
    return 1

a = input().upper()
if a == 'a' or a == 'A':
    print("It is a prime word.")
else:
    c = 0
    for i in a:
        c += ord(i) - 64
    if miller_rabin(c):
        print("It is a prime word.")
    else:print("It is not a prime word.")

