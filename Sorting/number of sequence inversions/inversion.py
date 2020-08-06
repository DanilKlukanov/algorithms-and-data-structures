def merge_sort_count(a):
    _, count = merge_sort(a.copy())
    return count
def merge_sort(a):
    n = len(a)
    if n==1:
        return a, 0
    left = a[0:n//2] 
    left, ct1 = merge_sort(left)
    right = a[n//2:] 
    right, ct2 = merge_sort(right)

    ct = 0
    x = y = p = 0
    while p < n:
        if (y>=len(right)) or (x < len(left) and left[x] <= right[y]):
            a[p] = left[x]
            x += 1
        else:
            a[p] = right[y]
            y += 1
            if x < len(left):
                ct += len(left) - x
        p += 1
    return a, ct1 + ct2 + ct
fin = open ("input.txt", "r")
fout = open ("output.txt", "w")
a = [int(i) for i in fin.read().split()]
del a[0]
fout.write(str(merge_sort_count(a)))
