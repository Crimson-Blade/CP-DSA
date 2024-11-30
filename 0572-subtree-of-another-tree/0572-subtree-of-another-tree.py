# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        self.out = 0
        def explore(p,subRoot):
            if p:
                if p.val == subRoot.val and checkSubRoot(p,subRoot):
                   self.out +=1
                explore(p.right,subRoot)
                explore(p.left,subRoot)
                    
        def checkSubRoot(p,q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False

            return checkSubRoot(p.left,q.left) and checkSubRoot(p.right,q.right)
        
        explore(root,subRoot)
        
        return self.out > 0