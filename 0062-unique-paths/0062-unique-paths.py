class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[ 0 for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                top = dp[i-1][j] if i>0 else 0
                left = dp[i][j-1] if j>0 else 0
                dp[i][j] = 1 if i==0 and j ==0 else top + left
        return dp[m-1][n-1]
                
        