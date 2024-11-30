# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        hashtable = set()
        ptr = head
        while ptr:
            if ptr in hashtable:
                return True
            hashtable.add(ptr)
            ptr = ptr.next
            
        return False
        
        