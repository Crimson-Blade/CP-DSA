class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        output = []
        
        def reccur(paran:str, left:int, right:int, n:int) -> None:
            if left + right == 2*n:
                output.append(paran)
                return
            if left < n:
                reccur(paran + '(',left + 1,right,n)
            if left > right:
                reccur(paran + ')',left,right+1,n)
        
        reccur("",0,0,n)
        return output