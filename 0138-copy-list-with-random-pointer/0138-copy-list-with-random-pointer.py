"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        ori = head
        if head:
            out = copy = Node(head.val,None,None)
        else:
            return head
        
        mydict = {ori:copy}
        
        while ori.next:
            copy.next = Node(ori.next.val,None,None)
            mydict[ori.next] = copy.next
            ori = ori.next
            copy = copy.next
        
        ori = head
        
        while ori:
            if ori.random:
                mydict[ori].random = mydict[ori.random]
            else:
                mydict[ori].random = None
            ori = ori.next
            
        return out
            
        
        
        
        