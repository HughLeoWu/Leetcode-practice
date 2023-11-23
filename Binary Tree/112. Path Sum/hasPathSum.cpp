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
  bfs level order traversal, we store every level of node and diff value in the queue
  ex: [5,4,8,11,null,13,4,7,2,null,null,null,1] 
  (node, diff), (5, 17) -> (4, 13) -> (11, 2) -> -4
                                              -> 0 , if this node is also the end of tree, return true 
                        -> (8, 9) -> 
                                  -> (4, 4)
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        queue<pair<TreeNode*, int>> que;
        que.push({root, targetSum - root->val}); // (5, 17)
        while(que.empty() != true) {
            TreeNode* node = que.front().first; 
            int diff = que.front().second; // diff = 17; 13; 9; 2
            que.pop();
            if(node->left == NULL && node->right == NULL && diff == 0)
                return true;
            if(node->left != NULL)
                que.push({node->left, diff - node->left->val}); 
                // que {(4, 13)}; {(8, 9), (11, 2)}; {(11, 2), (13, -2)}; {(7, -5),(13, -2), (4, 5)}}
            if(node->right != NULL)
                que.push({node->right, diff - node->right->val}); 
                // que {(4, 13), (8, 9)}; {(11, 2), (13, -2), (4, 5)}; {, ..., (2, 0)}
        }
        return false;
    }
};