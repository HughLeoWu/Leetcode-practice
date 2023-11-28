# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
 list1 = 1 -> 2 -> 4
 list2 = 1 -> 3 -> 4
 ans = (-1)
 ans = -1 -> 1 (l1) if l1->val <= l2->val
     = -1 -> 1 -> 1 (l2) if l1->val > l2->val
       -1 -> 1 -> 1 -> 2, if l1->val <= l2->val (2 < 3)
       -1 -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 if(l1 == NULL) ans->next = l2;    
'''
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # list1 = [1,2,4], list2 = [1,3,4]
        if list1 is None:
            return list2
        elif list2 is None:
            return list1
        elif list1.val <= list2.val:
            # 1. mergeTwoLists([2,4], [1,3,4]); 3. mergeTwoLists([4], [3,4]); 5. mergeTwoLists([], [4])
            list1.next = self.mergeTwoLists(list1.next, list2)
            # list1.next = list2 [4]; list1.next = list2
            return list1 # list1 -> 4; list1 -> [3,4,4]
        else:
            # 2. mergeTwoLists([2,4], [3,4]); 4. mergeTwoLists([4], [4]); 
            list2.next = self.mergeTwoLists(list1, list2.next)
            # list2.next = list1 [4,4]
            return list2 # list2 -> [4,4]