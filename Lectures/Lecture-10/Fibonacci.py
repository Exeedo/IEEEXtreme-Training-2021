dp = [-1 for i in range(1000)]

def fibonacci(n):
	if (n<=1):
		return 1
	if (dp[n] != -1):
		return dp[n]
	
	dp[n] = fibonacci(n-1) + fibonacci(n-2) # Assume O(1)
	return dp[n]

for i in range(1000):
	print(i, fibonacci(i))