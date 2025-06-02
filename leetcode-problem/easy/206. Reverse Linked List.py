# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        if not head.next:
            return head

        tail = None
        ptr = head
        front = head.next

        while front and ptr:
            ptr.next = tail

            tail = ptr
            ptr = front
            
            front = ptr.next
            ptr.next = tail
        return ptr