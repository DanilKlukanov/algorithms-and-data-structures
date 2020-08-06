fin = open("input.txt", "r")
fout = open("output.txt", "w")

n = int(fin.readline())
stairs = list(map(int, fin.read().split()))
stairs = [0] + stairs
dp = stairs.copy()

for i in range(1, n + 1):
    if i < 2:
        a_1 = dp[i - 1] + stairs[i]
        dp[i] = a_1
    elif i >= 2:
        a_1 = dp[i - 1] + stairs[i]
        a_2 = dp[i - 2] + stairs[i]
        dp[i] = max(a_1, a_2)
fout.write(str(dp[n]))