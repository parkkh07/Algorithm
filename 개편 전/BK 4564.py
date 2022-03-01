while True:
    try:
        a = input()
        if a =='0':break
        
        while True: 
            s = 1

            print(a,end=' ')
            if len(a) == 1:
                break
            for i in a:
                s *= int(i)
            a = str(s)


        print('\n',end='')

    except EOFError:
        break