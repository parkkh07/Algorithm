a = list(map(int,' '.join(input()).split(' ') ))
if sum(a[:len(a)//2]) == sum(a[len(a)//2:]):print('LUCKY')
else:print('READY')