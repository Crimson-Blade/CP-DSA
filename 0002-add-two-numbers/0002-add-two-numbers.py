# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        
        p1,p2 = l1,l2
        t = p1.val+p2.val
        outhead = out = ListNode(t%10,None)
        carry = t//10 
        
        p1 = p1.next
        p2= p2.next
        
        
        while p1 and p2:
            t = p1.val+p2.val + carry
            carry = t//10 
            out.next = ListNode(t%10,None)
            p1 = p1.next
            p2= p2.next
            out= out.next
            
        
        while p1:
            t = p1.val + carry
            carry = t//10
            out.next = ListNode(t%10,None)
            out=out.next
            p1=p1.next
            
        while p2:
            t = p2.val + carry
            carry = t//10
            out.next = ListNode(t%10,None)
            out=out.next
            p2=p2.next
        
        if carry:
            out.next = ListNode(carry,None)
            
            
        
        return outhead
        
            
            