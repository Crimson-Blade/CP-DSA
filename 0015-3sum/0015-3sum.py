from collections import Counter

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        out = []
        nums.sort()
        for i,num in enumerate(nums):
            if i>0 and nums[i] == nums[i-1]:
                continue
            
            l,r = i + 1 , len(nums) - 1
            
            while l < r:
                total = num + nums[l] + nums[r]
                if total<0:
                    l=l+1
                elif total>0:
                    r = r-1
                else:
                    out.append([num,nums[l],nums[r]])
                    l = l+1
                    while nums[l] == nums[l-1] and l<r:
                        l=l+1          
        return out
                
            
        