# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = n2 = n3 = 0
        
        
        i=1
        ptr = l1
        while ptr:
            n1 += ptr.val * i
            i*=10
            ptr = ptr.next
        i=1
        ptr = l2     
        while ptr:
            n2 += ptr.val * i
            i*=10
            ptr = ptr.next
        
        n3 = n2 + n1
        n3str = str(n3)[::-1]
        out = ptr = ListNode(int(n3str[0]),None)
        
        n3str = n3str[1::]
        
        for c in n3str:
            ptr.next = ListNode(int(c),None)
            ptr = ptr.next
            
        return out
        