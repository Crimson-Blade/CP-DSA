# Given a list, return if it can be sorted or not using the following rules.
# You can pick two indices (i and j) given that a[i] & a[j] is not zero. (bitwise and)

# l = [2,6,4]
# return True
# l = [1,0]
# return False

d = {
  "i": [[[2,6,4]],[[1,0]]],
  "o": [True, False]
}

from pysvt import test

@test(d)
def solution(arr):
  