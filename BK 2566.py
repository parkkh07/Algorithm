arr = []
mx = 0
x =0
y = 0
for i in range(9):
    arr.append(list(map(int,input().split(' '))))

for i in range(9):
    for j in range(9):
        if mx < arr[i][j]:
            mx = arr[i][j]
            x = i+1
            y = j+1
print(mx)
print(x,y)