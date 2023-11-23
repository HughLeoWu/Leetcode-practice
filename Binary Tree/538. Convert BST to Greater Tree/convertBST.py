# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cur = 0
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.inordered_traversal(root)
        return root

    def inordered_traversal(self, root):
        if root == None:
            return
        self.inordered_traversal(root.right)
        root.val += self.cur
        self.cur = root.val
        self.inordered_traversal(root.left)
