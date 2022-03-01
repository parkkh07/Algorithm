def func(k):
    if k == m:
        for i in range(m):
            print(arr[i],end=' ')
        print('\n',end='')
        return
    for i in n_list: 
        arr[k] = i        
        func(k+1)
          
n,m = map(int,input().split(' '))
n_list = sorted(list(map(int,input().split(' '))))
arr = [0 for _ in range(10)]
func(0)