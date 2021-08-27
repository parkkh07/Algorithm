import sys
sys.setrecursionlimit(10**6)
def lucas():   
    n,k,m = map(int,sys.stdin.readline().strip('\n').split(' '))
    binomial = [[0 for i in range(2010)] for j in range(2010)]
    for i in range(m):
        binomial[i][0] = 1
        for j in range(1,i+1):
            binomial[i][j] = (binomial[i-1][j-1] + binomial[i-1][j]) % m

    ret = 1
    while n or k:
        ret *= binomial[n%m][k%m]
        n = n // m
        k = k // m
        ret %= m
    return ret
print(lucas())

