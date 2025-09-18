import sys

while True:
    n = sys.stdin.readline()
    if not n:
        break
    n = int(n)
    if n == 0:
        print(1)
        continue
    elif n == 1:
        print(1)
        continue
    elif n == 2:
        print(3)
        continue
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 3
    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2] * 2
    print(dp[n])