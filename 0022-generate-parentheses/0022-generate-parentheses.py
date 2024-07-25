class Solution:
    output = []
    def reccur(self, paran:str, left:int, right:int, n:int) -> None:
        if left + right == 2*n:
            self.output.append(paran)
            return
        if left < n:
            self.reccur(paran + '(',left + 1,right,n)
        if left > right:
            self.reccur(paran + ')',left,right+1,n)
        
    def generateParenthesis(self, n: int) -> List[str]:
        self.output = []
        self.reccur("",0,0,n)
        return self.output