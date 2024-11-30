# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def drill(node):
            a=b=0
            if node.left:
                a = drill(node.left)
            if node.right:
                b = drill(node.right)
            return 1 + max(a,b)
        if root:
            return drill(root)
        else:
            return 0