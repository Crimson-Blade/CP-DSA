class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount+1)] for _ in range(n) ]
        
        # base 1
        for i in range(n):
            dp[i][0] = 1
        # base 2
        for k in range(1,amount+1):
            dp[0][k] = 1 if coins[0] <=k and k % coins[0] == 0 else 0
        
        #tabulation
        for i in range(1,n):
            for j in range(1,amount+1):
                not_take = dp[i-1][j]
                take = 0
                if j>= coins[i]:
                    take = dp[i][j-coins[i]]
                
                dp[i][j] = not_take + take
        
        
        return dp[n-1][amount]
        