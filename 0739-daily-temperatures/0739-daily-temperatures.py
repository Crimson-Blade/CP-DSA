class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        n = len(temperatures)
        o = [0] * n
        i = 0
        while i < n:
            while stack and (temperatures[i] > stack[-1][0]):
                j = stack[-1][1]
                o[j] = i - j
                stack.pop()
            stack.append([temperatures[i],i])
            i+=1
        return o
        