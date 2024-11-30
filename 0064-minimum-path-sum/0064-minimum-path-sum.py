class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        for i in range (m):
            for j in range (n):
                if i==0 and j == 0: continue
                left = grid[i][j-1] if j>0 else float('inf')
                right = grid[i-1][j] if i>0 else float('inf')
                
                grid[i][j] += min(left,  right)
        return grid[m-1][n-1]