def bubble(a):
    f = 1
    while f == 1:
        f = 0
        for i in range(len(a)-1):
            if a[i]>a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                f = 1
    return a
a = [int(i) for i in input().split()]
a.pop(0)
print(*(bubble(a)))