def binary_search(a,key):
    pl = 0
    pr = len(a) -1
    while True:
        pc = (pl + pr)//2
        if a[pc] == key: return 1
        elif a[pc] < key: pl = pc + 1
        else: pr = pc-1

        if pl > pr:
            return 0
     
# A must be sorted list
# A = [1,2,3,4,5,6,7,8]
# key = 3
# print(binary_search(A,key))