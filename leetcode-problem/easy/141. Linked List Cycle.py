# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        if not head.next:
            return False
        front = head
        rear = head.next
        while rear != front:
            if not rear or not rear.next:
                return False

            front = front.next
            rear = rear.next.next
        return True