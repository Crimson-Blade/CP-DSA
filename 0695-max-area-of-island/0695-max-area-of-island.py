class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        islandID = 2
        areas = collections.defaultdict(int)
        m = len(grid)
        n = len(grid[0])
        
        
        def dfs(x,y,iD):
            # base case
            if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != 1:
                return
            
            grid[x][y] = iD
            areas[iD] += 1
            
            dfs(x+1,y,iD)
            dfs(x-1,y,iD)
            dfs(x,y+1,iD)
            dfs(x,y-1,iD)
            
            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i,j,islandID)
                    islandID += 1
        
        return max(areas.values(), default=0)
        