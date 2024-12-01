class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount+1)] for _ in range(n) ]
        
        
        def f(i,t):
            if dp[i][t] != -1:
                return dp[i][t]
            # base cases
            if t==0:
                return 1
            if i==0:
                dp[i][t] = 1 if coins[0] <=t and t % coins[0] == 0 else 0
                return dp[i][t]

            # recursion
            not_take = f(i-1,t)
            take = 0
            if t>= coins[i]:
                take = f(i,t-coins[i])
                
            dp[i][t] = not_take + take
            return dp[i][t]
        
        return f(len(coins)-1,amount)
        