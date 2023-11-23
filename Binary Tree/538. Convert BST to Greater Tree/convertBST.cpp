/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
  we can use reverse inordered traversal to traverse the Binary serach tree, and then to update the node of value immediately.
  so, ex: [4,2,5,null,null,6] inorder -> [2,4,5,6] -> reverse [6,5,4,2] -> updated [6,11,15,17] and then we can update it to the node of value immediately
*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cur = 0;
        Inordered_traversal(root, cur); 
        return root;
    }
    void Inordered_traversal(TreeNode* root, int &cur) {
        if(root == NULL) return;
        Inordered_traversal(root->right, cur);
        // catch root->val 2, 4, 5, 6 ; 6, 5, 4, 2 -> 6, 11, 15, 17
        root->val += cur; // cur 0, root->val = 6, 11, 15, 17
        cur = root->val; // cur 6, 11
        Inordered_traversal(root->left, cur);
    }
};