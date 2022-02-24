#함수의 정의
#원판 n개를 a번 기둥에서 b번 기둥으로
def hanoi(a,b,n):
    if n == 1:
        print(a,b) # base condition
        return 0 
    hanoi(a,6-a-b,n-1)
    print(a,b)
    hanoi(6-a-b,b,n-1)

n = int(input())
print(2**n -1)
hanoi(1,3,n)