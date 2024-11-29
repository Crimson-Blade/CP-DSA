class Solution:
    def fib(self, n: int) -> int:
        
        dp = [-1] * (n + 1)
        def f(i):
            if i == 0:
                return 0
            if i == 1:
                return 1
            if dp[i] != -1:
                return dp[i]
            
            dp[i] = f(i-1) + f(i-2)
            
            return dp[i]
        
        return f(n)
        