class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mydict = dict()
        for num in nums:
            if num not in mydict:
                mydict[num] = 1
            else:
                mydict[num] += 1
        sorted_keys = sorted(mydict, key=lambda k: mydict[k])
        
        return list(reversed(sorted_keys))[:k:]