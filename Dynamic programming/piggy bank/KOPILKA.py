fin = open("input.txt", "r")
fout = open("output.txt", "w")

value = list(map(int, (fin.readline().split())))
e, f, n = value[0], value[1], value[2]
par = []

for i in range(n):
    c, w = fin.readline().split()
    par.append((int(c), int(w)))

dp = [10**6 for i in range(f - e + 1)]
dp[0] = 0

for i in range(n):
    for j in range(1, f - e + 1):
        if j >= par[i][1]:
            dp[j] = min(dp[j], dp[j - par[i][1]] + par[i][0])

if dp[f - e] != 10**6:
    fout.write(str(dp[f - e]))
else:
    fout.write(str(-1)) 