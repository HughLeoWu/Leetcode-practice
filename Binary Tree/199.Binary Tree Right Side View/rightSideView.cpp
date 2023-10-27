/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * sol: 
   level ordered travsal
   bfs to get total node every level, and then to append the lastest one into answer
   so, [1,2,3,null,5,null,4] -> [1] -> [2,3] -> [5,4] answer = [1,3,4]
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) 
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size() != 0) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
                if(i == (size - 1))
                    ans.push_back(node->val);
            }
        }
        return ans;
    }
};