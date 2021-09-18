dp = [-1 for i in range(1000)]

def factorial(n):
	if (n==0):
		return 1
	if (dp[n] != -1):
		return dp[n]
	dp[n] = n * factorial(n-1)
	return dp[n]

dp2 = [-1 for i in range(1000)]
dp2[0] = 1
for i in range(1, 1000):
	dp2[i] = dp2[i-1] * i

def factorial2(n):
	return dp2[n]

l = [500, 400, 200, 550, 100]
for n in l:
	print(factorial(n) == factorial2(n))