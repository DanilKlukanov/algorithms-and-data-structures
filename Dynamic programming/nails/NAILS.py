fin = open("input.txt", "r")
fout = open("output.txt", "w")

n = int(fin.readline())
nails = list(map(int, fin.read().split()))

nails.sort()
dp = [0 for i in range(n)]

if n == 2:
    fout.write(str(nails[1] - nails[0]))
elif n > 2:
    dp[1] = nails[1] - nails[0]
    dp[2] = nails[2] - nails[0]

    for i in range(3, n):
        dp[i] = min(dp[i - 1], dp[i - 2]) + nails[i] - nails[i - 1]
print(dp[n-1])