import random

fin = open("input.txt","r")
fout = open("output.txt","w")
n, k = fin.readline().split()
n, k = int(n), int(k)
nums = [int(num) for num in fin.readline().split()]
k -= 1

left = 0 
right = len(nums) - 1

less_left, less_right = 0, 0
equal_left, equal_right = 0, 0
more_left, more_right = 0, 0
not_find = True
not_exist = -123456789
while not_find:
    less, equal, more = [], [], []
    tmp = nums[left:right+1]
    q = random.choice(tmp)

    for x in tmp:
        if x < q:
            less.append(x)
        elif x == q:
            equal.append(x)
        elif x > q:
            more.append(x)

    tmp = []
    if len(less) > 0:
        tmp += less
    if len(equal) > 0:
        tmp += equal
    if len(more) > 0:
        tmp += more
    #=====================================================1
    if len(less) == 1:
        less_left, less_right = left, left
    elif len(less) > 1:
        less_left, less_right = left, left + len(less) - 1
    else:
        less_left, less_right = not_exist, not_exist
    #=====================================================2
    if len(more) == 1:
        more_left, more_right = right, right
    elif len(more) > 1:
        more_left, more_right = right - len(more) + 1, right
    else:
        more_left, more_right = not_exist, not_exist
    #=====================================================3
    if less_right == not_exist and more_left == not_exist:
        equal_left, equal_right = left, right
    elif less_right == not_exist and more_left != not_exist:
        equal_left, equal_right = left, more_left - 1
    elif less_right != not_exist and more_left == not_exist:
        equal_left, equal_right = less_right + 1, right
    else:
        equal_left, equal_right = less_right + 1, more_left - 1
    #===================================================end
    nums = nums[:left] + tmp + nums[right+1:]

    if k >= less_left and k <= less_right:
        left, right = less_left, less_right
    if k >= equal_left and k <= equal_right:
        stat = q
        not_find = False
    if k >= more_left and k <= more_right:
        left, right = more_left, more_right

fout.write(str(stat))