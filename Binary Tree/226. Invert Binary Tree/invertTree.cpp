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
    use level order traversal, and swap left and right node 
    ex:  2          2
        / \   ->   / \
       1   3      3   1
    
    time complexity O(n) 
    space complexity O(n) since in the worst case, the queue will contain all nodes in one level of the binary tree. 
                          For a full binary tree, the leaf level has n/2 + 1 leaves 
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> que;
        que.push(root); // que = {[4,2,7,...]}
        while(que.empty() == false) {
            TreeNode* node = que.front(); // node = [4,2,7,...]; [7..]
            que.pop(); // que = []; {[2..]}
            swap(node->left, node->right);
            // root = [4,7,2,6,9,1,3]; [4,7,2,9,6,1,3]
            // The node's pointer equal to root, so when we swap the node->left and node->right, the root's pointer also swap, too.
            if(node->left != NULL) 
                que.push(node->left); // que = {[7,6,9]}
            if(node->right != NULL) 
                que.push(node->right); // que = {[7,6,9], [2,1,3]}
        }
        return root;
    }
};