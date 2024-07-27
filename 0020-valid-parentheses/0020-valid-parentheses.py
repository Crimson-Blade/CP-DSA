class Solution:
    def isValid(self, s: str) -> bool:
        closed_to_open = {
            ")":"(",
            "}":"{",
            "]":"[",
        }
        stack = []
        
        for c in s:
            if c in closed_to_open:
                if stack and stack[-1] == closed_to_open[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        
        return True if not stack else False
        