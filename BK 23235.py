c = 0
while True:
    try:
        a = input()
        if a == '0':
            break
        c += 1
    except: break
for i in range(1,c+1):
    print(f'Case {i}: Sorting... done!')
        