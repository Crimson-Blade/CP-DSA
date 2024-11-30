class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(1,m):
            for j in range(n):
                tl = matrix[i-1][j-1] if j>0 else float('inf')
                t = matrix[i-1][j]
                tr = matrix[i-1][j+1] if j<n-1 else float('inf')
                
                matrix[i][j] += min(tl,t,tr)
        out = min(matrix[m-1])
        return out
                
                