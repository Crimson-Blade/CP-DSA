class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        zipped = list(zip(position,speed))
        pos_time = list(sorted(zipped, key = lambda x:x[0]))
        stack = []
        
        for ele in pos_time[::-1]:
            if not stack:
                stack.append(ele)
            elif stack:
                time1 = (target - ele[0]) / ele[1]
                time2 = (target - stack[-1][0]) / stack[-1][1]
                stack.append(ele)
                if time1 <= time2:
                    stack.pop()
                    
        return len(stack)