# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Finding len
        t = head
        l = 0
        
        while t:
            l += 1
            t = t.next
            
        t = head
        if l-n == 0:
            head = head.next
        else:
            for i in range(l-n-1):
                t = t.next

            if t.next:
                t.next = t.next.next
            else:
                head = None
        
        return head
            
        