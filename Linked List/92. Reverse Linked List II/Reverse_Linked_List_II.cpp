/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// First locate the node before the m-th node (pre) and the m-th node (cur). 
// Then movecur -> next to be after pre for n - m times. 
// ex:    
//   head 1 -> 2 -> 3 -> 4 -> 5  left = 2, right = 4 ->  head 1 -> 4 -> 3 -> 2 -> 5
//   d    0 -> 1 -> 2 -> 3 -> 4 -> 5 
//        p                      pre = [0,1,2,3,4,5]
//             p                 because left is 2, p should move forward left - 1 times 
//                               pre = [1,2,3,4,5]
//                  c            cur = pre->next              cur = [2,3,4,5]
//                               for loop right - left times, 
//                  t              tmp = pre->next              tmp = [2,3,4,5]; [3,2,4,5]
//                                 pre->next = cur->next,       pre = [1,3,4,5]; [1,4,5]
//                                 cur->next = cur->next->next, cur = [2,4,5];   [2,5]
//                                 because pre->next = cur->next, then tmp = pre->next, tmp = [2,4,5] (skip 3); [3,2,5] (skip 4)
//                                 pre->next->next = tmp,       pre = [1,3,2,4,5]; [1,4,3,2,5] 
//        
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) { // [1,2,3,4,5]
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy; 
        ListNode *cur;
        dummy->next = head; 
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        } 
        cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = pre->next; 
            pre->next = cur->next;      
            cur->next = cur->next->next;
            pre->next->next = temp;     
        }
        return dummy->next;
    }
};