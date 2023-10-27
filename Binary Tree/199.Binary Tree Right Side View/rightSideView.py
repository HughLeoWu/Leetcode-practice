"""
level ordered travsal, to append the lastest one into answer
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans, que = [], []
        if root == None:
            return ans
        que.append(root)
        while len(que) != 0:
            size = len(que)
            ans.append(que[-1].val)
            for i in range(size):
                node = que[0]
                que.pop(0)
                if node.left != None:
                    que.append(node.left)
                if node.right != None:
                    que.append(node.right)
        return ans

# root = [1,2,3,null,5,null,4]
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)
root.right.right = TreeNode(4)

# root1 = [1,null,3]
root1 = TreeNode(1)
root1.right = TreeNode(3)

RSV = Solution()
assert RSV.rightSideView(root) == [1,3,4], "ex1 failed"
assert RSV.rightSideView(root1) == [1,3], "ex2 failed"
print("all pass")

"""
Time: O(n) BFS to check all of node 
Space: O(k) to keep the queues  
"""
