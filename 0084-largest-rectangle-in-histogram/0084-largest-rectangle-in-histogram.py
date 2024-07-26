class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stack to store pairs of (index, height)
        output = 0
        
        for i, h in enumerate(heights):
            start = i  # This will keep track of the start index for the current height
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                output = max(output, height * (i - index))
                start = index  # Update the start index
            stack.append((start, h))
        
        # Calculate the area for the remaining heights in the stack
        for i, h in stack:
            output = max(output, h * (len(heights) - i))
        
        return output