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

// list1 = 1 -> 2 -> 4
// list2 = 1 -> 3 -> 4
// ans = (-1)
// ans = -1 -> 1 (l1) if l1->val <= l2->val
//     = -1 -> 1 -> 1 (l2) if l1->val > l2->val
//       -1 -> 1 -> 1 -> 2, if l1->val <= l2->val (2 < 3)
//       -1 -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 if(l1 == NULL) ans->next = l2;       

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode (-1);
        ListNode* pilot = ans;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                pilot->next = list1;
                pilot = pilot->next;
                list1 = list1->next;
            } else {
                pilot->next = list2;
                pilot = pilot->next;
                list2 = list2->next;
            }
        }
        pilot->next = list2 == NULL ? list1 : list2;
        return ans->next;
    }
};