while True:
    try:
        a = input()
        k = 0
        if a == '*': exit()
        for i in range(ord('a'),ord('z') +1):
            if a.count(chr(i)) < 1:
                print("N")
                k = 1
                break
        if k: continue
        print("Y")
    except EOFError:
        break