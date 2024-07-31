from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(grid, i, j):
            # Base case for recursion to stop
            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1':
                return
            # Mark the cell as visited
            grid[i][j] = '0'
            # Explore all four directions
            dfs(grid, i+1, j)
            dfs(grid, i-1, j)
            dfs(grid, i, j+1)
            dfs(grid, i, j-1)
        
        m = len(grid)
        n = len(grid[0])
        
        out = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    out += 1
                    dfs(grid, i, j)
        return out
