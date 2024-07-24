class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ms = set(nums)
        output = 0
        for num in nums:
            if num - 1 in ms:
                continue
            seq = 0
            while (num + seq) in ms:
                seq += 1
                if seq > output:
                    output = seq
        return output
            