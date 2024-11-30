class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[ 0 for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j]:
                    dp[i][j] = 0
                    continue
                top = dp[i-1][j] if i>0 else 0
                left = dp[i][j-1] if j>0 else 0
                dp[i][j] = 1 if i==0 and j ==0 else top + left
        return dp[m-1][n-1]