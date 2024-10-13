class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        out = []
        subset = []
        def recur(i, s):
            # Final case
            if s == target:
                out.append(subset.copy())
                return
            
            # Overflow case
            if i >= len(candidates) or s > target:
                return
            
                
            # Include this number?
            subset.append(candidates[i])
            recur(i,s + candidates[i])
            
            # Don't inlcude this number
            subset.pop()
            recur(i+1,s)
            
                
        recur(0,0)
        
        return out
            