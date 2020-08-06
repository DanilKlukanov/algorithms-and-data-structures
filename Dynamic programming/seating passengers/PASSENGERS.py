fin = open("input.txt", "r")
fout = open("output.txt", "w")

n, k = list(map(int, fin.readline().split()))
M = 1000000007 
dp = [[0] * (n + 1) for i in range(3)]
dp[1][0] = 1

one = {}
for j in range(k):
    p = int(fin.readline())
    one[p] = 1

for i in range(1, n + 1):
    
    dp[0][i] = dp[0][i] + (dp[1][i - 1] + dp[2][i - 1]) % M
    dp[1][i] = dp[1][i] + (dp[0][i - 1]) % M
    dp[2][i] = dp[2][i] + (dp[1][i - 1]) % M

    if one.get(i) == 1:
        dp[1][i]=0
        dp[2][i]=0
fout.write(str((dp[0][n] + dp[1][n]) % M))