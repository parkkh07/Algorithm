def merge(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    low_arr = merge(arr[:mid])
    high_arr = merge(arr[mid:])
    l = h = 0
    merged_arr = []
    while l<len(low_arr) and h <len(high_arr):
        if low_arr[l] < high_arr[h]:
            merged_arr.append(low_arr[l])
            l +=1
        else:
            merged_arr.append(high_arr[h])
            h +=1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr
a = list(map(int,input().split()))
print(merge(a))