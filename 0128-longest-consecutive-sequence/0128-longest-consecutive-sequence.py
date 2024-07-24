class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ms = set(nums)
        output = 0
        for num in nums:
            if num - 1 not in ms:
                seq = 0
                while (num + seq) in ms:
                    seq += 1
                output = max(seq,output)
        return output