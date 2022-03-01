for w in range(int(input())):
    NumList = [0,0,0,0,0,0,0,0,0,0]
    a = input()
    for i in a:
        NumList[int(i)] = 1
    print(sum(NumList))
