import itertools
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        out = []
        subset = []
        l = len(nums)
        def recur(i):
            if i>=l:
                out.append(sorted(subset.copy()))
                return
            
            #include element
            subset.append(nums[i])
            recur(i+1)
            
            #excluse element
            subset.pop()
            recur(i+1)
            return
        recur(0)
        return list(k for k,_ in itertools.groupby(sorted(out)))