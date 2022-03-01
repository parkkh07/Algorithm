import heapq
import sys

heap = []

for i in range(int(input())):
    a = int(input())
    if a:
        heapq.heappush(heap,a)
    else:
        if len(heap):
            print(heapq.heappop(heap))
        else:
            print('0')