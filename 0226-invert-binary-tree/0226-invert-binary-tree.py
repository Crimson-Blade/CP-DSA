# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def insertNode(oldNode: Optional[TreeNode],newNode: Optional[TreeNode]):
            if oldNode.left:
                newNode.right = TreeNode(oldNode.left.val)
                insertNode(oldNode.left, newNode.right)
            if oldNode.right:
                newNode.left = TreeNode(oldNode.right.val)
                insertNode(oldNode.right,newNode.left)
                
        newRoot = None
        if root:
            newRoot = TreeNode(root.val)
            insertNode(root,newRoot)
        else:
            return root
        
        
            
        return newRoot
            
            