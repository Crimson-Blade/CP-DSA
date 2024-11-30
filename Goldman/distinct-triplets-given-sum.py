# https://www.geeksforgeeks.org/unique-triplets-sum-given-value/

def distinct_tiplets(arr, target):
  arr = sorted(arr)
  n = len(arr)
  for i in range(n):
    