/*
    define the hashmap {prefixsum, node} to update every prefix sum of node, 
    if the prefix sum will be appear again, the remaining node also is updated via the same key 
    because the key will be update the new nodes if the key 
    ex: 
            1 -> 2 -> 3 -> -3 -> -2 -> 1 -> 2 -> 3]
    prefix  1    3    6     3    1     2    4    7 
    hashmap {[7] = [3], [4] = [2,3], [2] = [1,2,3], [6] = [3,-3,-2,1,2,3], 
             [3] = [-3,-2,1,2,3], [1] = [-2,1,2,3], [0] = [0,1,2,3,-3,-2,1,2,3]}
    Note: the key = [3] of the hashmap was updated by the second time, because the prefixsum is equal before one
          the key = [1] was also updated by the second time, and the reason was the same as key = 3 

    prefix  1    3    6     3    1     2    4    7 
                 |          [-3 -> -2 -> 1, ...]
                 |          |
                 - - - > - -|
    So, we can iteriate by using the prefixsum of hashmap and archieve our goal  
*/

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
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        prefixSumToNode[0] = front;

        // Calculate the prefix sum for each node and add to the hashmap
        // Duplicate prefix sum values will be replaced
        while (current != nullptr) {
            prefixSum += current->val;            // prefix = 0, 1, 3, 6, 3, 1, 2, 3 ,5
            prefixSumToNode[prefixSum] = current; // prefixnode {0 = [0]; 1 = [1]; 3 = [2]; 6 = [3]; 3 = [-3]
                                                  //             1 = [-2]; 2 = [1]; 3 = [3]; 5 = [3]
            current = current->next;              // curr 1, 2, 3, -3, -2, 1, 2, 3
        }
        // prefixSumToNode {[7] = [3], [4] = [2,3], [2] = [1,2,3], [6] = [3,-3,-2,1,2,3], 
        //                  [3] = [-3,-2,1,2,3], [1] = [-2,1,2,3], [0] = [0,1,2,3,-3,-2,1,2,3]}
        // Reset prefix sum and current
        prefixSum = 0;
        current = front;

        // Delete zero sum consecutive sequences 
        // by setting node before sequence to node after
        while (current != nullptr) {
            prefixSum += current->val;                        // prefix = 0, 1, 2, 4, 7
            current->next = prefixSumToNode[prefixSum]->next; // curr->next = 1; 1; 2; 3; null
            current = current->next;                          // curr = 1; 1; 2; 3; null
        }
        return front->next;
    }
};