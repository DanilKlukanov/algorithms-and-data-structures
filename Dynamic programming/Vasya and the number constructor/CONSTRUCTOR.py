fin = open("input.txt", "r")
fout = open("output.txt", "w")

n = int(fin.readline())
s = fin.readline()
dp = [[0] * (n + 1) for i in range(10)]

for i in range(n):
    if s[i] != '*':
        data = int(s[i])
        for j in range(10):
            if j != data:
                dp[j][i] = 0
        for g in range(10):
            if data != g:
                dp[g][i + 1] = max(dp[g][i + 1], dp[data][i] + data * g)
            else:
                dp[g][i + 1] = max(dp[g][i + 1], dp[data][i])
    else:
        for j in range(10):
            for q in range(10):
                if j != q:
                    dp[q][i + 1] = max(dp[q][i + 1], dp[j][i] + j * q)
                else:
                    dp[q][i + 1] = max(dp[q][i + 1], dp[j][i])    
for i in dp:
    print(dp)

fout.write(str(72 * (n - 1) - dp[0][n]))