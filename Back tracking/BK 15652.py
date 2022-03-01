def func(k):
    if k == m:
        for i in range(m):
            print(arr[i],end=' ')
        print('\n',end='')
        return
    for i in range(1,n+1):
        if i >= arr[k-1]:
            arr[k] = i
            func(k+1)

n,m = map(int,input().split(' '))
arr = [0 for _ in range(10)]
func(0)