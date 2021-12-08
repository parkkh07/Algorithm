a=int(input())
for i in range(a+2):
    if i == 0 or i == a+1:
        for j in range(a+2):
            print("@",end='')
        print('\n',end='')
    else:
        print("@",end='')
        for j in range(a):
            print(' ',end='')
        print('@')