# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def rec_sumOfLeftLeaves(node, ans):
    if(node):
        if(node.left):
            if(not(node.left.left) and not(node.left.right)):
                ans[0] += node.left.val
            else:
                rec_sumOfLeftLeaves(node.left, ans)
        rec_sumOfLeftLeaves(node.right, ans)
    

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = [0]
        rec_sumOfLeftLeaves(root, ans)
        return ans[0]
        
        
