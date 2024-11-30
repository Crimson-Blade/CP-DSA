# https://www.geeksforgeeks.org/maximum-path-sum-matrix/
def max_sum(mat):
  N = len(mat)
  M = len(mat[0])
  
  res = 0
  
  for i in range(1,N):
    for j in range(0,M):
      # all paths possible
      if j>0 and j < M-1:
        mat[i][j] += max(mat[i-1][j-1],mat[i-1][j],mat[i-1][j+1])
      # top right not possible
      elif j>0:
        mat[i][j] += max(mat[i-1][j-1],mat[i-1][j])
      # top left not possible
      elif j< M-1:
        mat[i][j] += max(mat[i-1][j],mat[i-1][j+1])
      
      res = max(res, mat[i][j])
  return res

  
# Driver program to check findMaxPath
N = 4
M = 6
mat = ([[10, 10, 2, 0, 20, 4],
        [1, 0, 0, 30, 2, 5],
        [0, 10, 4, 0, 2, 0],
        [1, 0, 2, 20, 0, 4]])

print(max_sum(mat))