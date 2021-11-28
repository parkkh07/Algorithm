import heapq
import sys

heap = []
for i in range(int(input())):
    a = int(sys.stdin.readline().rstrip())
    if a:
        heapq.heappush(heap,(-a,a))
    else:
        if len(heap):
            print(heapq.heappop(heap)[1])
        else:
            print('0')